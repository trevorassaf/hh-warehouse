<?hh // strict

class IntegerColumnBuilder extends TypedColumnBuilder<int, IntegerColumn> {

  private bool $isUnsigned;
  private ?IntegerType $type;
  private ?DefaultIntegerMode $defaultMode;

  public function __construct() {
    parent::__construct();
    $this->isUnsigned = false;
  }

  public function setIsUnsigned(bool $is_unsigned): this {
    $this->isUnsigned = $is_unsigned;
    return $this;
  }

  public function setType(IntegerType $type): this {
    $this->type = $type;
    return $this;
  }

  public function setDefaultIntegerMode(DefaultIntegerMode $default_mode): this {
    $this->defaultMode = $default_mode;
    return $this;
  }

  protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?int $default_value
  ): IntegerColumn {
    // 'type' can't be null
    invariant(
      $this->type !== null,
      "IntegerColumnBuilder::buildScalarColumnChild() usage: 'type' must be non-null..."
    );

    // Verify that 'default-value' and 'default-mode' aren't both set
    invariant(
      $default_value === null || $this->defaultMode === null,
      "IntegerColumnBuilder::buildScalarColumnChild() usage: conflicting default-value and default-mode values. Both can't be set."
    );

    return new IntegerColumn(
      $name,
      $this->type,
      $is_nullable,
      $default_value,
      $this->isUnsigned,
      $this->defaultMode
    );
  }
}
