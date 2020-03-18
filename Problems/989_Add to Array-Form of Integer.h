/**
 * @Problem https://leetcode.com/problems/add-to-array-form-of-integer/
 * @Author  MinRam
 * @Date    03/18/2020
 * @tutorial none
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
       int arrayIndex = A.size() - 1;
       vector<int> res;
       while(K >0 && arrayIndex >= 0){
           K += A[arrayIndex];
           A[arrayIndex] = K%10;
           K /= 10;
           --arrayIndex;
       }
        
       while(K>0){
           A.insert(A.begin(),K%10);
           K /= 10;
       }
        
        return A;
    }
};