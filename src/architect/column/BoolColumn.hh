<?hh // strict 

class BoolColumn extends TypedColumn<bool> {

  public function verifyType(Column $column): bool {
    return $column instanceof BoolColumn;
  }
}
