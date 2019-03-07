/**
 * @Problem https://leetcode.com/problems/longest-common-prefix/
 * @Author  MinRam
 * @Date    03/07/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];
		
		string res = strs[0];
		size_t index = 1;

		while (index < strs.size()) {
			res = getSimlar(res, strs[index]);
			if (res.size() == 0) break;
			++index;
		}
		return res;
	}

	string getSimlar(string & a, string & b) {
		string res = "";
		for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
			if (a[i] == b[i]) 
				res += a[i];
			else 
				break;
		}
		return res;
	}
};