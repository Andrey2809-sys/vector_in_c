#include "vector.h"

// create vector with default data(capacity = 2, size = 0) 
struct Vector vector_create()
{
    size_t size = 0;
    size_t capacity = 2;

    struct Vector vec = {
        .arr = (int*) malloc(capacity * sizeof(int)),
        .size = size,
        .capacity = capacity
    };
    return vec;
}

// init vector with default data(capacity = 2, size = 0) 
void init_vector(struct Vector* vec)
{
    vec->size = 0;
    vec->capacity = 2;
    vec->arr = (int*) malloc(vec->capacity * sizeof(int));
    if (vec->arr == NULL) {
        fprintf(stderr, "[ERROR #1] Memory allocation failed (Vector is NULL)\n");
        exit(-1);
    }
}

// push element in the end of vector
void push(struct Vector* vec, int el)
{
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        // reallocate vector
        vec->arr = realloc(vec->arr, vec->capacity * sizeof(int));
        if (vec->arr == NULL) {
            fprintf(stderr, "[ERROR #1] Memory allocation failed (Vector is NULL)\n");
            exit(-1);            
        }
    }

    *(vec->arr+vec->size) = el;
    vec->size++;
}

// get element
int at(const struct Vector* vec, int pos)
{
    if (pos < 0 || pos >= vec->size) { 
        fprintf(stderr, "[ERROR #2] Out of bounds (Position: %d, Size: %d, Capacity: %d)\n", pos, vec->size, vec->capacity);
        exit(-1);
    }

    return (int) *(vec->arr+pos);
}

void pop(struct Vector* vec)
{
    if (vec->size == 0) {
        fprintf(stderr, "[ERROR #3] Pop from empty vector (Size: 0)\n");
        exit(-1);
    }

    *(vec->arr + vec->size-1) = 0;
    vec->size--;
}

void vector_free(struct Vector* vec)
{
    if (vec->arr) {
        free(vec->arr);
        vec->arr = NULL;
    }
    vec->capacity = 0;
    vec->size = 0;
}