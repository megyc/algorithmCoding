/**
 * 剑指 Offer 11. 旋转数组的最小数字
*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0,high = numbers.size()-1,mid;
        
        //二分
        while(low < high){
            mid = low + (high-low)/2;
            //后半段有序，说明最小值在前面
            if(numbers[mid]<numbers[high]){
                high = mid;
            }else if(numbers[mid]>numbers[high]){//说明最小值在mid和high中间
                low = mid+1;
            }else if(numbers[mid] == numbers[high]){
                high--;
            }
        }
        return numbers[low];
    }
};