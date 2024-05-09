//
// Created on 2024/5/9.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef AKIDEMO_TEST_NAPI_H
#define AKIDEMO_TEST_NAPI_H

#include "napi/native_api.h"

napi_value Add(napi_env env, napi_callback_info info);

#endif //AKIDEMO_TEST_NAPI_H
