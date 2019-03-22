/**
 * @Problem https://leetcode.com/problems/generate-parentheses/
 * @Author  xxxx
 * @Date    03/12/2019
 * @tutorial none
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) {
      for (string str : dp[i - 1]) {
        dp[i].push_back(str + "()");
        int j = str.length() - 1;
        while (str[j] == ')') {
          dp[i].push_back(str.substr(0, j) + "()" + str.substr(j));
          j--;
        }
      }
    }
    return dp[n];
  }
};