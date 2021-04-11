/**
 * 35. 搜索插入位置
*/

//自己写的：
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }

    int binarySearch(vector<int>& nums,int left,int right,int target){
        int mid = left+(right - left)/2;
        if(nums[mid] == target) return mid;
        if(left == right){
            if(nums[right]>target) return right;
            if(nums[right]<target) return right+1;
        }
        if(nums[mid] > target) return binarySearch(nums,left,mid,target);
        if(nums[mid] < target) return binarySearch(nums,mid + 1,right,target);
        return 0 ;
    }
};

//优化解法：
//对于闭合区间而言，如果要查找的数不在数组中，最后肯定会到达left==right相等的情况，
//如果target大于这个数，left会+1，跳出循环，left这就是这个数的位置，其实也就是right+1
//如果target小于这个数，right会-1，跳出循环，right后面的数就是这个数应该在的位置，就是right+1，就是left
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left<=right){//因为查询区间是[left,right]
            mid = left+((right - left)>>1);
            if(nums[mid]>target){
                right = mid - 1;
            } else if(nums[mid]<target){
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return right + 1;//也可以返回left
    }
};