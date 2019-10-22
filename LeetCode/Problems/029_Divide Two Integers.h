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
		// �����������Խ��
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;

		// ͳһ����
		long m = labs(dividend), n = labs(divisor), res = 0;

		// �ж��Ƿ����
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

		// ȥ���������,�ֶ�ȥ���ߺ�ʱ���
		if (n == 1) return sign == 1 ? m : -m;

		// log(m) ��Сmֵ
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