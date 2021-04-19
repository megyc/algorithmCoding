/**
 * 
 * 349. 两个数组的交集
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set,ansSet;
        vector<int> ans;
        //构建哈希表
        for (int i = 0; i < nums1.size(); i++) {
            set.insert(nums1[i]);
        }
        //依次判断每个元素是否在哈希表中
        for (int i = 0; i < nums2.size(); i++) {
            if (set.find(nums2[i]) != set.end()) ansSet.insert(nums2[i]);
        }
        ans.assign(ansSet.begin(),ansSet.end());
        return ans;
    }
};

//官方优化（效率差不多，但是逻辑清晰）
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (auto& num : nums1) {
            set1.insert(num);
        }
        for (auto& num : nums2) {
            set2.insert(num);
        }
        return getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1);
        }
        vector<int> intersection;
        for (auto& num : set1) {
            if (set2.count(num)) {
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};
