#include<stdio.h>
#include<stdlib.h>
#include"vector.h"


int main()
{
    printf("Vector version: %s\n", VERSION);

    struct Vector vec;
    init_vector(&vec);

    for (int i = 0; i < 10; i++) {
        push(&vec, i * 10);
    }

    for (size_t i = 0; i < vec.size; i++) {
        printf("vec[%zu] = %d\n", i, at(&vec, i));
    }

    vector_free(&vec);

    return 0;
}