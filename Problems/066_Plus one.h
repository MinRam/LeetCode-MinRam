/**
 * @Problem https://leetcode.com/problems/plus-one/
 * @Author  MinRam
 * @Date    03/18/2020
 * @tutorial none
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int addition = 1;
        for(int index = length-1 ; index >= 0; --index){
            if(0 == addition) break;
            if(9 == digits[index]) digits[index] = 0 ;
            else {
                digits[index]+=1;
                addition = 0;
            }
        }
        if(addition != 0)  digits.insert(digits.begin(),1);
        return digits;
    }
};