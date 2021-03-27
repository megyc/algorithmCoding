/*
*剑指 Offer 03. 数组中重复的数字
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //穷举法时间不通过
        set<int> mySet;
        //迭代器
        vector<int>::iterator it = nums.begin();
        //判断set元素是否增加
        int num = 0;
        for(it;it!=nums.end();it++){
            mySet.insert(*it);
            if(num == mySet.size()){
                return *it;
            } else {
                num = mySet.size();
            }
        }
        return -1;
    }
};