/**
 * 215. 数组中的第K个最大元素
 * 
*/

//堆排序解法
class Solution {
public:
    //堆排序法求解
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        //初始化大顶堆
        for(int i = length/2-1;i >= 0;i--){
            heapAjust(nums,i,length-1);
        }
        //将大顶移动k次，即可得到答案
        for(int i = length - 1;i >= length-k;i--){
            swap(nums[0],nums[i]);
            heapAjust(nums,0,i - 1);
        }
        return nums[length-k];
    }

    void heapAjust(vector<int>& nums,int start,int end){//调整成大顶堆
        int dad = start;
        int son = 2*dad+1;
        while(son<=end){//在范围内才比较
            if(son+1<=end && nums[son+1]>nums[son]){
                son++;
            }
            if(nums[dad]>=nums[son])return;//不需要交换
            else{
                swap(nums[dad],nums[son]);
                dad = son;
                son = 2*dad+1;
            }
        }
    }
};

//快速排序解法：
class Solution {
public:
    //快速排序序法求解
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        quickFindK(nums,0,length-1,k);
        return nums[length-k];
    }

    void quickFindK(vector<int>& nums,int low,int high,const int &k){
        if(low>=high) return;
        int key = nums[low];
        int i = low;
        int j = high + 1;
        while(i < j){
            while(i<j&&nums[--j]>key);
            while(i<j&&nums[++i]<key);
            if(i >= j) break;
            swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        if(j == nums.size() - k) return;//这个数刚好是第k大
        if(j < nums.size() - k){//这个数比第k大小，再前边继续快速排序
            quickFindK(nums,j+1,high,k);
        }else{
            quickFindK(nums,low,j-1,k); //在后边继续快排
        }
    }
};