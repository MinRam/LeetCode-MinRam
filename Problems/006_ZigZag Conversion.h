/**
 * @Problem https://leetcode.com/problems/zigzag-conversion/
 * @Author MinRam
 * @Date  03/01/2019
 */


static const auto __ = []() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   return nullptr;
}();


class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.size() <= numRows) 
            return s;

		string resStr;
		int sectionSize = 2 * numRows - 2;
		for (int i = 0; i < numRows; ++i) {
			for (int j = i; j < s.size(); j += sectionSize) {
				resStr += s[j];
				if (i != 0 && i != numRows - 1) {
					int temp = j + sectionSize - 2 * i;
					if (temp < s.size()) {
						resStr += s[temp];
					}
				}
			}
		}
		return resStr;
	}
};