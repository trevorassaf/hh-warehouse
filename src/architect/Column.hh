<?hh // strict

final class Column {

  public function __construct(
    private string $name,
    private Dt $dataType
  ) {}

  public function getName(): string {
    return $this->name;
  }

  public function getDt(): Dt {
    return $this->dataType;
  }

}
