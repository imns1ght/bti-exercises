#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max = 0;
    float *nums;
    
    scanf("%d", &n);
    nums = malloc(sizeof(float)*n);
    
    for (int i = 0; i < n; i++) {
        scanf("%f", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }

    printf("%d", max+1);

    return 0;
}