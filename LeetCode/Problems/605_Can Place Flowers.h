/**
 * @Problem https://leetcode.com/problems/can-place-flowers
 * @Author MinRam
 * @Date  08/23/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len == 0) return n==0;
        if(n == 0) return true;
        
    	for(int i=0;i<len;){
            if(flowerbed[i]==0){
              if( ( i == 0 || flowerbed[i-1] ==0 )
                && ( i == len - 1 || flowerbed[i+1] ==0)){
                   if(--n<=0) return true; 
                  flowerbed[i] = 1;
                  i+=2;   // jump to the next available position
              } else ++i;
            }
            else  i+=2;   // jump to the next available position
        }
    	return false;
    }
}; 