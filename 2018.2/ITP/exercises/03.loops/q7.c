#include <stdio.h>

int main()
{
	int n;
	scanf("%d ", &n);

	int nums[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	
	for (int j = 1; j < n; j++) {
		if (nums[0] < nums[j]) {
			nums[0] = nums[j];
		}
	}
	printf("%d", nums[0]);

	return 0;
}
