#ifndef REGISTER_ALLOCATOR_H
#define REGISTER_ALLOCATOR_H 

#include <stdint.h>

#define SET_BIT(mask, bit) ((mask) |= (1 << (bit)))
#define RESET_BIT(mask, bit) ((mask) &= ~(1 << (bit)))
#define GET_BIT(mask, bit)  ((mask) & (1 << (bit)))

struct RegisterAllocator {
    // 32 registers - 32 bit mask
    // bit = 0 - register free
    // bit = 1 - register busy
 
    uint32_t busyMask;

};

void regAllocatorInit(struct RegisterAllocator* registerAllocator) {
    registerAllocator->busyMask = (uint32_t)0;

    SET_BIT(registerAllocator->busyMask, 0);
}

int regAllocatorAlloc(struct RegisterAllocator* registerAllocator) {
    
    for (uint i = 0; i < 32; ++i) {   
        if (GET_BIT(registerAllocator->busyMask, i)) {
            continue;
        }

        SET_BIT(registerAllocator->busyMask, i);
        return i + 1;
    }
    
    return -1;
}

int regAllocatorFree(struct RegisterAllocator* registerAllocator,
    const int registerNum) {
    RESET_BIT(registerAllocator->busyMask, registerNum - 1);
}

#endif
