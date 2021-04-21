/**
 * 18. 四数之和
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        int left,right;//内层双指针
        int subtarget;
        int subsum;
        //排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            //第二次开始后去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
               //第二次开始后去重
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                subtarget = target - (nums[i] + nums[j]);
                left = j + 1;
                right = nums.size() - 1;
                while (left < right) {//双指针开始移动
                    subsum = nums[left] + nums[right];
                    if (subsum > subtarget) {
                        //右指针左移
                        right--;
                    } else if (subsum < subtarget) {
                        //左指针右移
                        left++;
                    } else {
                        //存入键值对
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        //移动左右指针
                        left++;
                        right--;
                        //找到下一个不同的元素
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
            } 
        }
        return ans;
    }
};