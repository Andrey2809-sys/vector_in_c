#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define VERSION "1.10"

struct Vector
{
    int* arr;
    size_t size;
    size_t capacity;
};

struct Vector   vector_create();
void            init_vector(struct Vector* vec);
void            push(struct Vector* vec, int el);
int             at(const struct Vector* vec, int pos);
void            pop(struct Vector* vec);
void            vector_free(struct Vector* vec);

#endif