//
//  Test 1: Sprawdzanie poprawności działania funkcji memory_init
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji memory_init", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1732];

                memory_init(memory, 1732);

                test_error(memory_manager.memory_size == 1732, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1732, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");
            
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1436];

                memory_init(memory, 1436);

                test_error(memory_manager.memory_size == 1436, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1436, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(187);

                test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 187, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 187, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1249];

                memory_init(memory, 1249);

                test_error(memory_manager.memory_size == 1249, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1249, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(0);

                test_error(ptr1 == NULL, "Funkcja memory_malloc() powinna zwrócić NULL");

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1838];

                memory_init(memory, 1838);

                test_error(memory_manager.memory_size == 1838, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1838, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(1838);

                test_error(ptr1 == NULL, "Funkcja memory_malloc() powinna zwrócić NULL");
               
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[13697];

                size_t mem_sizes[] = {102, 115, 148, 155, 122};

                memory_init(memory, 13697);

                test_error(memory_manager.memory_size == 13697, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 13697, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(mem_sizes[0]);

                test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == mem_sizes[0], "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na %lu, a ustawiła na %lu",  mem_sizes[0], memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

                for (int i = 1; i < 5; ++i)
                {
                    char *ptr1 = memory_malloc(mem_sizes[i]);
                    test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 5; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], memory_manager.first_memory_chunk->size);
                    test_error(curr_chunk->free == 0, "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 5 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }
                

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[572];

                size_t mem_sizes[] = {174, 119, 183};

                memory_init(memory, 572);

                test_error(memory_manager.memory_size == 572, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 572, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(mem_sizes[0]);

                test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == mem_sizes[0], "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na %lu, a ustawiła na %lu",  mem_sizes[0], memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

                for (int i = 1; i < 3; ++i)
                {
                    char *ptr1 = memory_malloc(mem_sizes[i]);
                    test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 3; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], curr_chunk->size);
                    test_error(curr_chunk->free == 0, "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 3 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }


            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[490];

                size_t mem_sizes[] = {119, 188, 119};

                memory_init(memory, 490);

                test_error(memory_manager.memory_size == 490, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 490, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr[3];

                int i = 0;

                for (; i < 3 - 1; ++i)
                {
                    ptr[i] = memory_malloc(mem_sizes[i]);
                    test_error(ptr[i] != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                ptr[i] = memory_malloc(mem_sizes[i]);
                test_error(ptr[i] == NULL, "Funkcja memory_malloc() powinna zwrócić NULL");

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 3 - 1; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], curr_chunk->size);
                    test_error(curr_chunk->free == 0, "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 3 - 2)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }


            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji memory_free
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji memory_free", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1708];

                memory_init(memory, 1708);

                test_error(memory_manager.memory_size == 1708, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1708, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(155);

                test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 155, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 155, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

                memory_free(ptr1);

                test_error(memory_manager.memory_size == 1708, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1708, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");
                
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji memory_free
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji memory_free", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[1416];

                memory_init(memory, 1416);

                test_error(memory_manager.memory_size == 1416, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1416, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr1 = memory_malloc(157);

                test_error(ptr1 != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 157, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 157, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

                char *ptr2 = memory_malloc(157);

                memory_free(ptr1);

                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr1, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr1 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 157, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 157, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 1, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 1, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error((char *)memory_manager.first_memory_chunk->next == ptr2 - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na adres kolejnego bloku");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");

                memory_free(ptr2);

                test_error(memory_manager.memory_size == 1416, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 1416, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");
                
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[716];

                size_t mem_sizes[] = {111, 200, 145, 132};

                memory_init(memory, 716);

                test_error(memory_manager.memory_size == 716, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 716, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr[4];

                for (int i = 0; i < 4; ++i)
                {
                    ptr[i] = memory_malloc(mem_sizes[i]);
                    test_error(ptr[i] != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                memory_free(ptr[0]);
                memory_free(ptr[2]);

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 4; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], memory_manager.first_memory_chunk->size);
                    test_error(curr_chunk->free == !(i % 2), "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 4 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }

                memory_free(ptr[1]);

                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr[0], "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr[0] - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 520, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 520, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 1, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 1, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error((char *)memory_manager.first_memory_chunk->next == ptr[3] - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na adres kolejnego bloku");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");


            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[489];

                size_t mem_sizes[] = {106, 136, 151};

                memory_init(memory, 489);

                test_error(memory_manager.memory_size == 489, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 489, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr[4];

                for (int i = 0; i < 3; ++i)
                {
                    ptr[i] = memory_malloc(mem_sizes[i]);
                    test_error(ptr[i] != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                memory_free(ptr[1]);

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 3; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], curr_chunk->size);
                    test_error(curr_chunk->free == (i % 2), "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 3 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }

                memory_free(ptr[2]);

                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_free() powinna ustawić wskaźnik na następny blok na NULL");

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[378];

                size_t mem_sizes[] = {199, 115};

                memory_init(memory, 378);

                test_error(memory_manager.memory_size == 378, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 378, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr[2];

                for (int i = 0; i < 2; ++i)
                {
                    ptr[i] = memory_malloc(mem_sizes[i]);
                    test_error(ptr[i] != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                memory_free(ptr[0]);
                memory_free(ptr[1]);

                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                char memory[765];

                size_t mem_sizes[] = {155, 199, 108, 175};
                size_t mem_sizes_2[] = {155, 94, 108, 175};

                memory_init(memory, 765);

                test_error(memory_manager.memory_size == 765, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 765, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                char *ptr[4];

                for (int i = 0; i < 4; ++i)
                {
                    ptr[i] = memory_malloc(mem_sizes[i]);
                    test_error(ptr[i] != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                }

                onerror_terminate(); // przerwnie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct memory_chunk_t *curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 4; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], memory_manager.first_memory_chunk->size);
                    test_error(curr_chunk->free == 0, "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 4 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }

                memory_free(ptr[1]);
                ptr[1] = memory_malloc(94);

                curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 4; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes_2[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes_2[i], curr_chunk->size);
                    test_error(curr_chunk->free == 0, "Flaga free %d bloku pamięci powinna być ustawiona na 0, a ustawiła na %d", i, curr_chunk->free);
                    if (i == 4 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }

                memory_free(ptr[1]);

                curr_chunk = memory_manager.first_memory_chunk;

                for (int i = 0; i < 4; ++i)
                {
                    test_error(curr_chunk->size == mem_sizes[i], "Rozmiar %d bloku pamięci powinien być ustawiony na %lu, a jest na %lu",  i, mem_sizes[i], curr_chunk->size);
                    test_error(curr_chunk->free == (i == 1), "Flaga free %d bloku pamięci powinna być ustawiona na %d, a ustawiła na %d", i, i == 1, curr_chunk->free);
                    if (i == 4 - 1)
                        test_error(curr_chunk->next == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->next != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres kolejnego bloku", i);

                    if (i == 0)
                        test_error(curr_chunk->prev == NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na NULL", i);
                    else
                        test_error(curr_chunk->prev != NULL, "Wskaźnik next %d bloku pamięci powinien być ustawiony na adres poprzedniego bloku", i);

                    curr_chunk = curr_chunk->next;
                }

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji memory_free
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji memory_free", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char memory[172];

                memory_init(memory, 172);

                char *ptr = memory_malloc(16);

                memory_free(ptr + 1);
                memory_free(ptr - 1);
                memory_free(ptr - sizeof(struct memory_chunk_t));

                test_error(ptr != NULL, "Funkcja memory_malloc() powinna zwrócić adres przydzielonej pamięci, a zwróciła NULL");
                test_error(memory_manager.first_memory_chunk != NULL, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci");
                test_error((char *)memory_manager.first_memory_chunk != ptr, "Funkcja memory_malloc() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na adres pierwszego bloku pamieci, a nie na adres bloku pamięci zwróconego użytkownikowi");
                test_error((char *)memory_manager.first_memory_chunk == ptr - sizeof(struct memory_chunk_t), "Funkcja memory_malloc() powinna zwrócić użytkownikowi adres pamięci przesunięty o rozmiar struktury memory_chunk_t od początku dostępnej pamięci");
                test_error(memory_manager.first_memory_chunk->size == 16, "Funkcja memory_malloc() powinna ustawić rozmiar pierwszego bloku pamięci na 16, a ustawiła na %lu", memory_manager.first_memory_chunk->size);
                test_error(memory_manager.first_memory_chunk->free == 0, "Funkcja memory_malloc() powinna ustawić flagę free pierwszego bloku pamięci na 0, a ustawiła na %d", memory_manager.first_memory_chunk->free);
                test_error(memory_manager.first_memory_chunk->next == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik next pierwszego bloku pamięci na NULL");
                test_error(memory_manager.first_memory_chunk->prev == NULL, "Funkcja memory_malloc() powinna ustawić wskaźnik prev pierwszego bloku pamięci na NULL");


                memory_free(ptr);


                test_error(memory_manager.memory_size == 172, "Funkcja memory_init() powinna ustawić wartość memory_size w strukturze memory_manager na 172, a ustawiła na %lu", memory_manager.memory_size);
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");
                test_error(memory_manager.memory_start == memory, "Funkcja memory_init() powinna ustawić wartość memory_start w strukturze memory_manager na adres przekazany w parametrze funkcji");

        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji memory_malloc
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji memory_malloc", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
                  srand (time(NULL));
                
                  char memory[73554];
            
                  char *ptr[290];
                  int ptr_state[290] = {0};
                
                  int is_allocated = 0;
                
                  memory_init(memory, 73554);
                
                  for (int i = 0; i < 290; ++i)
                  {
                    if (rand() % 100 < 66)
                    {
                      for (int j = 0; j < 290; ++j)
                        if (ptr_state[j] == 0)
                        {
                          ptr_state[j] = 1;
                          ptr[j] = memory_malloc(rand() % 100 + 50);
                          is_allocated++;
                          break;
                        }
                    }
                    else
                    {
                      if (is_allocated)
                      {
                        int to_free = rand() % is_allocated;
                        for (int j = 0; j < 290; ++j)
                          if (ptr_state[j] == 1 && !(to_free--))
                          {
                            ptr_state[j] = 0;
                            is_allocated--;
                            memory_free(ptr[j]);
                            break;
                          }
                      }
                    }
                  }
                
                
                  for (int j = 0; j < 290; ++j)
                    if (ptr_state[j] == 1)
                      memory_free(ptr[j]);
                
                test_error(memory_manager.first_memory_chunk == NULL, "Funkcja memory_init() powinna ustawić wartość first_memory_chunk w strukturze memory_manager na NULL");

            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}