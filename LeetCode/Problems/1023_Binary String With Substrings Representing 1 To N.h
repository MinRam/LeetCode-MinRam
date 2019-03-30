/**
 * @Problem https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
 * @Author MinRam
 * @Date  03/30/2019
 */
 
 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool queryString(string S, int N) {
		if (N > 2 * S.length()) return false;
        
		for (int i = N; i > N / 2; --i) {
			string b = bitset<32>(i).to_string();
			if (S.find(b.substr(b.find("1"))) == string::npos)
				return false;
		}
        
		return true;
	}
};