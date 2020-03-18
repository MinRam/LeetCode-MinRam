  
/**
 * @Problem https://leetcode.com/problems/maximum-swap/
 * @Author MinRam
 * @Date  10/24/2019
 */

static const auto __ = []() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   return nullptr;
}();

class Solution {
public:
    int maximumSwap(int num) {
        int maxValue = -1, maxIndex = -1;
        int leftIndex = -1, rightIndex = -1;
        
        // 字符串方便操作
        string numStr = to_string(num);
        
        /* 从右往左遍历，只要关注 遍历过的元素集 的最大值， 与 未遍历过的元素 交换即可
         */
        for(int i = numStr.length() -1 ; i >= 0; --i){
            if(numStr[i] > maxValue){  // 此处字符转整数比较
                maxValue = numStr[i];
                maxIndex = i;
            }  else if (numStr[i] < maxValue){
                leftIndex = i;
                rightIndex = maxIndex;
            }
        }
        
        if( -1 == leftIndex ) return num;
        swap(numStr[leftIndex],numStr[rightIndex]);
        return stoi(numStr);
    }
};