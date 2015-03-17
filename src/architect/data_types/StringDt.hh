<?hh // strict

class StringDt extends Dt {
  
  public function __construct(
    int $first_length
  ) {
    parent::__construct();
    $this->hasFirstLength = true;
    $this->firstLength = $first_length;
  }

  public function getType(): DtType {
    return DtType::STRING;
  }

}
