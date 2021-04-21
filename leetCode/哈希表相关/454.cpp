/**
 * 454. 四数相加 II
*/

//思路：数组两两分组，分别得出两个数组所有可能的结果，然后从中寻找等于0的解的个数，运用哈希表可以减少搜索的时间复杂度
//与twoSum和threeSum的区别：不用找出具体的键值对是什么，只要找到个数即可
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int,int> map;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a+b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                if (map.find(-(c+d)) != map.end()) {
                    ans += map[-(c+d)];
                }
            }
        }
        return ans;
    }
};