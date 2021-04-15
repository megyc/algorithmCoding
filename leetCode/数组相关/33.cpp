/**
 *33. 搜索旋转排序数组
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //二分查找
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[high]) {//mid在左侧旋转数组
                if (target >= nums[low] && target < nums[mid]) {//target在左侧连续区间，继续二分肯定能找到答案
                    high = mid - 1;
                } else {//target在右侧存在下降的区间
                    low = mid + 1;
                }
            } else {//mid在右侧旋转数组
                if (target > nums[mid] && target <= nums[high]) {//target在右侧连续区间，继续二分肯定能找到答案
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};