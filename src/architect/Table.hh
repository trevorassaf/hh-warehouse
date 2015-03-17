<?hh // strict

type ImmColumnMap = ImmMap<string, Column>;
type ImmUniqueColumnSet = ImmSet<ImmSet<Column>>;

/**
 * Table
 * - The table specification of this table is immutable, however,
 *   the row list is mutable.
 */
class Table {

  private RowList $rowList;

  public function __construct(
      private string $name,
      private ImmColumnMap $columnMap,
      private ImmUniqueColumnSet $uniqueColumnSet,
      private bool $isReadOnly
  ) {
    $this->rowList = new RowList(
        $this->columnMap,
        $this->uniqueColumnSet
    ); 
  }

  public function getName(): string {
    return $this->name;
  }

  public function getColumnMap(): ImmColumnMap {
    return $this->columnMap;
  }

  public function getUniqueColumnSet(): ImmUniqueColumnSet {
    return $this->uniqueColumnSet;
  }

  public function getRowList(): RowList {
    return $this->rowList; 
  }

  public function isReadOnly(): bool {
    return $this->isReadOnly;
  }
}
