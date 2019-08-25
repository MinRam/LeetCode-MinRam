/**
 * @Problem https://leetcode.com/problems/search-insert-position/
 * @Author  MinRam
 * @Date    08/25/2019
 * @complexity Time:O(logn),Space:O(1)
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;
        if(nums[0]>target) return 0;
        if(nums[len-1]<target) return len;
        
        int pre = 0;
        int las = len;
        while(pre < las){
            int min = (pre + las) >> 1;
            int midNum = nums[min];
            if(midNum == target) return min;
            else if(midNum > target) {
                las = min;
            } else {
                pre = min + 1;
            }
        }
        return pre;
    }
};