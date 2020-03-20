/**
 * @Problem https://leetcode.com/problems/sqrtx
 * @Author  MinRam
 * @Date    03/20/2020
 * @tutorial reference_book
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int mySqrt(int x) {
        if (0 == x || 1 == x) return x;
        
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};