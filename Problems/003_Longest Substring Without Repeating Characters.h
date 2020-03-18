/**
 * @Problem https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @Author MinRam
 * @Date  02/21/2019
 */
static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        int left=-1;
        vector<int> last_index(128,-1);
        for(int i = 0;i < s.size(); ++i){
            left = max(left,last_index[s[i]]);
            last_index[s[i]] = i;
            max_size=max(max_size, i-left);
        }
        return max_size;
    }
};