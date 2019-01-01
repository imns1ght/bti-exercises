#include <stdio.h>

int main()
{
	int n, seq = 0;
	int nums[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	for (int j = 0; j < n; j++) {
		if (nums[j] == nums[j+1]) {
			seq++;				
		}
	}

	printf("%d", seq);

	return 0;
}
