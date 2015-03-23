<?hh // strict

abstract class TypedColumn<T> extends Column {

  private ?T $defaultValue;

  public function __construct(
    string $name,
    bool $is_nullable=true,
    ?T $default_value=null
  ) {
    parent::__construct($name, $is_nullable);
    $this->defaultValue = $default_value;
  }
  
  public function hasDefaultValue(): bool {
    return $this->defaultValue !== null;
  }

  public function getDefaultValue(): T {
    invariant(
      $this->defaultValue !== null,
      "Column::getDefaultValue() usage: must ensure default value exists first!"
    );

    return $this->defaultValue;
  }
}
