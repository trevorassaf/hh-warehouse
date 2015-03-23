<?hh // strict

class ColumnSet {

  private ImmSet<Column> $columns;

  public function __construct(
    ColumnSetParams $column_set_params
  ) {
    $this->columns = $column_set_params->getColumns();
  }

  public function getColumns(): ImmSet<Column> {
    return $this->columns;
  }
}
