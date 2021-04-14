/**
 * 16. 最接近的三数之和
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int length = nums.size();
        int first = 0;
        int second = first + 1;
        int third = length - 1;
        int ans;
        bool flag = true;
        while (first <= length - 3) {
            while (second < third){
                int sum = nums[first] + nums[second] + nums[third];
                int gap = sum - target;
                if (flag) {
                    ans = sum;
                    flag = false;
                } else ans = abs(ans - target) > abs(gap) ? sum : ans;
                if (gap < 0) {//这里可以去重，但是经过实践，去重实践反而更长
                    second++;
                } else if (gap > 0) {
                    third--;
                } else return ans;
            }
            first++;
            second = first + 1;
            third = length - 1;
        }
        return ans;
    }
};