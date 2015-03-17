<?hh // strict

final class Column {

  public function __construct(
    private string $name
  ) {}

  public function getName(): string {
    return $this->name;
  }
}
