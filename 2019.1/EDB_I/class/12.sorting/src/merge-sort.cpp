#include "../include/merge-sort.h"

void merge(int *firstL, int *lastL, int *firstR, int *lastR, int *firstA)
{
//        auto sizeA = (lastL - firstL) + (lastR - firstR);

        while ((firstL != lastL) && (firstR != lastR)) {
                if (*firstL < *firstR) {
                        *firstA = *firstL;
                        firstL++;
                } else {
                        *firstA = *firstR;
                        firstR++;
                }
                firstA++;
        }

        if (firstL < lastL) {
                std::copy(firstL, lastL, firstA);
        } else {
                std::copy(firstR, lastR, firstA);
        }
}

void mergesort(int *firstA, int *lastA)
{
        size_t sz_A = std::distance(firstA, lastA);

        if (sz_A > 1) {
                size_t sz_L = sz_A / 2;
                size_t sz_R = sz_A - sz_L;
                int *L = new int[sz_L];
                int *R = new int[sz_R];

                std::copy(firstA, firstA+sz_L, L);
                std::copy(firstA + sz_L, lastA, R);

                mergesort(L, L + sz_L);
                mergesort(R, R + sz_R);

                merge(L, L + sz_L, R, R + sz_R, firstA);

                delete[] L;
                delete[] R;
        }
}