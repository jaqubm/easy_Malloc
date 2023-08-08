#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

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
int UTEST14(void);
int UTEST15(void);

int main(void)
{
    printf("\nStarting Tests!\n\n");

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

    if(UTEST6() == -1)
    {
        printf("\nUTEST6 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST6 Passed\n");

    if(UTEST7() == -1)
    {
        printf("\nUTEST7 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST7 Passed\n");

    if(UTEST8() == -1)
    {
        printf("\nUTEST8 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST8 Passed\n");

    if(UTEST9() == -1)
    {
        printf("\nUTEST9 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST9 Passed\n");

    if(UTEST10() == -1)
    {
        printf("\nUTEST10 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST10 Passed\n");

    if(UTEST11() == -1)
    {
        printf("\nUTEST11 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST11 Passed\n");

    if(UTEST12() == -1)
    {
        printf("\nUTEST12 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST12 Passed\n");

    if(UTEST13() == -1)
    {
        printf("\nUTEST13 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST13 Passed\n");

    if(UTEST14() == -1)
    {
        printf("\nUTEST14 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST14 Passed\n");

    if(UTEST15() == -1)
    {
        printf("\nUTEST15 Failed\n\nTests Failed\n");
        return -1;
    } 
    else printf("UTEST15 Passed\n");

    printf("\nAll Tests Passed Successfully\n\n");

    return 0;
}

//  Test 1: Testing functionality of memory_init
int UTEST1(void)
{
    char memory[1732];

    memory_init(memory, 1732);

    if(memory_manager.memory_size != 1732) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    return 0;
}

//  Test 2: Testing functionality of memory_malloc
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

//  Test 3: Testing functionality of memory_malloc
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

//  Test 4: Testing functionality of memory_malloc
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

//  Test 5: Testing functionality of memory_malloc
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

    for(int i=1; i<5; i++)
    {
        char *ptr1 = memory_malloc(mem_sizes[i]);
        if(ptr1 == NULL) return -1;
    }

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<5; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 4 && curr_chunk->next != NULL) || (i != 4 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    return 0;
}

//  Test 6: Testing functionality of memory_malloc
int UTEST6(void)
{
    char memory[572];

    size_t mem_sizes[] = {174, 119, 183};

    memory_init(memory, 572);

    if(memory_manager.memory_size != 572) return -1;
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

    for(int i=1; i<3; i++)
    {
        char *ptr1 = memory_malloc(mem_sizes[i]);
        if(ptr1 == NULL) return -1;
    }

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<3; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 2 && curr_chunk->next != NULL) || (i != 2 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    return 0;
}

//  Test 7: Testing functionality of memory_malloc
int UTEST7(void)
{
    char memory[490];

    size_t mem_sizes[] = {119, 188, 119};

    memory_init(memory, 490);

    if(memory_manager.memory_size != 490) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr[3];

    int i = 0;

    for(; i<2; i++)
    {
        ptr[i] = memory_malloc(mem_sizes[i]);
        if(ptr[i] == NULL) return -1;
    }

    ptr[i] = memory_malloc(mem_sizes[i]);
    if(ptr[i] != NULL) return -1;

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<2; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 1 && curr_chunk->next != NULL) || (i != 1 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    return 0;
}

//  Test 8: Testing functionality of memory_free
int UTEST8(void)
{
    char memory[1708];

    memory_init(memory, 1708);

    if(memory_manager.memory_size != 1708) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(155);

    if(ptr1 == NULL) return -1;
    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr1) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr1 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 155) return -1;
    if(memory_manager.first_memory_chunk->free != 0) return -1;
    if(memory_manager.first_memory_chunk->next != NULL) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    memory_free(ptr1);

    if(memory_manager.memory_size != 1708) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    return 0;
}

//  Test 9: Testing functionality of memory_free
int UTEST9(void)
{
    char memory[1416];

    memory_init(memory, 1416);

    if(memory_manager.memory_size != 1416) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr1 = memory_malloc(157);

    if(ptr1 == NULL) return -1;
    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr1) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr1 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 157) return -1;
    if(memory_manager.first_memory_chunk->free != 0) return -1;
    if(memory_manager.first_memory_chunk->next != NULL) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    char *ptr2 = memory_malloc(157);

    memory_free(ptr1);

    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr1) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr1 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 157) return -1;
    if(memory_manager.first_memory_chunk->free != 1) return -1;
    if((char *)memory_manager.first_memory_chunk->next != ptr2 - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    memory_free(ptr2);

    if(memory_manager.memory_size != 1416) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    return 0;
}

//  Test 10: Testing functionality of memory_malloc
int UTEST10(void)
{
    char memory[716];

    size_t mem_sizes[] = {111, 200, 145, 132};

    memory_init(memory, 716);

    if(memory_manager.memory_size != 716) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr[4];

    for(int i=0; i<4; i++)
    {
        ptr[i] = memory_malloc(mem_sizes[i]);
        if(ptr[i] == NULL) return -1;
    }

    memory_free(ptr[0]);
    memory_free(ptr[2]);

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<4; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != !(i % 2)) return -1;
        if ((i == 3 && curr_chunk->next != NULL) || (i != 3 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    memory_free(ptr[1]);

    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr[0]) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr[0] - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 520) return -1;
    if(memory_manager.first_memory_chunk->free != 1) return -1;
    if((char *)memory_manager.first_memory_chunk->next != ptr[3] - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    return 0;
}

//  Test 11: Testing functionality of memory_malloc
int UTEST11(void)
{
    char memory[489];

    size_t mem_sizes[] = {106, 136, 151};

    memory_init(memory, 489);

    if(memory_manager.memory_size != 489) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr[3];

    for(int i=0; i<3; i++)
    {
        ptr[i] = memory_malloc(mem_sizes[i]);
        if(ptr[i] == NULL) return -1;
    }

    memory_free(ptr[1]);

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<3; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != (i % 2)) return -1;
        if ((i == 2 && curr_chunk->next != NULL) || (i != 2 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    memory_free(ptr[2]);

    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk->next != NULL) return -1;

    return 0;
}

//  Test 12: Testing functionality of memory_malloc
int UTEST12(void)
{
    char memory[378];

    size_t mem_sizes[] = {199, 115};

    memory_init(memory, 378);

    if(memory_manager.memory_size != 378) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr[2];

    for(int i=0; i<2; i++)
    {
        ptr[i] = memory_malloc(mem_sizes[i]);
        if(ptr[i] == NULL) return -1;
    }

    memory_free(ptr[0]);
    memory_free(ptr[1]);

    if(memory_manager.first_memory_chunk != NULL) return -1;

    return 0;
}

//  Test 13: Testing functionality of memory_malloc
int UTEST13(void)
{
    char memory[765];

    size_t mem_sizes[] = {155, 199, 108, 175};
    size_t mem_sizes_2[] = {155, 94, 108, 175};

    memory_init(memory, 765);

    if(memory_manager.memory_size != 765) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    char *ptr[4];

    for(int i=0; i<4; i++)
    {
        ptr[i] = memory_malloc(mem_sizes[i]);
        if(ptr[i] == NULL) return -1;
    }

    struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<4; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 3 && curr_chunk->next != NULL) || (i != 3 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    memory_free(ptr[1]);
    ptr[1] = memory_malloc(94);

    curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<4; i++)
    {
        if(curr_chunk->size != mem_sizes_2[i]) return -1;
        if(curr_chunk->free != 0) return -1;
        if ((i == 3 && curr_chunk->next != NULL) || (i != 3 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    memory_free(ptr[1]);

    curr_chunk = memory_manager.first_memory_chunk;

    for(int i=0; i<4; i++)
    {
        if(curr_chunk->size != mem_sizes[i]) return -1;
        if(curr_chunk->free != (i == 1)) return -1;
        if ((i == 3 && curr_chunk->next != NULL) || (i != 3 && curr_chunk->next == NULL)) return -1;
        if ((i == 0 && curr_chunk->prev != NULL) || (i != 0 && curr_chunk->prev == NULL)) return -1;

        curr_chunk = curr_chunk->next;
    }

    return 0;
}

//  Test 14: Testing functionality of memory_free
int UTEST14(void)
{
    char memory[172];

    memory_init(memory, 172);

    char *ptr = memory_malloc(16);

    memory_free(ptr + 1);
    memory_free(ptr - 1);
    memory_free(ptr - sizeof(struct memory_chunk_t));

    if(ptr == NULL) return -1;
    if(memory_manager.first_memory_chunk == NULL) return -1;
    if((char *)memory_manager.first_memory_chunk == ptr) return -1;
    if((char *)memory_manager.first_memory_chunk != ptr - sizeof(struct memory_chunk_t)) return -1;
    if(memory_manager.first_memory_chunk->size != 16) return -1;
    if(memory_manager.first_memory_chunk->free != 0) return -1;
    if(memory_manager.first_memory_chunk->next != NULL) return -1;
    if(memory_manager.first_memory_chunk->prev != NULL) return -1;

    memory_free(ptr);

    if(memory_manager.memory_size != 172) return -1;
    if(memory_manager.first_memory_chunk != NULL) return -1;
    if(memory_manager.memory_start != memory) return -1;

    return 0;
}

//  Test 15: Testing functionality of memory_malloc
int UTEST15(void)
{
    srand(time(NULL));

    char memory[73554];

    char *ptr[290];
    int ptr_state[290] = {0};

    int is_allocated = 0;

    memory_init(memory, 73554);

    for(int i=0; i<290; i++)
    {
        if(rand() % 100 < 66)
        {
            for(int j=0; j<290; j++)
            {
                if(ptr_state[j] == 0)
                {
                    ptr[j] = memory_malloc(rand() % 100 + 50);
                    ptr_state[j] = 1;
                    is_allocated++;
                    break;
                }
            }
        }
        else
        {
            if(is_allocated)
            {
                int to_free = rand() % is_allocated;

                for(int j=0; j<290; j++)
                {
                    if(ptr_state[j] == 1 && !(to_free--))
                    {
                        memory_free(ptr[j]);
                        ptr_state[j] = 0;
                        is_allocated--;
                        break;
                    }
                }
            }
        }
    }

    for(int j=0; j<290; j++)
        if(ptr_state[j] == 1)
            memory_free(ptr[j]);

    if(memory_manager.first_memory_chunk != NULL) return -1;

    return 0;
}
