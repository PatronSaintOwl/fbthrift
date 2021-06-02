/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic_swift_bean;

import java.util.*;

public class LegacyServiceBlockingReactiveWrapper 
    implements LegacyService.Reactive {
    private final LegacyService _delegate;

    public LegacyServiceBlockingReactiveWrapper(LegacyService _delegate) {
        
        this._delegate = _delegate;
    }

    @java.lang.Override
    public void dispose() {
        _delegate.close();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Map<String, List<Integer>>> getPoints(final Set<String> key, final long legacyStuff) {
        return reactor.core.publisher.Mono.fromSupplier(() -> {
                try {
                    return _delegate.getPoints(key, legacyStuff);
                } catch (Throwable _e) {
                    throw reactor.core.Exceptions.propagate(_e);
                }
            }).subscribeOn(com.facebook.thrift.util.resources.RpcResources.getOffLoopScheduler());
    }

}
