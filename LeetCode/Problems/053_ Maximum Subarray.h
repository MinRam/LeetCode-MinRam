/**
 * @Problem https://leetcode.com/problems/maximum-subarray
 * @Author MinRam
 * @Date  10/29/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

// O(n) time, O(1) space, dynamic programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int sum = 0;
        int max = INT_MIN;
        int length = nums.size();

        for(int i = 0; i < length; i++) {
            sum += nums[i];
            max = max > sum ? max:sum;
            //如果sum小于0了，将sum重置为0，从i + 1再次开始计算
            if(sum < 0) {
                sum = 0;
            }
        }

        return max;
    }
};
