#pragma once
#include <memory>
#include "Types.h"
namespace Memory
{
    class Memory
    {
    public:
        Memory();
        ~Memory();

        u8 read8(const u32 addr);
        void write8(const u32 addr, const u8 val);

        u16 read16(const u32 addr);
        void write16(const u32 addr, const u16 val);
        const u8 *Memory::get() noexcept;
        size_t size() noexcept;

    private:
        std::unique_ptr<u8[]> space;
    };
}