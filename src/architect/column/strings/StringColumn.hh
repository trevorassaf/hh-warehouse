<?hh // strict

class StringColumn extends ScalarColumn<string> {

  public function verifyType(Column $column): bool {
    return $column instanceof StringColumn;
  }
}
