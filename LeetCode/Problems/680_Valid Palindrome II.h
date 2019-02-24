/**
 * @Problem https://leetcode.com/problems/valid-palindrome-ii/
 * @Author MinRam
 * @Date  02/24/2019
 */

static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:



bool validPalindrome(string s) {
 int lo = 0;
 int hi = s.size() - 1;



 while (lo < hi) {
 if (s[lo] != s[hi]) // 发现不同字符对，进行删字符
 return isPalin(s, lo + 1, hi) || isPalin(s, lo, hi - 1); // 判断删除后的剩余字符串是否为回文
 ++lo;
 --hi;
 }
 return true;
 }


 // 回文判断
 bool isPalin(const string &s, int lo, int hi) {
 while (lo < hi) {
 if (s[lo] != s[hi])
 return false;
 ++lo;
 --hi;
 }
 return true;
 }
};