<?hh // strict

type ColumnMap = Map<string, Column>;
type PrimaryKey = ImmSet<Column>;

class CoreTable {

  private ?string $name;
  private ?PrimaryKey $primaryKey; 
  private ColumnMap $columnMap;

  public function __construct() {
    $this->columnMap = Map{};
  }

  public function setName(string $name): this {
    invariant(
      $this->name === null,
      "CoreTable::setName() usage: already set name '{$this->name}' cant' set new name '{$name}'"
    );

    $this->name = $name;
    return $this;
  }

  public function getName(): string {
    invariant(
      $this->name !== null,
      "CoreTable::setName() usage: must check that name is non-null before calling this function"
    ); 

    return $this->name;
  }

  public function setPrimaryKey(PrimaryKey $primary_key): this {
    invariant(
      $this->primaryKey === null,
      "CoreTable::setPrimaryKey() usage: primary already set..."
    );

    $this->primaryKey = $primary_key;
    return $this;
  }

  public function getPrimaryKey(): PrimaryKey {
    invariant(
      $this->primaryKey !== null,
      "CoreTable::getPrimaryKey() usage: must first set primary key..."
    );

    return $this->primaryKey;
  }

  public function bindColumn(Column $column): this {
    invariant(
      $this->columnMap->containsKey($column->getName()),
      "CoreTable::bindColumn() usage: column with name '{$column->getName()}' already bound..."
    );

    $this->columnMap[$column->getName()] = $column;
    return $this;
  }

  public function getColumns(): ColumnMap {
    return $this->columnMap;
  }
}
