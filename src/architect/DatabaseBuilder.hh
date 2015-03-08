<?hh // strict

type TableMap = Map<string, Table>;

class DatabaseBuilder implements Builder<Database> {

  private ?string $name;
  private TableMap $tableMap;

  public function __construct() {
    $this->name = null;
    $this->tableMap = Map{};
  }
  
  public function build(): Database {
    // Fail b/c name can't be null
    assert($this->name !== null); 

    return new Database($this->name, new ImmMap($this->tableMap));
  } 
}
