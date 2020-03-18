/**
 * @Problem https://leetcode.com/problems/add-strings/
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
    string addStrings(string num1, string num2) {
        string res = "";
        int num1Index = num1.size()-1;
        int num2Index = num2.size()-1;
        int carry = 0;
        while (num1Index >=0 || num2Index >=0 ){
            if(num1Index >=0) carry += num1[num1Index]-'0';
            if(num2Index >=0) carry += num2[num2Index]-'0';
            res.push_back(carry%10 + '0');
            carry/=10;
            --num1Index,--num2Index;
        }
        if(carry!=0)
            res.push_back(carry%10+'0');
        reverse(res.begin(),res.end());
        return res;
    }
};