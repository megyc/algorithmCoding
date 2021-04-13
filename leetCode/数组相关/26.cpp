/**
 * 26. 删除有序数组中的重复项
 * 
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0,right = 0;
        int length = nums.size();
        if(length == 0) return 0;
        for (right; right < length; right++){
            if(nums[right] != nums[left]){
                nums[++left] = nums[right];
            }
        }
        return left + 1;
    }
};