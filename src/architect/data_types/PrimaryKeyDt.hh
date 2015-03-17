<?hh // strict

class PrimaryKeyDt extends Dt {

  public function getType(): DtType {
    return DtType::PRIMARY_KEY;
  }
}
