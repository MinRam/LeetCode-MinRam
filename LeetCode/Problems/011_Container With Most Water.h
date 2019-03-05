/**
 * @Problem https://leetcode.com/problems/container-with-most-water/
 * @Author MinRam
 * @Date  03/05/2019
 */
 
 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
	int maxArea(vector<int>& height) {
		int resContainer = 0;
		int pre = 0;
		int las = height.size() - 1;
		
		// 从数组左右两端开始往内计算
		while (pre < las) {
			int curHeight = min(height[pre], height[las]);
			resContainer = max(resContainer, curHeight * (las - pre));
			
			// 选择较低端开始缩减
			if (height[pre] < height[las]) {
				// 直到碰到比原来高的才停止缩减
				do {
					++pre;
				} while (pre < las && curHeight > height[pre]);
			}
			else {
				// 直到碰到比原来高的才停止缩减
				do {
					--las;
				} while (pre < las && curHeight > height[las]);
			}
		}

		return resContainer;
	}
};