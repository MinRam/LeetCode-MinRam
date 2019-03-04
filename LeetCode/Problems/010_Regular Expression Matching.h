/**
 * @Problem https://leetcode.com/problems/regular-expression-matching/
 * @Author XXXXX
 * @Date  03/04/2019
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
	bool isMatch(string s, string p) {
		const int s_len = s.size();
		const int p_len = p.size();
		bool dp[s_len + 1][p_len + 1] = {}; // initialize!
		dp[0][0] = true;
		for (int j = 1; j <= p_len; ++j) {
			if (p[j - 1] == '*') {
				dp[0][j] = dp[0][j - 2];
			}
		}
		for (int i = 1; i <= s_len; ++i) {
			for (int j = 1; j <= p_len; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
						dp[i][j] = dp[i][j - 2]; //skip x*
					}
					else {
						dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
					}
				}
			}
		}
		return dp[s_len][p_len];
	}
};