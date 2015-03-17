<?hh // strict

class TimestampDt extends Dt {

  public function getType(): DtType {
    return DtType::TIMESTAMP;
  }
}
