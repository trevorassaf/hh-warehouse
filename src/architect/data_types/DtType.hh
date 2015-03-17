<?hh // strict

enum DtType: int {
  INT = 0x00;
  UNSIGNED_INT = 0x01;
  PRIMARY_KEY = 0x02;
  BOOL = 0x03;
  STRING = 0x04;
  FOREIGN_KEY = 0x05;
  DATE = 0x06;
  TIMESTAMP = 0x07;
  FLOAT = 0x08;
}
