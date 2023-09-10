/***************************************************************************//**
 * @file stoneydsp_nodejs.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-10
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/
#pragma once

#define __STONEYDSP_NODEJS_H__

#include <napi.h>

#define __N_API_ENV_T class Napi::Env
#define __N_API_STRING_T class Napi::String
#define __N_API_VALUE_T class Napi::Value
#define __N_API_NUMBER_T class Napi::Number
#define __N_API_OBJECT_T class Napi::Object
#define __N_API_FUNCTION_T class Napi::Function
#define __N_API_CALLBACK_INFO_T class Napi::CallbackInfo
#define __N_API_TYPE_ERROR_T class Napi::TypeError

namespace StoneyDSP
{
namespace NodeJS
{
typedef __N_API_ENV_T Env;
typedef __N_API_STRING_T String;
typedef __N_API_VALUE_T Value;
typedef __N_API_NUMBER_T Number;
typedef __N_API_OBJECT_T Object;
typedef __N_API_FUNCTION_T Function;
typedef __N_API_CALLBACK_INFO_T CallbackInfo;
typedef __N_API_TYPE_ERROR_T TypeError;

void checker(Const CallbackInfo& info);

static String Method(Const CallbackInfo& info);

static Value Calc(Const CallbackInfo& info);

static Value Add(Const CallbackInfo& info);

static Object Init(Env env, Object exports);

NODE_API_MODULE(stoneydsp, Init)

}
}
