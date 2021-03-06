// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from token.djinni

#pragma once

#include "djinni_support.hpp"
#include "token.hpp"

namespace djinni_generated {

class NativeToken final : ::djinni::JniInterface<::Token, NativeToken> {
public:
    using CppType = std::shared_ptr<::Token>;
    using JniType = jobject;

    using Boxed = NativeToken;

    ~NativeToken();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeToken>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return {jniEnv, ::djinni::JniClass<NativeToken>::get()._toJava(jniEnv, c)}; }

private:
    NativeToken();
    friend ::djinni::JniClass<NativeToken>;
    friend ::djinni::JniInterface<::Token, NativeToken>;

    class JavaProxy final : ::djinni::JavaProxyCacheEntry, public ::Token
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();


    private:
        using ::djinni::JavaProxyCacheEntry::getGlobalRef;
        friend ::djinni::JniInterface<::Token, ::djinni_generated::NativeToken>;
        friend ::djinni::JavaProxyCache<JavaProxy>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/dropbox/djinni/test/Token") };
};

}  // namespace djinni_generated
