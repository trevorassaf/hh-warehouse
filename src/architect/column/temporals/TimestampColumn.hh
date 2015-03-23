<?hh // strict

class TimestampColumn extends TypedColumn<string> {

  private ?DefaultTimestampMode $defaultMode;
  private ?TimestampUpdateMode $updateMode;

  public function __construct(
    string $name,
    bool $is_nullable=true,
    ?string $default_value=null,
    ?DefaultTimestampMode $default_mode=null,
    ?TimestampUpdateMode $update_mode=null
  ) {
    parent::__construct($name, $is_nullable, $default_value); 
    $this->defaultMode = $default_mode;
    $this->updateMode = $update_mode;
  }

  public function verifyType(Column $column): bool {
    return $column instanceof TimestampColumn;
  }
}
