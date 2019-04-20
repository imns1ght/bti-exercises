#include "../include/client.h"

bool cmp(const void *a, const void *b) {
        return (*((int *)a) < *((int *)b));
}