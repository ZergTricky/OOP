#ifndef TALLOCATOR
#define TALLOCATOR

#include "tvector.h"
#include <new>

class TAllocator {
public:
    TAllocator(const size_t &block_size, const size_t &block_count);

    void *allocate(size_t size);

    void deallocate(void *ptr);

    bool hasFreeBlocks();

    ~TAllocator();

private:
    size_t free_count;
    size_t block_count;
    size_t block_size;

    TVector<void *> free_blocks;
    char *used_blocks;
};

#endif // TALLOCATOR