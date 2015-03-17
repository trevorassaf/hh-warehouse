<?hh // strict

class StringDt extends Dt {
  
  public function __construct(
    int $first_length,
    bool $is_nullable=false
  ) {
    parent::__construct($is_nullable, $first_length);
  }

  public function getType(): DtType {
    return DtType::STRING;
  }

}
