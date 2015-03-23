<?hh // strict

class DateColumnBuilder extends TypedColumnBuilder<string, DateColumn> {

  private ?DefaultDateMode $defaultMode;
  private ?DateUpdateMode $updateMode;

  public function setDefaultMode(DefaultDateMode $default_mode): this {
    $this->defaultMode = $default_mode;
    return $this;
  }

  public function setUpdateMode(DateUpdateMode $update_mode): this {
    $this->updateMode = $update_mode;
    return $this;
  }

  protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?string $default_value
  ): DateColumn {
    // 'Default-mode' and 'default-value' can't both be set
    invariant(
      $default_value === null || $this->defaultMode === null,
      "DateColumnBuilder::buildTypedColumnChild() usage: 'default-value' and 'default-mode' can't both be set"
    );

    return new DateColumn(
      $name,
      $is_nullable,
      $default_value,
      $this->defaultMode,
      $this->updateMode
    );
  }
}
