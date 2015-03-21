<?hh // strict

type ImmColumnConstraints = ImmSet<ImmSet<Column>>;
type ImmForeignKeys = ImmSet<Column>;

class Table {

  public function __construct(
    private CoreTable $coreTable,
    private ImmForeignKeys $foreignKeys,
    private ImmColumnConstraints $columnConstraints
  ) {}

}
