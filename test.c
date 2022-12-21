#include <stdio.h>
#include "heap.h"

int main(void)
{
    char memory[1361];

    memory_init(memory, 1361);

    char *ptr1 = memory_malloc(164);

    memory_free(ptr1);

    return 0;
}



