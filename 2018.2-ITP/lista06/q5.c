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
		for (int j = i+1; j < n; j++) {
			if (nums[i] == nums[j]) {
				printf("sim\n");
				return 0;
			}
		}
	}

	printf("não\n");

	return 0;
}
