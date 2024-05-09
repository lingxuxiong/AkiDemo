//
// Created on 2024/5/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <bits/alltypes.h>
#include <string>
#include <aki/jsbind.h>

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

class TaskRunner {
public:
    TaskRunner(): value(0) {};
    TaskRunner(int val): value(val) {}
    ~TaskRunner() = default;
    
    std::string doTask() {
        AKI_LOG(INFO) << "DoTask";
        return "done.";
    }
    
    int getValue() {
        return value;
    }
    
    long getTime() {
        AKI_LOG(INFO) << "getTime: " << time;
        return time;
    }
    
    void setTime(long time) {
        AKI_LOG(INFO) << "setTime: " << time;
        this->time = time;
    }
    
public:
    int value;
    long time;
};

JSBIND_CLASS(TaskRunner) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_CONSTRUCTOR<int>();
    JSBIND_METHOD(getValue);
    JSBIND_PMETHOD(doTask);
    JSBIND_PROPERTY(value);
    JSBIND_FIELD("time", getTime, setTime);
}

JSBIND_GLOBAL() {
    JSBIND_FUNCTION(sayHello);
    JSBIND_FUNCTION(callArkTSStaticMethod);
    JSBIND_PFUNCTION(asyncTaskReturnInt);
}