/**
 * @Problem https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 * @Author  MinRam
 * @Date    03/27/2020
 * @tutorial null
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
        
        int length = prices.size();
        int totalProfit = 0;
        
        for(int index = 1 ; index < length; ++index){
            if(prices[index] > prices[index - 1]){
                totalProfit += prices[index] - prices[index - 1];
            }
        }
        
        return totalProfit;
    }
};