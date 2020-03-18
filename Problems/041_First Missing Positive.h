/**
 * @Problem https://leetcode.com/problems/first-missing-positive/
 * @Author  MinRam
 * @Date    03/18/2019
 * @tutorial none
 */
 
/**
* Definition for singly-linked list.
*/
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int numsLen = nums.size();
        for (int i = 0 ; i < numsLen; ){
        	if (nums[i] != (i + 1) && nums[i] >= 1 && nums[i] <= numsLen && nums[nums[i] - 1] != nums[i])
        		swap(nums[i], nums[nums[i] - 1]);
        	else
        		i++;
        }
        for (int i = 0; i < numsLen; ++i)
        	if (nums[i] != (i + 1))
        		return i + 1;
        return numsLen + 1;
	}
};