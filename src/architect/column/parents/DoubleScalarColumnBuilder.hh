<?hh // strict

abstract class DoubleScalarColumnBuilder<TType, TDoubleScalarColumn as DoubleScalarColumn<TType>> extends ScalarColumnBuilder<TType, TDoubleScalarColumn> {

  private ?int $secondLength;

  public function setSecondLength(int $second_length): this {
    $this->secondLength = $second_length;
    return $this;
  }

  protected function buildScalarColumnChild(
    string $name,
    bool $is_nullable,
    ?TType $default_value,
    int $length
  ): TDoubleScalarColumn {
    invariant(
      $this->secondLength !== null,
      "DoubleScalarColumnBuilder::buildScalarColumnChild() usage: second-length must be non-null..."
    );  

    return $this->buildDoubleScalarColumnChild(
      $name,
      $is_nullable,
      $default_value,
      $length,
      $this->secondLength
    );
  }
  
  abstract protected function buildDoubleScalarColumnChild(
    string $name,
    bool $is_nullable,
    ?TType $default_value,
    int $length,
    int $seconod_length
  ): TDoubleScalarColumn;
}
