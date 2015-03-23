<?hh // strict

abstract class TypedColumnBuilder<TType, TTypedColumn as TypedColumn<TType>> extends ColumnBuilder<TTypedColumn> {

  private ?TType $defaultValue;

  public function setDefaultValue(TType $default_value): this {
    $this->defaultValue = $default_value;
    return $this;
  }

  protected function buildColumnChild(
    string $name,
    bool $is_nullable
  ): TTypedColumn {
    return $this->buildTypedColumnChild(
      $name,
      $is_nullable,
      $this->defaultValue
    );
  }

  abstract protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?TType $default_value
  ): TTypedColumn;
}
