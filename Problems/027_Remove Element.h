/**
 * @Problem https://leetcode.com/problems/remove-element/
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
	int removeElement(vector<int>& nums, int val) {
		size_t len = nums.size();
		for (size_t i = 0; i<len;) {
			if (nums[i] == val) {
				--len;
				nums[i] = nums[len]; // 获取新要素填充空位
			}
			else {
				++i;
			}
		}
		return len;
	}
};