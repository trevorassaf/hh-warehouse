<?hh // strict

class WhCoreTable extends CoreTable {
  
  public function __construct(string $name) {
    parent::__construct($name);
    $this->initWhColumns();
  }

  private function initWhColumns(): void {
  }
}
