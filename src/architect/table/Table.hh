<?hh // strict

interface Table {
  public function getName(): string;
  public function hasColumnName(string $column_name): bool;
  public function hasColumn(Column $column): bool; 
  public function getColumn(string $name): Column;
  public function getIntegerColumns(): ImmIntegerColumnMap;
  public function getStringColumns(): ImmStringColumnMap;
  public function getBoolColumns(): ImmBoolColumnMap;
  public function getDateColumns(): ImmDateColumnMap;
  public function getTimestampColumns(): ImmTimestampColumnMap;
  public function getUniqueKeys(): ImmSet<ColumnSet>;
  public function hasUniqueColumn(Column $column): bool;
  public function getPrimaryKey(): ColumnSet;
  public function hasPrimaryKey(): bool;
}
