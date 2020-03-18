/**
 * @Problem https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * @Author MinRam
 * @Date  08/22/2019
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		size_t len = nums.size();
		if (len <= 1) return len;
		size_t lasPosi = 1;
		for (size_t count = 1; count < len; ++count) {
			if (nums[count] != nums[count - 1]) {
				nums[lasPosi] = nums[count];
				++lasPosi;
			}
		}
		
		return lasPosi;
	}
};
