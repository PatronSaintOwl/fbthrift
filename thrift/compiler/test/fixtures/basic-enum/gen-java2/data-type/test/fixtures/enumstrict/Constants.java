/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.enumstrict;

import com.facebook.swift.codec.*;
import com.google.common.collect.*;
import java.util.*;

@SwiftGenerated
public final class Constants {
    private Constants() {}

    public static final test.fixtures.enumstrict.MyEnum K_ONE = test.fixtures.enumstrict.MyEnum.ONE;

    public static final Map<test.fixtures.enumstrict.MyEnum, String> ENUM_NAMES = ImmutableMap.<test.fixtures.enumstrict.MyEnum, String>builder()
        .put(test.fixtures.enumstrict.MyEnum.ONE, "one")
        .put(test.fixtures.enumstrict.MyEnum.TWO, "two")
        .build();
}
