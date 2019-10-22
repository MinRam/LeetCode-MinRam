/**
 * @Problem https://leetcode.com/problems/divide-two-integers/
 * @Author MinRam
 * @Date  10/23/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int divide(int dividend, int divisor) {
		// 避免后续操作越界
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;

		// 统一符号
		long m = labs(dividend), n = labs(divisor), res = 0;

		// 判断是否异号
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

		// 去除特殊情况,手动去除高耗时情况
		if (n == 1) return sign == 1 ? m : -m;

		// log(m) 减小m值
		while (m >= n) {
			long t = n, p = 1;
			while (m >= (t << 1)) {
				t <<= 1;
				p <<= 1;
			}
			res += p;
			m -= t;
		}

		return sign == 1 ? res : -res;
	}
};