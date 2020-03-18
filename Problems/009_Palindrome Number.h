/**
 * @Problem https://leetcode.com/problems/palindrome-number/
 * @Author MinRam
 * @Date  03/02/2019
 */


static const auto __ = []() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   return nullptr;
}();


class Solution {
public:
    bool isPalindrome(int x) {
         if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;                        
        }
        
        return x == revertedNumber || x == revertedNumber/10;
    }
};