/**
 * @Problem https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @Author  MinRam
 * @Date    04/03/2019
 * @tutorial none
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int las = nums.size() - 1;
		int pre = 0;
		int med = nums.size() / 2;

		while (pre <= las) {
			if (nums[med] < target) {
				pre = med + 1;
				med = (las + pre) / 2;
			}
			else if(nums[med] > target) {
				las = med - 1;
				med = (las + pre) / 2;
			}
			else if (nums[med] == target) {
				vector<int> ans;
				pre = las = med;
				while (pre >=0 && nums[pre] == target) --pre;
				while (las < nums.size() && nums[las] == target) ++las;
				ans.push_back(pre + 1);
				ans.push_back(las - 1);
				return ans;
			}
		}

		return { -1,-1 };	
	}
};