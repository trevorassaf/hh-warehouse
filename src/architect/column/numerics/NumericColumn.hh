<?hh // strict

trait NumericColumn<T> {

  require extends TypedColumn<T>;

  protected bool $isUnsigned; 

  public function isUnsigned(): bool {
    return $this->isUnsigned;
  }
}
