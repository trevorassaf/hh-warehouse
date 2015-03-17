<?hh // strict

class ForeignKeyDt extends Dt {

  public function getType(): DtType {
    return DtType::FOREIGN_KEY;
  }
}
