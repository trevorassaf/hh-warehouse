<?hh // strict

abstract class OptionalScalarColumn<T> extends TypedColumn<T> {
  
  private ?int $length;

  public function __construct(
    string $name,
    bool $is_nullable,
    ?T $default_value,
    ?int $length
  ) {
    parent::__construct($name, $is_nullable, $default_value);
    $this->length = $length;
  }

  public function hasLength(): bool {
    return $this->length !== null; 
  }

  public function getLength(): int {
    invariant(
      $this->length !== null,
      "OptionalScalarColumn::getLength() usage: must check for null length before calling!"
    );

    return $this->length;
  }
}
