<?hh // strict 

interface AccessLayerBuilder {
  
  /**
   * createAccessLayerFile()
   * - Generate query for droping the database.
   */
  public function createAccessLayerFiles( string $database_name, string $path_to_dir): void;
}
