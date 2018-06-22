<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

namespace test\fixtures\jsenum;

/**
 * Original thrift enum:-
 * MyThriftEnum
 */
<<ApiEnum, JSEnum>>
enum MyThriftEnum : int {
  foo = 1;
  bar = 2;
  baz = 3;
}
type MyThriftEnumType = MyThriftEnum;

/**
 * Original thrift struct:-
 * MyThriftStruct
 */
class MyThriftStruct implements \IThriftStruct {
  use \ThriftSerializationTrait;

  public static dict<int, dict<string, mixed>> $_TSPEC = dict[
    1 => dict[
      'var' => 'foo',
      'type' => \TType::STRING,
      ],
    2 => dict[
      'var' => 'bar',
      'type' => \TType::STRING,
      ],
    3 => dict[
      'var' => 'baz',
      'type' => \TType::STRING,
      ],
    ];
  public static Map<string, int> $_TFIELDMAP = Map {
    'foo' => 1,
    'bar' => 2,
    'baz' => 3,
  };
  const int STRUCTURAL_ID = 6671455975178405100;
  /**
   * Original thrift field:-
   * 1: string foo
   */
  public string $foo;
  /**
   * Original thrift field:-
   * 2: string bar
   */
  public string $bar;
  /**
   * Original thrift field:-
   * 3: string baz
   */
  public string $baz;

  public function __construct(?string $foo = null, ?string $bar = null, ?string $baz = null  ) {
    if ($foo === null) {
      $this->foo = '';
    } else {
      $this->foo = $foo;
    }
    if ($bar === null) {
      $this->bar = '';
    } else {
      $this->bar = $bar;
    }
    if ($baz === null) {
      $this->baz = '';
    } else {
      $this->baz = $baz;
    }
  }

  public function getName(): string {
    return 'MyThriftStruct';
  }

}

/**
 * Original thrift struct:-
 * MySecondThriftStruct
 */
class MySecondThriftStruct implements \IThriftStruct {
  use \ThriftSerializationTrait;

  public static dict<int, dict<string, mixed>> $_TSPEC = dict[
    1 => dict[
      'var' => 'foo',
      'type' => \TType::I32,
      'enum' => '\test\fixtures\jsenum\MyThriftEnum',
      ],
    2 => dict[
      'var' => 'bar',
      'type' => \TType::STRUCT,
      'class' => '\test\fixtures\jsenum\MyThriftStruct',
      ],
    3 => dict[
      'var' => 'baz',
      'type' => \TType::I64,
      ],
    ];
  public static Map<string, int> $_TFIELDMAP = Map {
    'foo' => 1,
    'bar' => 2,
    'baz' => 3,
  };
  const int STRUCTURAL_ID = 2800971917864580212;
  /**
   * Original thrift field:-
   * 1: enum module1.MyThriftEnum foo
   */
  public ?\test\fixtures\jsenum\MyThriftEnum $foo;
  /**
   * Original thrift field:-
   * 2: struct module1.MyThriftStruct bar
   */
  public ?\test\fixtures\jsenum\MyThriftStruct $bar;
  /**
   * Original thrift field:-
   * 3: i64 baz
   */
  public int $baz;

  public function __construct(?\test\fixtures\jsenum\MyThriftEnum $foo = null, ?\test\fixtures\jsenum\MyThriftStruct $bar = null, ?int $baz = null  ) {
    $this->foo = $foo;
    $this->bar = $bar;
    if ($baz === null) {
      $this->baz = 0;
    } else {
      $this->baz = $baz;
    }
  }

  public function getName(): string {
    return 'MySecondThriftStruct';
  }

}

