<?hh // strict

// Column map types
type IntegerColumnMap = Map<string, IntegerColumn>;
type ImmIntegerColumnMap = ImmMap<string, IntegerColumn>;

type StringColumnMap = Map<string, StringColumn>;
type ImmStringColumnMap = ImmMap<string, StringColumn>;

type BoolColumnMap = Map<string, BoolColumn>;
type ImmBoolColumnMap = ImmMap<string, BoolColumn>;

type DateColumnMap = Map<string, DateColumn>;
type ImmDateColumnMap = ImmMap<string, DateColumn>;

type TimestampColumnMap = Map<string, TimestampColumn>;
type ImmTimestampColumnMap = ImmMap<string, TimestampColumn>;

class CoreTable implements Table {

  // Metadata
  private string $name;

  // Constraints 
  private ?ColumnSet $primaryKey;
  private Set<ColumnSet> $uniqueKeySet;

  // Data columns 
  private ?IntegerColumnMap $integerColumns;
  private ?StringColumnMap $stringColumns;
  private ?BoolColumnMap $boolColumns;
  private ?DateColumnMap $dateColumns;
  private ?TimestampColumnMap $timestampColumns;

  public function __construct(string $name) {
    $this->name = $name;
    $this->uniqueKeySet = Set{};
  }
  
  public function bindIntegerColumn(IntegerColumn $column): this {
    $this->validateNewColumn($column);
    if ($this->integerColumns === null) {
      $this->integerColumns = Map{};
    }
    $this->integerColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindStringColumn(StringColumn $column): this {
    $this->validateNewColumn($column);
    if ($this->stringColumns === null) {
      $this->stringColumns = Map{};
    }
    $this->stringColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindBoolColumn(BoolColumn $column): this {
    $this->validateNewColumn($column);
    if ($this->boolColumns === null) {
      $this->boolColumns = Map{};
    }
    $this->boolColumns[$column->getName()] = $column;
    return $this;
  }

  public function bindDateColumn(DateColumn $column): this {
    $this->validateNewColumn($column);
    if ($this->dateColumns === null) {
      $this->dateColumns = Map{};
    }
    $this->dateColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindTimestampColumn(TimestampColumn $column): this {
    $this->validateNewColumn($column);
    if ($this->timestampColumns === null) {
      $this->timestampColumns = Map{};
    }
    $this->timestampColumns[$column->getName()] = $column;
    return $this;
  }

  private function validateNewColumn(Column $column): void {
    // Check naming colisions
    invariant(
      $this->hasColumnName($column->getName()),
      "CoreTable::validateNewColumn() usage: column with name '{$column->getName()}' already exists!"
    ); 
  }

  public function hasColumnName(string $column_name): bool {
    return ($this->integerColumns !== null && $this->integerColumns->containsKey($column_name)) ||
      ($this->stringColumns !== null && $this->stringColumns->containsKey($column_name)) ||
      ($this->boolColumns !== null && $this->boolColumns->containsKey($column_name)) ||
      ($this->dateColumns !== null && $this->dateColumns->containsKey($column_name)) ||
      ($this->timestampColumns !== null && $this->timestampColumns->containsKey($column_name));
  }

  public function getColumn(string $name): Column {
    $integer_columns = $this->integerColumns;
    if ($integer_columns !== null && $integer_columns->containsKey($name)) {
      return $integer_columns[$name];
    } 

    $string_columns = $this->stringColumns;
    if ($string_columns !== null && $string_columns->containsKey($name)) {
      return $string_columns[$name];
    } 

    $bool_columns = $this->boolColumns;
    if ($bool_columns !== null && $bool_columns->containsKey($name)) {
      return $bool_columns[$name];
    } 

    $date_columns = $this->dateColumns;
    if ($date_columns !== null && $date_columns->containsKey($name)) {
      return $date_columns[$name];
    } 

    $timestamp_columns = $this->timestampColumns;
    if ($timestamp_columns !== null && $timestamp_columns->containsKey($name)) {
      return $timestamp_columns[$name];
    }

    invariant(false, "CoreTable::getColumn() usage: column '{$name}' does not exist");
  }

  public function hasColumn(Column $column): bool {
    return $this->hasColumnName($column->getName()) 
        && $this->getColumn($column->getName()) == $column;
  }

  public function getIntegerColumns(): ImmIntegerColumnMap {
    return new ImmMap($this->integerColumns);
  }

  public function getStringColumns(): ImmStringColumnMap {
    return new ImmMap($this->stringColumns);
  }

  public function getBoolColumns(): ImmBoolColumnMap {
    return new ImmMap($this->boolColumns);
  }

  public function getDateColumns(): ImmDateColumnMap {
    return new ImmMap($this->dateColumns);
  }

  public function getTimestampColumns(): ImmTimestampColumnMap {
    return new ImmMap($this->timestampColumns);
  }

  public function getName(): string {
    return $this->name;
  }

  public function addUniqueKey(ColumnSet $unique_key): this {
    $this->validateUniquenessConstraint($unique_key);
    $this->uniqueKeySet[] = $unique_key;
    return $this;
  }

  private function validateUniquenessConstraint(ColumnSet $column_set): void {
    foreach ($column_set->getColumns() as $column) {
      // Unique key columns must already exist in the table
      invariant(
        $this->hasColumnName($column->getName()),
        "CoreTable::addUniqueKey() usage: column with name '{$column->getName()}' does not exist!"
      );

      $existing_column = $this->getColumn($column->getName());
      invariant(
        $existing_column == $column,
        "CoreTable::addUniqueKey() usage: column '{$column->getName()}' does not match the existing column!'"
      );

      // Unique key columns can't be nullable
      invariant(
        !$column->isNullable(),
        "CoreTable::addUniqueKey() usage: column '{$column->getName()}' cannot be nullable in a unique key!"
      );
    }
  }

  public function getUniqueKeys(): ImmSet<ColumnSet> {
    return $this->uniqueKeySet->toImmSet();
  }

  public function setPrimaryKey(ColumnSet $primary_key): this {
    invariant(
      $primary_key === null,
      "CoreTable::setPrimaryKey() usage: primary key already set!"
    );
    
    $this->validateUniquenessConstraint($primary_key);
    $this->primaryKey = $primary_key;
    return $this;
  }

  public function getPrimaryKey(): ColumnSet {
    invariant(
      $this->primaryKey !== null,
      "CoreTable::getPrimaryKey() usage: primary key does not exists!"
    );

    return $this->primaryKey;
  }

  public function hasPrimaryKey(): bool {
    return $this->primaryKey !== null;
  }
  
  public function hasUniqueColumn(Column $column): bool {
    // Check primary key
    $primary_key = $this->primaryKey;
    if ($primary_key !== null && $primary_key->getColumns()->count() == 1) {
      $primary_column = $primary_key->getColumns()->getIterator()->current();
      if ($primary_column == $column) {
        return true;
      }
    }

    // Check unique keys
    foreach ($this->uniqueKeySet as $unique_key) {
      if ($unique_key->getColumns()->count() == 1) {
        $unique_column = $unique_key->getColumns()->getIterator()->current();
        if ($unique_column == $column) {
          return true;
        }
      }
    }    
    
    return false;
  }
}
