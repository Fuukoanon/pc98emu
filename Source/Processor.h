#pragma once

#include "Types.h"

namespace Processor
{

    union Register
    {
        u16 reg16;
        struct
        {
            u8 lo;
            u8 hi;
        };
    };

    struct CPU
    {
        // General-Purpose Registers
        Register AX;
        Register BX;
        Register CX;
        Register DX;

        // Pointer & Index Registers
        Register SP;
        Register BP;
        Register SI;
        Register DI;

        // Segment Registers
        Register CS;
        Register DS;
        Register SS;
        Register FS;

        // Other Registers
        Register IP;
        Register Flags;

        u64 cycles_total;

        CPU();
        ~CPU();
    };
}