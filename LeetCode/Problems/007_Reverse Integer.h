/**
 * @Problem https://leetcode.com/problems/reverse-integer/submissions/
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
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};