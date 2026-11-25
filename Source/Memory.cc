#include <memory.h>
#include <cassert>
#include "Memory.h"
#include "Types.h"
#include "Config.h"

namespace Memory
{
    Memory::Memory()
    {
        static_assert(Cfg::memory_size > 0, "Memory size must be not zero");
        static_assert(Cfg::memory_size % 1024 == 0, "Memory size must be whole KiBs");

        std::unique_ptr<uint8_t[]> space(new u8[Cfg::memory_size]);
    }
    Memory::~Memory() {}

    u8 Memory::read8(const u32 addr)
    {
        assert(addr < Cfg::memory_size);
        return space[addr];
    }

    void Memory::write8(const u32 addr, const u8 val)
    {
        assert(addr < Cfg::memory_size);
        space[addr] = val;
    }

    u16 Memory::read16(const u32 addr)
    {
        assert(addr + 1 < Cfg::memory_size);
        return static_cast<u16>(space[addr]) | (static_cast<u16>(space[addr] + 1) << 8);
    }

    void Memory::write16(const u32 addr, const u16 val)
    {
        assert(addr + 1 < Cfg::memory_size);
        space[addr] = static_cast<u8>(val & 0xff);
        space[addr + 1] = static_cast<u8>(val >> 8);
    }

    const u8 *Memory::get() noexcept
    {
        return space.get();
    }
}