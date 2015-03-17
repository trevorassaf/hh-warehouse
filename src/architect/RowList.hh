<?hh // strict

type Row = ImmMap<string, mixed>;

final class RowList {
  
  private Vector<Row> $rowSeq;

  public function __construct(
      private ImmColumnMap $columnMap,
      private ImmUniqueColumnSet $uniqueColumnSet
  ) {
    $this->rowSeq = Vector{};
  }

  public function addRow(Row $row): this {
    $this->validateRowOrThrow($row);
    $this->rowSeq[] = $row;
    return $this;
  }

  private function validateRowOrThrow(Row $new_row): void {
    // Validate columns 
    foreach ($new_row as $row_key => $row_val) {
      if (!$this->columnMap->containsKey($row_key)) {
        throw new BadRowInsertionWithInvalidColumnException(
            $row_key,
            $this->columnMap
        );
      }
    }

    // Validate row uniqueness
    foreach ($this->uniqueColumnSet as $col_set) {
      // Skip this constrain b/c columns in 'unique-column-set' 
      // is not a subset of the columns in 'col-set'
      if (!$this->doesRowContainColumns($new_row, $col_set)) {
        continue;
      }
      
      // Ensure this row doesn't violate the uniqueness of an existing
      // row according to the current constraint (col-set) 
      foreach ($this->rowSeq as $existing_row) {

        // Skip row b/c it doesn't contain all of the constrain columns,
        // therefore, this constraint doesn't apply
        if (!$this->doesRowContainColumns($existing_row, $col_set)) {
          continue; 
        }

        // Check if 'new-row' collides with an existing row 
        $is_collision = true;

        foreach ($col_set as $col) {
          $existing_value = $existing_row[$col->getName()];
          $new_value = $new_row[$col->getName()];
          
          if ($existing_value != $new_value) {
            $is_collision = false; 
            break;
          }
        }

        if ($is_collision) {
          throw new BadRowInsertionWithUniquenessViolationException(
              $new_row,
              $existing_row,
              $col_set
          );
        }
      }
    }
  }

  private function doesRowContainColumns(Row $row, ImmSet<Column> $col_set): bool {
    if ($col_set->count() > $row->count()) {
      return false;
    }  

    foreach ($col_set as $col) {
      if (!$row->containsKey($col->getName())) {
        return false;
      }
    }

    return true;
  }
}
