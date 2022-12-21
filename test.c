#include <stdio.h>
#include "heap.h"

//struct memory_manager_t memory_manager;

int UTEST1(void);
int UTEST2(void);
int UTEST3(void);
int UTEST4(void);
int UTEST5(void);
int UTEST6(void);
int UTEST7(void);
int UTEST8(void);
int UTEST9(void);
int UTEST10(void);
int UTEST11(void);
int UTEST12(void);
int UTEST13(void);

int main(void)
{
    if(UTEST1() == -1)
    {
        printf("\nUTEST1 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST1 Passed\n");

    if(UTEST2() == -1)
    {
        printf("\nUTEST2 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST2 Passed\n");

    if(UTEST3() == -1)
    {
        printf("\nUTEST3 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST3 Passed\n");

    if(UTEST4() == -1)
    {
        printf("\nUTEST4 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST4 Passed\n");

    if(UTEST5() == -1)
    {
        printf("\nUTEST5 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST5 Passed\n");

    return 0;
}

//  Test 1: Sprawdzanie poprawności działania funkcji memory_init
int UTEST1(void)
{
    char memory[1732];

    memory_init(memory, 1732);

    if(memory_manager.memory_size != 1732) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    return 0;
}

//  Test 2: Sprawdzanie poprawności działania funkcji memory_malloc
int UTEST2(void)
{
    char memory[1436];

    memory_init(memory, 1436);

    if(memory_manager.memory_size != 1436) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(187);

    if(ptr1 == NULL) return -1;
    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr1) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr1 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 187) return -1;
    if(memory_manager.first_memory_chunk->free != 0) return -1;
    if(memory_manager.first_memory_chunk->next != NULL) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    return 0;
}

//  Test 3: Sprawdzanie poprawności działania funkcji memory_malloc
int UTEST3(void)
{
    char memory[1249];

    memory_init(memory, 1249);

    if(memory_manager.memory_size != 1249) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(0);

    if(ptr1 != NULL) return -1;

    return 0;
}

//  Test 4: Sprawdzanie poprawności działania funkcji memory_malloc
int UTEST4(void)
{
    char memory[1838];

    memory_init(memory, 1838);

    if(memory_manager.memory_size != 1838) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(1838);

    if(ptr1 != NULL) return -1;

    return 0;
}

//  Test 5: Sprawdzanie poprawności działania funkcji memory_malloc
int UTEST5(void)
{
    char memory[13697];

    size_t mem_sizes[] = {102, 115, 148, 155, 122};

    memory_init(memory, 13697);

    if(memory_manager.memory_size != 13697) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(mem_sizes[0]);

    if(ptr1 == NULL) return -1;
    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr1) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr1 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != mem_sizes[0]) return -1;
    if(memory_manager.first_memory_chunk->free != 0) return -1;
    if(memory_manager.first_memory_chunk->next != NULL) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    for (int i = 1; i < 5; ++i)
    {
        char *ptr1 = memory_malloc(mem_sizes[i]);
        if(ptr1 == NULL) return -1;
    }

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for (int i = 0; i < 5; ++i)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 4 && curr_chunk->next != NULL) || (i != 4 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    return 0;
}

int UTEST6(void);
int UTEST7(void);
int UTEST8(void);
int UTEST9(void);
int UTEST10(void);
int UTEST11(void);
int UTEST12(void);
int UTEST13(void);
