/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.sink;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct("InitialException")
public final class InitialException extends org.apache.thrift.TBaseException implements com.facebook.thrift.payload.ThriftSerializable {
    private static final long serialVersionUID = 1L;


    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();

    private static final TStruct STRUCT_DESC = new TStruct("InitialException");
    private final String reason;
    public static final int _REASON = 1;
    private static final TField REASON_FIELD_DESC = new TField("reason", TType.STRING, (short)1);

    @ThriftConstructor
    public InitialException(
        @com.facebook.swift.codec.ThriftField(value=1, name="reason", requiredness=Requiredness.NONE) final String reason
    ) {
        this.reason = reason;
    }
    
    @ThriftConstructor
    protected InitialException() {
      this.reason = null;
    }
    
    public static class Builder {
    
        private String reason = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="reason", requiredness=Requiredness.NONE)
        public Builder setReason(String reason) {
            this.reason = reason;
            return this;
        }
    
        public String getReason() { return reason; }
    
        public Builder() { }
        public Builder(InitialException other) {
            this.reason = other.reason;
        }
    
        @ThriftConstructor
        public InitialException build() {
            InitialException result = new InitialException (
                this.reason
            );
            return result;
        }
    }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="reason", requiredness=Requiredness.NONE)
    public String getReason() { return reason; }
    
    
    public static com.facebook.thrift.payload.Reader<InitialException> asReader() {
      return InitialException::read0;
    }
    
    public static InitialException read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(InitialException.NAMES_TO_IDS, InitialException.THRIFT_NAMES_TO_IDS, InitialException.FIELD_METADATA);
      InitialException.Builder builder = new InitialException.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _REASON:
          if (__field.type == TType.STRING) {
            String reason = oprot.readString();
            builder.setReason(reason);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.reason != null) {
        oprot.writeFieldBegin(REASON_FIELD_DESC);
        oprot.writeString(this.reason);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
