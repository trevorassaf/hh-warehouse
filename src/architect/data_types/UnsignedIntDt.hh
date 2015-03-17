<?hh // strict

class UnsignedIntDt extends Dt {

  public function getType(): DtType {
    return DtType::UNSIGNED_INT;
  }
}
