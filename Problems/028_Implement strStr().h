/**
 * @Problem https://leetcode.com/problems/implement-strstr/
 * @Author MinRam
 * @Date  08/24/2019
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
	int strStr(string haystack, string needle) {
		size_t hayLen = haystack.size();
		size_t needLen = needle.size();

		if (needLen == 0) return 0;
		if (hayLen == 0 || hayLen < needLen) return -1; // the length  of substring  is longer than the length of string

		int posi = haystack.find(needle);
		if (posi == string::npos) return -1;
		else return posi;
	}
};