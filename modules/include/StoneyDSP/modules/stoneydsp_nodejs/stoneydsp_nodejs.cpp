/***************************************************************************//**
 * @file stoneydsp_nodejs.cpp
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-10
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/

#ifdef __STONEYDSP_NODEJS_H__
 #error "Incorrect usage of 'stoneydsp_nodejs.cpp'!"
#endif

namespace StoneyDSP
{
/**
 * @brief The 'StoneyDSP::NodeJS' namespace.
 *
 */
namespace NodeJS
{

} // namespace NodeJS
} // namespace StoneyDSP

#include "stoneydsp_nodejs.h"



namespace StoneyDSP
{
namespace NodeJS
{
static String Method(Const CallbackInfo& info)
{
    // 'Napi::Env' is the opaque data structure containing the environment in
    // which the request is being run. We will need this env when we want to
    // create any new objects inside of the node.js environment.
    Env env = info.Env();

    // Create a C++ level variable.
    std::string helloWorld = "Hello, world!";

    // Return a new javascript string that we copy-construct inside of the
    // NodeJs environment
    return String::New(env, helloWorld);
}


void checker(Const CallbackInfo& info)
{
	Env env = info.Env();

	std::string msg = "Number expected";

	if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        TypeError::New(env, msg).ThrowAsJavaScriptException();
    }
}

static Value Calc(Const CallbackInfo& info)
{
	Env env = info.Env();

	checker(info);

	Double a = info[0].As<Number>().DoubleValue();
    Double b = info[1].As<Number>().DoubleValue();

	Double result = a + b;

	return Number::New(env, result);

}

static Value Add(Const CallbackInfo& info)
{
    Env env = info.Env();

	if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        TypeError::New(env, "Number expected").ThrowAsJavaScriptException();

        return env.Null();
    }

	Double a = info[0].As<Number>().DoubleValue();
    Double b = info[1].As<Number>().DoubleValue();
    Double sum = a + b;

	return Number::New(env, sum);
}


static Object Init(Env env, Object exports)
{
    exports.Set(
        String::New(env, "hello"),
        Function::New(env, Method)
    );

    exports.Set(
        String::New(env, "calculate"),
        Function::New(env, Calc)
    );

    exports.Set(
        String::New(env, "add"),
        Function::New(env, Add)
    );

    return exports;
}

} // namespace NodeJS
} // namespace StoneyDSP
