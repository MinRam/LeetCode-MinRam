/**
 * @Problem https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 * @Author  MinRam
 * @Date    03/25/2020
 * @tutorial none
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        
        int curProfit = 0;
        int curMin = prices[0];
        int length = prices.size();
        for(int index = 0 ; index < length ; ++index){
            // if(prices[index] < 0) return -1;  /* 判断非法输入 */
            if(prices[index]<curMin) 
                curMin = prices[index];
            curProfit = max(curProfit, prices[index] - curMin);
        }
        
        return curProfit;
    }
};