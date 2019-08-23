/**
 * @Problem https://leetcode.com/problems/move-zeroes/
 * @Author MinRam
 * @Date  08/23/2019
 * @Complexiy O(n)=n;T(n)=n;
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] == 0)
				++count;
			else {
				nums[i - count] = nums[i];
				if (count != 0)
					nums[i] = 0;
			}

		}
	}
};