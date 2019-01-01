#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int *nInts, *mInts, *nums;
    
    scanf("%d", &n);
    nInts = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nInts[i]);
    }

    scanf("%d", &m);
    mInts = malloc(sizeof(int)*m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &mInts[i]);
    }

    nums = malloc(sizeof(int)*(m+n));

    /* Armazena os n e m ints em um único array */
    for (int i = 0; i < m+n; i++) {
        if (i < n) {
            nums[i] = nInts[i];
        } else {
            nums[i] = mInts[i-n];
        }
    }
    
    /* Ordena crescentemente */
    for (int i = 0; i < n+m; i++) {
		for (int j = 0; j < n+m; j++) {
			if (nums[j] > nums[i]) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
    
    for (int i = 0; i < m+n; i++) {
        printf("%d ", nums[i]);
    }
   
    return 0;
}