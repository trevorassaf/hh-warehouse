<?hh // strict

class DateColumn extends TypedColumn<string> {

  private ?DefaultDateMode $defaultMode;
  private ?DateUpdateMode $updateMode;

  public function __construct(
    string $name,
    bool $is_nullable=true,
    ?string $default_value=null,
    ?DefaultDateMode $default_mode=null,
    ?DateUpdateMode $update_mode=null
  ) {
    parent::__construct($name, $is_nullable, $default_value); 
    $this->defaultMode = $default_mode;
    $this->updateMode = $update_mode;
  }

  public function verifyType(Column $column): bool {
    return $column instanceof DateColumn;
  }
}
