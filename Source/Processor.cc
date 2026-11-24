#include "Processor.h"
#include "Types.h"

namespace Processor
{
    CPU::CPU()
    {
        // Pointer & Index Registers
        SP.reg16 = 0x0000;

        // Segment Registers
        CS.reg16 = 0xffff;
        DS.reg16 = 0x0000;
        SS.reg16 = 0x0000;
        FS.reg16 = 0x0000;

        // Other Registers
        IP.reg16 = 0x0000;
        Flags.reg16 = 0x0000;
    }
}