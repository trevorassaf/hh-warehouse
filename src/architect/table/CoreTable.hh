<?hh // strict

type PrimaryKey = ImmSet<Column>;

type UniqueKey = ImmSet<Column>;
type UniqueKeySet = Set<UniqueKey>;
type ImmUniqueKeySet = ImmSet<UniqueKey>;

// Column map types
type IntegerColumnMap = Map<string, IntegerColumn>;
type ImmIntegerColumnMap = ImmMap<string, IntegerColumn>;

type StringColumnMap = Map<string, StringColumn>;
type ImmStringColumnMap = ImmMap<string, StringColumn>;

type BoolColumnMap = Map<string, BoolColumn>;
type ImmBoolColumnMap = ImmMap<string, BoolColumn>;

type DateColumnMap = Map<string, DateColumn>;
type ImmDateColumnMap = ImmMap<string, DateColumn>;

type TimestampColumnMap = Map<string, TimestampColumn>;
type ImmTimestampColumnMap = ImmMap<string, TimestampColumn>;

class CoreTable {

  private string $name;
  private PrimaryKey $primaryKey; 
  private UniqueKeySet $uniqueKeySet;
  private IntegerColumnMap $integerColumns;
  private StringColumnMap $stringColumns;
  private BoolColumnMap $boolColumns;
  private DateColumnMap $dateColumns;
  private TimestampColumnMap $timestampColumns;

  public function __construct(string $name) {
    $this->name = $name;
    $this->primaryKey = ImmSet{};
    $this->uniqueKeySet = Set{};

    // Column maps
    $this->integerColumns = Map{};
    $this->stringColumns = Map{};
    $this->boolColumns = Map{};
    $this->dateColumns = Map{};
    $this->timestampColumns = Map{};
  }
  
  public function bindIntegerColumn(IntegerColumn $column): this {
    $this->validateNewColumn($column);
    $this->integerColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindStringColumn(StringColumn $column): this {
    $this->validateNewColumn($column);
    $this->stringColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindBoolColumn(BoolColumn $column): this {
    $this->validateNewColumn($column);
    $this->boolColumns[$column->getName()] = $column;
    return $this;
  }

  public function bindDateColumn(DateColumn $column): this {
    $this->validateNewColumn($column);
    $this->dateColumns[$column->getName()] = $column;
    return $this;
  }
  
  public function bindTimestampColumn(TimestampColumn $column): this {
    $this->validateNewColumn($column);
    $this->timestampColumns[$column->getName()] = $column;
    return $this;
  }

  private function validateNewColumn(Column $column): void {
    // Check naming colisions
    invariant(
      $this->hasColumnName($column->getName()),
      "CoreTable::validateNewColumn() usage: column with name '{$column->getName()}' already exists!"
    ); 
  }

  public function hasColumnName(string $column_name): bool {
    return $this->integerColumns->containsKey($column_name) ||
      $this->stringColumns->containsKey($column_name) ||
      $this->boolColumns->containsKey($column_name) ||
      $this->dateColumns->containsKey($column_name) ||
      $this->timestampColumns->containsKey($column_name);
  }

  public function getColumn(string $name): Column {
    if ($this->integerColumns->containsKey($name)) {
      return $this->integerColumns[$name];
    } else if ($this->stringColumns->containsKey($name)) {
      return $this->stringColumns[$name];
    } else if ($this->boolColumns->containsKey($name)) {
      return $this->boolColumns[$name];
    } else if ($this->dateColumns->containsKey($name)) {
      return $this->dateColumns[$name];
    } else if ($this->timestampColumns->containsKey($name)) {
      return $this->timestampColumns[$name];
    }

    invariant(false, "CoreTable::getColumn() usage: column '{$name}' does not exist");
  }

  public function getIntegerColumns(): ImmIntegerColumnMap {
    return new ImmMap($this->integerColumns);
  }

  public function getStringColumns(): ImmStringColumnMap {
    return new ImmMap($this->stringColumns);
  }

  public function getBoolColumns(): ImmBoolColumnMap {
    return new ImmMap($this->boolColumns);
  }

  public function getDateColumns(): ImmDateColumnMap {
    return new ImmMap($this->dateColumns);
  }

  public function getTimestampColumns(): ImmTimestampColumnMap {
    return new ImmMap($this->timestampColumns);
  }

  public function getName(): string {
    return $this->name;
  }

  public function addUniqueKey(UniqueKey $unique_key): this {
    foreach ($unique_key as $column) {
      // Unique key columns must already exist in the table
      invariant(
        $this->hasColumnName($column->getName()),
        "CoreTable::addUniqueKey() usage: column with name '{$column->getName()}' does not exist!"
      );

      $existing_column = $this->getColumn($column->getName());
      invariant(
        $existing_column == $column,
        "CoreTable::addUniqueKey() usage: column '{$column->getName()}' does not match the existing column!'"
      );

      // Unique key columns can't be nullable
      invariant(
        !$column->isNullable(),
        "CoreTable::addUniqueKey() usage: column '{$column->getName()}' cannot be nullable in a unique key!"
      );
    }

    $this->uniqueKeySet[] = $unique_key;
    return $this;
  }

  public function getUniqueKeys(): ImmUniqueKeySet {
    return new ImmSet($this->uniqueKeySet);
  }
}
