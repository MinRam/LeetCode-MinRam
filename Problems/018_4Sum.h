/**
 * @Problem https://leetcode.com/problems/4sum/
 * @Author  xxxx
 * @Date    03/16/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, const int target)const  throw() {
		vector<vector<int>> result;
		const int size = nums.size();
		int i = 0;
		sort(nums.begin(), nums.end());

		while (i < size - 3) {
			const int a = nums[i];
			int bIter = i + 1;
			if (a + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (a + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) goto increment_i;

			while (bIter < size - 2) {
				int cIter = bIter + 1;
				int dIter = size - 1;
				const int b = nums[bIter];

				if (a + b + nums[bIter + 1] + nums[bIter + 2] > target) break;
				if (a + b + nums[size - 2] + nums[size - 1] < target) goto increment_bIter;

				while (cIter < dIter) {
					const int c = nums[cIter];
					const int d = nums[dIter];
					const int sum = a + b + c + d;
					if (sum == target) {
						vector<int> solution{ a,b,c,d };
						result.push_back(solution);
						do {
							++cIter;
						} while (cIter < size && c == nums[cIter]);
					}
					if (sum < target) {
						do {
							++cIter;
						} while (cIter < size && c == nums[cIter]);
					}
					if (sum > target) {
						do {
							--dIter;
						} while (0 <= dIter && d == nums[dIter]);
					}
				}
				increment_bIter:
				do {
					++bIter;
				} while (bIter < size && b == nums[bIter]);
			}
			increment_i:
			do {
				i++;
			} while (i < size && a == nums[i]);
		}
		return result;
	}
};