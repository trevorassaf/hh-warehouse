<?hh // strict

type ColumnMap = Map<string, Column>;
type ImmColumnMap = ImmMap<string, Column>;

class ColumnSetParams {

  private ColumnMap $columns;

  public function __construct() {
    $this->columns = Map{};
  }

  public function addColumn(Column $column): this {
    invariant(
      $this->columns->containsKey($column->getName()),
      "ColumnSetBuilder::addColumn() usage: column '{$column->getName()}' already added!"
    );

    $this->columns[$column->getName()] = $column;
    return $this; 
  }

  public function getColumns(): ImmColumnMap {
    return $this->columns->toImmMap(); 
  }
}
