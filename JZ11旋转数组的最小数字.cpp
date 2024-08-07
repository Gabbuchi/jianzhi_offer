/*
由于题意要求O（logN）时间复杂度，所以用二分查找
主要有三种情况：
1、101111类：此种情况nums[mid] == nums[r],无法判断目标在哪里，所以只能r--
2、78123456类：nums[mid] < nums[r]，目标一定在mid位置或者mid左侧 特别考虑[2,3]类似情况，所以处理右边界时应该是r = mid;
3、34567812类：同上
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int>& nums) {
        int L = 0; 
        int R = nums.size()-1;
        while(L<R){
            int mid = L + ((R-L)>>1);
            if(nums[mid] > nums[R]){
                L = mid + 1;
            }else if(nums[mid] < nums[R]){
                R = mid;
            }else{
                R--;
            }
        }
        return nums[L];
    }
};
