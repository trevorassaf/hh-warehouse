<?hh // strict

abstract class ScalarColumnBuilder<TType, TScalarColumn as ScalarColumn<TType>> extends TypedColumnBuilder<TType, TScalarColumn> {

  private ?int $length;

  public function setLength(int $length): this {
    $this->length = $length;
    return $this;
  }

  protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?TType $default_value
  ): TScalarColumn {
    invariant(
      $this->length !== null,
      "ScalarColumnBuilder::buildTypedColumnChild() usage: length must be non-null..."
    ); 
    
    return $this->buildScalarColumnChild(
      $name,
      $is_nullable,
      $default_value,
      $this->length
    );
  }  

  abstract protected function buildScalarColumnChild(
    string $name,
    bool $is_nullable,
    ?TType $default_value,
    int $length
  ): TScalarColumn;
}
