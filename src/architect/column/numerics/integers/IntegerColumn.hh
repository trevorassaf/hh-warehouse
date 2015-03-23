<?hh // strict

class IntegerColumn extends ScalarColumn<int> {

  use NumericColumn<int>;

  protected ?DefaultIntegerMode $defaultMode;

  public function __construct(
    string $name,
    IntegerType $integer_type,
    bool $is_nullable=true,
    ?int $default_value=null,
    bool $is_unsigned=false,
    ?DefaultIntegerMode $default_mode=null
  ) {
    parent::__construct($name, (int) $integer_type, $is_nullable, $default_value);
    $this->isUnsigned = $is_unsigned;
    $this->defaultMode = $default_mode;
  }

  public function verifyType(Column $column): bool {
    if (!($column instanceof IntegerColumn)) {
      return false;
    } 

    return $column->isUnsigned() == $this->isUnsigned() &&
      $column->getLength() == $this->getLength();
  }
  
  public function hasDefaultMode(): bool {
    return $this->defaultMode !== null;
  }

  public function getDefaultMode(): DefaultIntegerMode {
    invariant(
      $this->defaultMode !== null,
      "IntegerColumn::getDefaultMode() usage: must first check if there is a default mode"
    ); 

    return $this->defaultMode;
  }
}
