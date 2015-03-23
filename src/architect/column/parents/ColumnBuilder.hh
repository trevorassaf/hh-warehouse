<?hh // strict

abstract class ColumnBuilder<TColumn as Column> implements Builder<TColumn> {
  
  private ?string $name;
  private bool $isNullable;

  public function __construct() {
    $this->isNullable = false;
  }

  public function setName(string $name): this {
    $this->name = $name;
    return $this;
  }

  public function setIsNullable(bool $is_nullable): this {
    $this->isNullable = $is_nullable;
    return $this;
  }

  public function build(): TColumn {
    invariant(
      $this->name !== null,
      "ColumnBuilder::build() usage: name must be non-null..."
    );

    return $this->buildColumnChild($this->name, $this->isNullable);
  }

  abstract protected function buildColumnChild(
    string $name,
    bool $is_nullable
  ): TColumn;
}
