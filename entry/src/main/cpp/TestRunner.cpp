//
// Created on 2024/5/8.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include <string>
#include <aki/jsbind.h>

class TaskRunner {
public:
    TaskRunner() = default;
    std::string DoTask() {
        AKI_LOG(INFO) << "DoTask";
        return "done.";
    }
};

JSBIND_CLASS(TaskRunner) {
    JSBIND_CONSTRUCTOR<>();
    JSBIND_PMETHOD(DoTask, "doTask");
}

int AsyncTaskReturnInt2() {
    AKI_LOG(INFO) << "[Aki] run async task2";
    return rand(); 
}

JSBIND_GLOBAL() { JSBIND_PFUNCTION(AsyncTaskReturnInt2, "asyncTaskReturnInt2"); }