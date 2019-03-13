/**
 * @Problem https://leetcode.com/problems/3sum-closest/
 * @Author  MinRam
 * @Date    03/13/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());

		int len = nums.size();
		int p = 0, q = 1, r = len - 1;
		int delta = 0x3f3f3f3f;   // 等同maxint
		int ans = nums[0] + nums[1] + nums[2];
		int lastr = len - 1;

		for (; p < len - 2; p++) {
			q = p + 1;
			for (r = lastr; r > q && nums[p] + nums[q] + nums[r] > target; --r);

			if (r <= q) break;
			lastr = r;
			for (; q < r;) {
				if (nums[p] + nums[q] + nums[r] > target) {
					--r;
				}
				else if (nums[p] + nums[q] + nums[r] < target) {
					int tmp = target - nums[p] - nums[q] - nums[r];
					if (tmp < delta) {
						delta = tmp;
						ans = nums[p] + nums[q] + nums[r];
					}
					++q;
				}
				else {
					return target;
				}
			}
		}

		int lastp = 0;
		for (r = len - 1; r >= 2; r--) {
			q = r - 1;
			for (p = lastp; p < q && nums[p] + nums[q] + nums[r] <= target; ++p);
			if (p >= q) break;
			lastp = p;

			for (; p < q;) {
				if (nums[p] + nums[q] + nums[r] > target) {
					int tmp = nums[p] + nums[q] + nums[r] - target;
					if (tmp < delta) {
						delta = tmp;
						ans = tmp + target;
					}
					--q;
				}
				else if (nums[p] + nums[q] + nums[r] < target) {
					++p;
				}
				else {
					return target;
				}
			}
		}

		return ans;
	}
};