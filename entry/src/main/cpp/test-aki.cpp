//
// Created on 2024/5/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <string>
#include <aki/jsbind.h>
#include "test-aki.h";

static std::string sayHello(std::string msg) { return msg + " too."; }

static std::string callArkTSStaticMethod(aki::Value av) {
    aki::Value res = av.CallMethod("foo");
    AKI_LOG(INFO) << "C++ call JS static Fun: " << res.As<std::string>();
    return res.As<std::string>();
}

static int asyncTaskReturnInt() {
    AKI_LOG(INFO) << "[Aki] run async task";
    return rand();
}

static int asyncTaskReturnInt2() {
    AKI_LOG(INFO) << "[Aki] run async task2";
    return rand();
}

class TaskRunner {
public:
    TaskRunner() = default;
    std::string doTask() {
        AKI_LOG(INFO) << "DoTask";
        return "done.";
    }
};

JSBIND_CLASS(TaskRunner) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_PMETHOD(doTask);
}

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(sayHello);
    JSBIND_FUNCTION(callArkTSStaticMethod);
    JSBIND_PFUNCTION(asyncTaskReturnInt);
    JSBIND_PFUNCTION(asyncTaskReturnInt2); 
}