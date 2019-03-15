/**
 * @Problem https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * @Author  xxxx
 * @Date    03/15/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    vector<char> map[10];
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        if(map[2].empty()){
            map[2] = {'a', 'b', 'c'};
            map[3] = {'d', 'e', 'f'};
            map[4] = {'g', 'h', 'i'};
            map[5] = {'j', 'k', 'l'};
            map[6] = {'m', 'n', 'o'};
            map[7] = {'p', 'q', 'r', 's'};
            map[8] = {'t', 'u', 'v'};
            map[9] = {'w', 'x', 'y', 'z'};
        }
        vector<string> result;
        for(char c : map[digits[0] - '0']) result.push_back(string(1, c));
        for(int i = 1; i < digits.length(); ++i){
            vector<string> temp;
            for(auto c : map[digits[i] - '0']){
                for(auto str : result){
                    temp.push_back(str + string(1, c));
                }
            }
            result = temp;
        }
        return result;
    }
};