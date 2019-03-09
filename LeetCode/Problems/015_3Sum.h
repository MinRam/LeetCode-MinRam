/**
 * @Problem https://leetcode.com/problems/3sum/
 * @Author  MinRam
 * @Date    03/09/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		
		if (nums.size() <= 2)return result;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (long j = i + 1, k = nums.size() - 1; j < k;) {
				int b = nums[j];
				int c = nums[k];
				int value = a + b + c;
				if (value == 0) {
					result.push_back(vector<int>({ a, b, c }));
					while (j < k && b == nums[++j]);
					while (j < k && c == nums[--k]);
				}
				else if (value > 0) {
					--k;
				}
				else {
					++j;
				}
			}
		}
		return result;
	}
};