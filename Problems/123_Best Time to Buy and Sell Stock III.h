/**
 * @Problem https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
 * @Author  MinRam
 * @Date    03/28/2020
 * @tutorial none
 */
 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    static inline int max(int a, int b){
        return a>b?a:b;
    } 
    static inline int min(int a, int b){
        return a<b?a:b;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int stockNum = prices.size();

        vector<int> firstProfits(stockNum);
        firstProfits[0] = 0;

        int Oper = prices[0];

        // get the  profit array from buying and selling at first time;
        for(int firstIndex = 1 ; firstIndex < stockNum; ++ firstIndex){
                Oper = min(Oper,prices[firstIndex]);
                firstProfits[firstIndex] = max(firstProfits[firstIndex-1],prices[firstIndex] - Oper);
        }
        
        // get the maximum profit of buying and selling at second time;
        int maxProfit = firstProfits.back();
        int curLastProfit = 0;
        Oper = prices.back();
        for(int lastIndex = stockNum - 1; lastIndex > 0; --lastIndex){
                Oper = max(Oper,prices[lastIndex]);
                curLastProfit = max(curLastProfit, Oper - prices[lastIndex]);
                maxProfit = max(maxProfit,curLastProfit + firstProfits[lastIndex-1]);
        }

        return maxProfit;
    }
};