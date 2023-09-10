/***************************************************************************//**
 * @file main.cpp
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-09
 *
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/

#include "StoneyDSP/modules/stoneydsp_core/stoneydsp_core.cpp"
// #include "modules/stoneydsp_nodejs/stoneydsp_nodejs.cpp"


#include "main.h"

Int Main(Int argc, Char* argv[])
{

    for(Int i = 0; i < argc; ++i)
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;

    std::cout << std::endl;


    using namespace StoneyDSP::Core::Types;

    {
        using namespace StoneyDSP::Core::Memory;

        unique_ptr<Value<Float>> numPtr = make_unique<Value<Float>>();

        std::cin.get();
    }

    std::cin.get();

    return 0;
}
