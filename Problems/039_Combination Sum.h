/**
 * @Problem https://leetcode.com/problems/combination-sum/
 * @Author MinRam
 * @Date  10/28/2019
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end(), [](int l, int right) {return l > right; });

		vector<vector<int>> results;
		vector<int> combination;

		findCombinations(candidates, target, 0, combination, 0, results);

		return results;
	}

	void findCombinations(vector<int>& candidates,
		int target,
		int startIndex,
		vector<int>& combination,
		int sum,
		vector<vector<int>>& results) {

		if (sum > target) {
			return;
		}

		if (sum == target) {
			results.push_back(combination);
			return;
		}

		for (int i = startIndex; i < candidates.size(); ++i) {
			combination.push_back(candidates[i]);
			findCombinations(candidates, target, i, combination, sum + candidates[i], results);
			combination.pop_back();
		}
	}
};