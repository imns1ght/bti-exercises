#include <stdio.h>

int main()
{
	int n;
	int nums[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nums[j] < nums[i]) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}
