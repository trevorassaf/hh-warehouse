<?hh // strict

class I16Column extends IntegerColumn {

  const NUM_BYTES = 2;

  public function __construct(
    string $name,
    bool $is_nullable=true,
    ?int $default_value=null,
    bool $is_unsigned=false,
    ?DefaultIntegerMode $default_mode=null
  ) {
    parent::__construct($name, self::NUM_BYTES, $is_nullable, $default_value);
    $this->isUnsigned = $is_unsigned;
    $this->defaultMode = $default_mode;
  }

  public function verifyType(Column $column): bool {
    if (!($column instanceof I32Column)) {
      return false;
    } 

    return $column->isUnsigned() == $this->isUnsigned();
    
  }
}
