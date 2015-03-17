<?hh // strict

abstract class Dt {

  private bool $hasFirstLength;
  private bool $hasSecondLength;

  public function __construct(
    private bool $isNullable=false,
    private ?int $firstLength=null,
    private ?int $secondLength=null
  ) {
    $this->hasFirstLength = $this->firstLength !== null;
    $this->hasSecondLength = $this->secondLength !== null;
  }

  abstract public function getType(): DtType;

  /**
   * hasFirstLength()
   * @return true iff first length has been set
   */
  public function hasFirstLength(): bool {
    return $this->hasFirstLength; 
  }
  
  /**
   * getFirstLength()
   * @return length of this data-type, if it has one 
   */
  public function getFirstLength(): int {
    invariant($this->firstLength !== null, "First length is not set!");
    return $this->firstLength;
  }
  
  /**
   * hasSecondLength()
   * @return true iff this DataType has a length
   */
  public function hasSecondLength(): bool {
    return $this->hasSecondLength;
  }
  
  /**
   * getSecondLength()
   * @return length of this data-type, if it has one 
   */
  public function getSecondLength(): int {
    invariant($this->secondLength !== null, "Second length is not set!");
    return $this->secondLength;
  }

}
