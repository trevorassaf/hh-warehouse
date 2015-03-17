<?hh // strict

type ColumnMap = Map<string, Column>;
type UniqueColumnSet = Set<ImmSet<Column>>;

class TableBuilder implements Builder<Table> {

  private ?string $name;
  private ColumnMap $columnMap;
  private UniqueColumnSet $uniqueColumnSet;
  private bool $isReadOnly;

  public function __construct() {
    $this->name = null;
    $this->columnMap = Map{};
    $this->uniqueColumnSet = Set{};
    $this->isReadOnly = false;
  }

  public function addCompositeKey(ImmSet<Column> $col_set): this {
    $this->uniqueColumnSet[] = $col_set;
    return $this;
  }

  public function addUniqueKey(Column $col): this {
    $this->uniqueColumnSet[] = ImmSet{$col};
    return $this;
  }


  public function build(): Table {
    assert($this->name !== null);

    return new Table(
      $this->name,
      new ImmMap($this->columnMap),
      new ImmSet($this->uniqueColumnSet),
      $this->isReadOnly 
    );        
  } 

  public function getName(): ?string {
    return $this->name;
  }

  public function getColumnMap(): ColumnMap {
    return $this->columnMap;
  }

  public function getUniqueColumnSet(): UniqueColumnSet {
    return $this->uniqueColumnSet;
  }

  public function isReadOnly(): bool {
    return $this->isReadOnly;
  }
}
