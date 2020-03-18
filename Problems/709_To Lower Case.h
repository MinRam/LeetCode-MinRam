/**
 * @Problem https://leetcode.com/problems/to-lower-case/
 * @Author  MinRam
 * @Date    03/24/2019
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
    string toLowerCase(string str) {
        int len = str.size();
        for(size_t i = 0; i < len; ++i){
            str[i] = tolower(str[i]);
        }    
        return str;
    }
};