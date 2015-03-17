<?hh // strict

abstract class Dt {

  protected ?int $firstLength;
  protected ?int $secondLength;

  protected bool $hasFirstLength;
  protected bool $hasSecondLength;

  public function __construct() {
    $this->hasFirstLength = false;
    $this->hasSecondLength = false;
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
