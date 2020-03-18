/**
 * @Problem https://leetcode.com/problems/teemo-attacking/
 * @Author MinRam
 * @Date  08/23/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int len = timeSeries.size();
		if (len <= 0) return 0;
		if (duration <= 0) return 0;

		int time = duration;

		for (size_t i = 1; i < len; ++i) {
			time += min(duration, timeSeries[i]- timeSeries[i-1]); 
		}

		return time;
	}
};