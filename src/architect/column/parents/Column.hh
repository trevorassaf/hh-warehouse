<?hh // strict

abstract class Column {

  public function __construct(
    private string $name,
    private bool $isNullable=true
  ) {}

  /**
   * verifyType()
   * @return true iff 'column' is the same underlying type.
   */
  abstract public function verifyType(Column $column): bool;

  public function getName(): string {
    return $this->name;
  }

  public function isNullable(): bool {
    return $this->isNullable;
  }
}
