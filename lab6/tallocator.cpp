#include "tallocator.h"

TAllocator::TAllocator(const size_t &block_size, const size_t &block_count) : block_size(block_size),
                                                                              block_count(block_count),
                                                                              free_count(block_count) {
    used_blocks = (char *) malloc(block_size * block_count);
    for (size_t i = 0; i < block_count; ++i) {
        free_blocks.InsertLast(used_blocks + i * block_size);
    }
}

void *TAllocator::allocate(size_t size) {
    std::cout << "allocated!\n";
    if (!hasFreeBlocks()) {
        size_t old = block_count;
        free_count += 20;
        block_count += 20;
        used_blocks = (char *) realloc(used_blocks, block_count * block_size);
        for (size_t i = old; i < block_count; ++i) {
            free_blocks.InsertLast(used_blocks + i * block_size);
        }
    }
    void *result = free_blocks.Last();
    free_blocks.RemoveLast();
    --free_count;
    return result;
}

void TAllocator::deallocate(void *ptr) {
    std::cout << "deallocated!\n";
    free_count++;
    free_blocks.InsertLast(ptr);
}

bool TAllocator::hasFreeBlocks() {
    return free_count > 0;
}

TAllocator::~TAllocator() {
    std::cout << "freed!\n";
    free(used_blocks);
}