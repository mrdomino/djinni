// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from set.djinni

#include "NativeSetRecord.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeSetRecord::NativeSetRecord() = default;

NativeSetRecord::~NativeSetRecord() = default;

auto NativeSetRecord::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeSetRecord>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::Set<::djinni::String>::fromCpp(jniEnv, c.set).get())};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeSetRecord::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeSetRecord>::get();
    return {::djinni::Set<::djinni::String>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mSet))};
}

}  // namespace djinni_generated
