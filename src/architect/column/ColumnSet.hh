<?hh // strict

class ColumnSet {

  private ImmColumnMap $columns;

  public function __construct(
    ColumnSetParams $column_set_params
  ) {
    $this->columns = $column_set_params->getColumns();
  }

  public function getColumns(): ImmColumnMap {
    return $this->columns;
  }
}
