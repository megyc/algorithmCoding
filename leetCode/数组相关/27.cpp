/**
 * 27. 移除元素
*/

//双指针法：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int length = nums.size();
        for(int fast = 0;fast < length;fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};