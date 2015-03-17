<?hh // strict

class BadRowInsertionWithInvalidColumnException extends Exception {
  
  public function __construct(
    private string $rowKey,
    private ImmColumnMap $columnMap
  ) {
    parent::__construct();
  }

  public function __toString(): string {
    return "Bad row insertion: row column, {$this->rowKey}, 
        does not match any in column-map: {$this->columnMap}";
  }
}
