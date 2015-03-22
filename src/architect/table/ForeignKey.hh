<?hh // strict

class ForeignKey {

  public function __construct(
    private Column $localColumn,
    private CoreTable $foreignTable,
    private Column $foreignColumn
  ) {
    // Verify column compatibility
    invariant(
      $this->localColumn->verifyType($this->foreignColumn),
      "ForeignKey::__construct() usage: local-column '{$this->localColumn->getName()}' is incompatible with foreign-column '{$this->foreignColumn->getName()}' in a foreign key."
    );

    // Verify 'foreign-column' is column in 'foreign-table'
    invariant(
      $this->foreignTable->hasColumn($this->foreignColumn),
      "ForeignKey::__construct() usage: foreign-column is not a member of table '{$this->foreignTable->getName()}'"
    );

    // Verify 'foreign-column' is unique in 'foreign-table'
    invariant(
      $this->foreignTable->hasUniqueColumn($this->foreignColumn),
      "ForeignKey::__construct() usage: foreign-column '{$this->foreignColumn->getName()}' must be either a unique key or a primary key in foreign-table '{$this->foreignTable->getName()}'"
    );
  }

  public function getLocalColumn(): Column {
    return $this->localColumn;
  }

  public function getForeignTable(): CoreTable {
    return $this->foreignTable;
  }

  public function getForeignColumn(): Column {
    return $this->foreignColumn;
  }
}
