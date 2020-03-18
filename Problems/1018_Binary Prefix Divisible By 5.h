/**
 * @Problem https://leetcode.com/problems/binary-prefix-divisible-by-5/
 * @Author MinRam
 * @Date  03/31/2019
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> ans(A.size(), false);

		int sum = 0;
		int len = A.size();

		for (int i = 0; i < len; ++i) {
			sum = sum << 1;
			sum += A[i];
			if (sum >= 5) sum -= 5;
			ans[i] = sum == 0;
		}

		return ans;

	}
};