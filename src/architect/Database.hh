<?hh // strict

type ImmTableMap = ImmMap<string, Table>;

class Database {

  /**
   * Default delimitter for fields.
   */
  const FIELD_DELIMITER = "_";

  public function __construct(
      private string $name,
      private ImmTableMap $tableMap
  ) {}

  public function getName(): string {
    return $this->name;
  }

  public function getTableMap(): ImmTableMap {
    return $this->tableMap;
  }
}
