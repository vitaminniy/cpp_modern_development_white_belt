#include <vector>

void Reverse(std::vector<int>& nums) {
	if (nums.size() <= 1)
		return;

	int i = 0;
	int j = nums.size() - 1;

	while (i <= j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
		++i;
		--j;
	}
}
