<?hh // strict

class ForeignKeyDt extends Dt {
  
  public function __construct(bool $is_nullable=false) {
    parent::__construct($is_nullable);  
  }

  public function getType(): DtType {
    return DtType::FOREIGN_KEY;
  }
}
