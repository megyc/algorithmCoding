/**
 * 15. 三数之和
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int length = nums.size();
        if (nums.size() < 3) return {};//小于三个返回空
        sort(nums.begin(),nums.end());
        if (nums[0] > 0 || nums[length - 1] < 0) return {};//全都是正，或者全都是负，返回空
        int first = 0;
        int second = 1;
        int third = length - 1;
        while (first <= length - 3) {
            int sum = nums[first];//初始化sum
            if (!(first > 0 && nums[first] == nums[first - 1])){//判断是否重复
                while (second < third) {//移动两个指针，寻找和为0的情况
                    int temp = sum + nums[second] + nums[third];
                    if (temp < 0) {//比0小，second向右移动
                        second++;
                    } else if ( temp > 0){//比0大，third向左移动
                        third--;
                    } else {//找到了答案
                        ans.push_back({nums[first], nums[second], nums[third]});//不能退出循环，继续寻找
                        second++;
                        third--;
                        //去重，排除相邻相同的情况
                        while (second < third && nums[second] == nums[second - 1]) second++;
                        while (second < third && nums[third] == nums[third + 1]) third--;
                    }
                }
            }
            first++;//first前移
            second = first + 1;
            third = length - 1;
        }
        return ans;
    }
};