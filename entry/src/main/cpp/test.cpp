//
// Created on 2024/5/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <aki/jsbind.h>
#include <string>

std::string sayHello(std::string msg) { return msg + " too."; }

std::string callArkTSStaticMethod(aki::Value av) {
    aki::Value res = av.CallMethod("foo");
    AKI_LOG(INFO) << "C++ call JS static Fun: " << res.As<std::string>();
    return res.As<std::string>();
}

int asyncTaskReturnInt() {
    AKI_LOG(INFO) << "[Aki] run async task";
    return rand();
}

// Step 1 注册 AKI 插件
JSBIND_ADDON(entry) // 注册 AKI 插件名: 即为编译*.so名称，规则与NAPI一致

// Step 2 注册 FFI 特性
JSBIND_GLOBAL() {
    JSBIND_FUNCTION(sayHello);
    JSBIND_FUNCTION(callArkTSStaticMethod); 
    JSBIND_PFUNCTION(asyncTaskReturnInt);
}