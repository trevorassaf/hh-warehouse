<?hh // strict

class StringColumnBuilder extends ScalarColumnBuilder<string, StringColumn> {

  protected function buildScalarColumnChild(
    string $name,
    bool $is_nullable,
    ?string $default_value,
    int $length
  ): StringColumn {
    return new StringColumn(
      $name,
      $length,
      $is_nullable,
      $default_value
    );
  }

}
