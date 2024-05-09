#include "napi/native_api.h"
#include <aki/jsbind.h>

#include "test-napi.h";
#include "test-aki.h";

// Register AKI Addon
// Some notes that should be kept in mind
// 1. addonName should be the same as the module name in NAPI context.
// 2. JSBIND_ADDON should be declared before NAPI module registration,
// before RegisterEntryModule specifically, in order for AKI & NAPI
// hybrid development to work as expected. Otherwise, AKI bindings
// will be ignored.
JSBIND_ADDON(entry);

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{    
    AKI_LOG(INFO) << "enter Init flow";
    napi_property_descriptor desc[] = {
        { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);

    exports = aki::JSBind::BindSymbols(env, exports);

    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    AKI_LOG(INFO) << "register NAPI addon: " << __FUNCTION__;
    napi_module_register(&demoModule);
}