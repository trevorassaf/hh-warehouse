<?hh // strict

class PrimaryKeyDt extends Dt {

  public function __construct() {
    parent::__construct();
  }

  public function getType(): DtType {
    return DtType::PRIMARY_KEY;
  }
}
