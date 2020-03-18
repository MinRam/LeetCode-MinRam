/**
 * @Problem https://leetcode.com/problems/longest-palindromic-substring/
 * @Author MinRam
 * @Date  02/28/2019
 */
static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestPalindrome(string s) {
     	if (s.size() == 0) return "";

		int len = s.size();
		int maxlen = 0;
		int id = 0;
		int resId = 0;

		vector<char> s_new((len << 1) + 1);
		vector<int> s_p((len << 1) + 1);

		for (int i = 0; i < len; ++i) {
			s_new[i << 1] = '#';	
			s_new[(i << 1) + 1] = s[i];
		}
		s_new[len << 1] = '#';
		s_p[0] = 1;

		for (int i = 1; i < s_new.size() - 1; ++i ) {
 			s_p[i] = i < maxlen ? min(s_p[(id<<1) - i] ,maxlen - i + 1) : 1;

			while ( !(i < s_p[i] || i + s_p[i] >(len << 1)) 
				&& s_new[i - s_p[i]] == s_new[i + s_p[i]]) {
				++s_p[i];
			}

			if (maxlen < i + s_p[i] - 1) {
				id = i;
				maxlen = i + s_p[i] - 1;
			}

			if (s_p[resId] <= s_p[i]) {
				resId = i;
			}
		}

		return s.substr((resId - s_p[resId] + 1)/2, s_p[resId] - 1);
    }
};