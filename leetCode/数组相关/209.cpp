/**
 * 209. 长度最小的子数组
*/

//自己写的
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 100001;
        int sum = 0;
        int i = 0;
        bool flag = false;
        //i做前面的指针，j做后面的指针(闭区间)
        for(int j = 0;j < nums.size();j++){
            sum += nums[j];
            while(sum >= target){
                flag = true;
                if ( (j - i + 1) <ans) ans = j - i + 1;
                sum -= nums[i];
                i++;
            }
        }
       if(flag) return ans;
       else return 0;
    }
};

//优化过后
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT32_MAX;
        int sum = 0;
        int arraySize = nums.size();//减少每次循环的开销；
        int windowSize;//记录滑动窗口的大小
        int i = 0;
        //i做前面的指针，j做后面的指针(闭区间)
        for(int j = 0;j < arraySize;j++){
            sum += nums[j];
            while(sum >= target){
                windowSize = j - i + 1;
                ans = windowSize < ans ? windowSize : ans;
                sum -= nums[i++];
            }
        }
       return ans == INT32_MAX ? 0 : ans;
    }
};