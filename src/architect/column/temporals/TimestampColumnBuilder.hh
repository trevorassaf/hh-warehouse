<?hh // strict

class TimestampColumnBuilder extends TypedColumnBuilder<string, TimestampColumn> {

  private ?DefaultTimestampMode $defaultMode;
  private ?TimestampUpdateMode $updateMode;

  public function setDefaultMode(DefaultTimestampMode $default_mode): this {
    $this->defaultMode = $default_mode;
    return $this;
  }

  public function setUpdateMode(TimestampUpdateMode $update_mode): this {
    $this->updateMode = $update_mode;
    return $this;
  }

  protected function buildTypedColumnChild(
    string $name,
    bool $is_nullable,
    ?string $default_value
  ): TimestampColumn {
    // 'Default-mode' and 'default-value' can't both be set
    invariant(
      $default_value === null || $this->defaultMode === null,
      "TimestampColumnBuilder::buildTypedColumnChild() usage: 'default-value' and 'default-mode' can't both be set"
    );

    return new TimestampColumn(
      $name,
      $is_nullable,
      $default_value,
      $this->defaultMode,
      $this->updateMode
    );
  }
}
