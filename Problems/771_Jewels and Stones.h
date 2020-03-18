/**
 * @Problem https://leetcode.com/problems/jewels-and-stones/
 * @Author MinRam
 * @Date  02/20/2019
 */

static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
		
		bool jewels[58] = { false };

		// the type of stones that are jewels is none
		if (J.size() <= 0) return 0;
		// the stones that i have is none;
		if (S.size() <= 0) return 0;
		
		for (size_t i = 0; i < J.size(); ++i) {
			jewels[J[i] - 'A'] = true;
		}
		
		for (size_t j = 0; j < S.size(); ++j) {
			if (jewels[S[j] - 'A']) ++res;
		}

		return res;
    }
};