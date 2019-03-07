/**
 * @Problem https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * @Author  MinRam
 * @Date    03/08/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0; // 绝对值大于零

		unordered_map<int,int> numsMap;
		int resCount = 0;

		for (size_t i = 0; i < nums.size(); ++i) {
			++numsMap[nums[i]];   // 通过map，进行数量计数
		}

		for (size_t i = 0; i < nums.size(); ++i) {
			if (numsMap.end() == numsMap.find(nums[i])) continue;
			if (0 == k) {
				if(numsMap[nums[i]] > 1)
					++resCount;     // 当k==0时候，只要查询等值的key的数量大于1即可。
			} else {
				// 向上和向下查询，若存在则计数加一
				if (numsMap.find(nums[i] + k) != numsMap.end())
					++resCount;      
				if (numsMap.find(nums[i] - k) != numsMap.end())
					++resCount;
			}
			// 对已经计数的移除该key
			numsMap.erase(nums[i]);
		}

		return resCount;
	}
};