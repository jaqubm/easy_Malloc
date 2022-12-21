#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

struct memory_manager_t
{
    void *memory_start;
    size_t memory_size;
    struct memory_chunk_t *first_memory_chunk;
};

struct memory_chunk_t
{
    struct memory_chunk_t* prev;
    struct memory_chunk_t* next;
    size_t size;
    int free;
};

struct memory_manager_t memory_manager;

void memory_init(void *address, size_t size)
{
    memory_manager.memory_start = (uint8_t*)address;
    memory_manager.memory_size = size;
    memory_manager.first_memory_chunk = NULL;
}

void *memory_malloc(size_t size)
{
    if(size == 0 || size > memory_manager.memory_size - sizeof(struct memory_chunk_t)) return NULL;

    struct memory_chunk_t* cur = memory_manager.first_memory_chunk;

    if(memory_manager.first_memory_chunk == NULL)
    {
        cur = (void*)(memory_manager.memory_start);
        memory_manager.first_memory_chunk = cur;

        cur->prev = NULL;
        cur->next = NULL;
        cur->free = 0;
        cur->size = size;

        return (void*)((uint8_t*)cur + sizeof(struct memory_chunk_t));
    }

    size_t size_in = 0;

    while(cur->next != NULL)
    {
        if(cur->size >= size + sizeof(struct memory_chunk_t) && cur->free == 1) break;
        size_in += cur->size + sizeof(struct memory_chunk_t);
        cur = cur->next;
    }

    if(cur->size >= size + sizeof(struct memory_chunk_t) && cur->free == 1)
    {
        cur->free = 0;

        cur->size = size;

        return (void*)((uint8_t*)cur + sizeof(struct memory_chunk_t));
    }

    size_in += cur->size + sizeof(struct memory_chunk_t) + size;

    if(size_in > memory_manager.memory_size - sizeof(struct memory_chunk_t)) return NULL;

    if(cur->next == NULL)
    {
        struct memory_chunk_t* next = (void*)((uint8_t*)cur + sizeof(struct memory_chunk_t) + cur->size);

        next->prev = cur;
        next->next = NULL;
        next->free = 0;
        next->size = size;

        cur->next = next;

        cur = next;

        return (void*)((uint8_t*)cur + sizeof(struct memory_chunk_t));
    }

    return NULL;
}

void memory_free(void *address)
{
    if(address != NULL)
    {
        struct memory_chunk_t* cur = (struct memory_chunk_t*)((uint8_t*)address - sizeof(struct memory_chunk_t));

        if(cur->size == 0 || (cur->free != 1 && cur->free != 0)) return;

        int found = 0;

        struct memory_chunk_t* find = memory_manager.first_memory_chunk;

        while(find != NULL)
        {
            if(cur == find)
            {
                found = 1;

                break;
            }

            find = find->next;
        }

        if(found == 0) return;

        if(cur->next != NULL)
        {
            size_t new_size = ((uint8_t*)cur->next) - ((uint8_t*)cur + sizeof(struct memory_chunk_t));

            cur->size = new_size;
        }

        cur->free = 1;

        if(cur->prev != NULL && cur->prev->free == 1)
        {
            struct memory_chunk_t* prev = cur->prev;
            prev->next = cur->next;
            if(cur->next != NULL) cur->next->prev = prev;
            prev->size += cur->size + sizeof(struct memory_chunk_t);
            cur = prev;
        }

        if(cur->next != NULL && cur->next->free == 1)
        {
            struct memory_chunk_t* next = cur->next;
            cur->next = next->next;
            if(next->next != NULL) next->next->prev = cur;
            cur->size += next->size + sizeof(struct memory_chunk_t);
        }

        if(cur->next == NULL && cur->prev != NULL) cur->prev->next = NULL;

        if(cur->next == NULL && memory_manager.first_memory_chunk == cur) memory_manager.first_memory_chunk = NULL;
    }
}

#endif //HEAP_H
