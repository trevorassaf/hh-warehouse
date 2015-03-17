<?hh // strict

class BadRowInsertionWithUniquenessViolationException extends Exception {
  
  public function __construct(
    private Row $newRow,
    private Row $existingRow,
    private ImmSet<Column> $uniqueColumns
  ) {
    parent::__construct();
  }

  public function __toString(): string {
    return "Bad row insertion: uniqueness violoation: new row: {$this->newRow},
      existing row: {$this->existingRow}, constraint: {$this->uniqueColumns}";
  }
}

