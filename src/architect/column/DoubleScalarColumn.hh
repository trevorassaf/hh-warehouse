<?hh // strict

abstract class DoubleScalarColumn<T> extends ScalarColumn<T> {

  private int $secondLength;

  public function __construct(
    string $name,
    int $length,
    int $second_length,
    bool $is_nullable=true,
    ?T $default_value=null
  ) {
    parent::__construct($name, $length, $is_nullable, $default_value);
    $this->secondLength = $second_length;
  }

  public function getSecondLength(): int {
    return $this->secondLength;
  }

}
