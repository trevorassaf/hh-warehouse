<?hh // strict

class BoolColumnBuilder extends TypedColumnBuilder<bool, BoolColumn> {

  protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?bool $default_value
  ): BoolColumn {
    return new BoolColumn(
      $name,
      $is_nullable,
      $default_value
    );
  }
}
