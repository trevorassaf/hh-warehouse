<?hh // strict

abstract class ScalarColumn<T> extends TypedColumn<T> {

  private int $length;

  public function __construct(
    string $name,
    int $length,
    bool $is_nullable=true,
    ?T $default_value=null
  ) {
    parent::__construct($name, $is_nullable, $default_value);
    $this->length = $length;
  }

  public function getLength(): int {
    return $this->length;
  }
}
