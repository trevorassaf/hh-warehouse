<?hh // strict

abstract class IntegerColumn extends ScalarColumn<int> {

  use NumericColumn<int>;

  protected ?DefaultIntegerMode $defaultMode;
  
  public function hasDefaultMode(): bool {
    return $this->defaultMode !== null;
  }

  public function getDefaultMode(): DefaultIntegerMode {
    invariant(
      $this->defaultMode !== null,
      "IntegerColumn::getDefaultMode() usage: must first check if there is a default mode"
    ); 

    return $this->defaultMode;
  }
}
