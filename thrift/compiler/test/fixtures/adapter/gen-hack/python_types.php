<?hh
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift struct:-
 * Adapter
 */
<<\ThriftTypeInfo(shape('uri' => 'facebook.com/thrift/annotation/python/Adapter'))>>
class facebook_thrift_annotation_python_Adapter implements \IThriftSyncStruct, \IThriftShapishSyncStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'name',
      'type' => \TType::STRING,
    ),
    2 => shape(
      'var' => 'typeHint',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'name' => 1,
    'typeHint' => 2,
  ];

  const type TConstructorShape = shape(
    ?'name' => ?string,
    ?'typeHint' => ?string,
  );

  const type TShape = shape(
    'name' => string,
    'typeHint' => string,
  );
  const int STRUCTURAL_ID = 8465306397732997722;
  /**
   * Original thrift field:-
   * 1: string name
   */
  public string $name;
  /**
   * Original thrift field:-
   * 2: string typeHint
   */
  public string $typeHint;

  public function __construct(?string $name = null, ?string $typeHint = null  )[] {
    $this->name = $name ?? '';
    $this->typeHint = $typeHint ?? '';
  }

  public static function withDefaultValues()[]: this {
    return new static();
  }

  public static function fromShape(self::TConstructorShape $shape)[]: this {
    return new static(
      Shapes::idx($shape, 'name'),
      Shapes::idx($shape, 'typeHint'),
    );
  }

  public function getName()[]: string {
    return 'Adapter';
  }

  public static function getStructMetadata()[]: \tmeta_ThriftStruct {
    return tmeta_ThriftStruct::fromShape(
      shape(
        "name" => "python.Adapter",
        "fields" => vec[
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 1,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "name",
            )
          ),
          tmeta_ThriftField::fromShape(
            shape(
              "id" => 2,
              "type" => tmeta_ThriftType::fromShape(
                shape(
                  "t_primitive" => tmeta_ThriftPrimitiveType::THRIFT_STRING_TYPE,
                )
              ),
              "name" => "typeHint",
            )
          ),
        ],
        "is_union" => false,
      )
    );
  }

  public static function getAllStructuredAnnotations()[]: \TStructAnnotations {
    return shape(
      'struct' => dict[
        'facebook_thrift_annotation_Field' => facebook_thrift_annotation_Field::fromShape(
          shape(
          )
        ),
      ],
      'fields' => dict[
      ],
    );
  }

  public static function __fromShape(self::TShape $shape)[]: this {
    return new static(
      $shape['name'],
      $shape['typeHint'],
    );
  }

  public function __toShape()[]: self::TShape {
    return shape(
      'name' => $this->name,
      'typeHint' => $this->typeHint,
    );
  }
  public function getInstanceKey()[write_props]: string {
    return \TCompactSerializer::serialize($this);
  }

  public function readFromJson(string $jsonText): void {
    $parsed = json_decode($jsonText, true);

    if ($parsed === null || !($parsed is KeyedContainer<_, _>)) {
      throw new \TProtocolException("Cannot parse the given json string.");
    }

    if (idx($parsed, 'name') !== null) {
      $this->name = /* HH_FIXME[4110] */ $parsed['name'];
    }    
    if (idx($parsed, 'typeHint') !== null) {
      $this->typeHint = /* HH_FIXME[4110] */ $parsed['typeHint'];
    }    
  }

}

