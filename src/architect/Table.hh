<?hh // strict

type ColumnMap = ImmMap<string, Column>;

class Table {

  public function __construct(
    private string $name,
    private ColumnMap $columnMap
  ) {}

  public function getName(): string {
    return $this->name;
  }

  public function getColumnMap(): ColumnMap {
    return $this->columnMap;
  }
}
