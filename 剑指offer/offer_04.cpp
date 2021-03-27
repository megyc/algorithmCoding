/*
*剑指 Offer 04. 二维数组中的查找
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //判断数组数组是否为空
        if(matrix.empty())
            return false;
        int lineSize,rowSize,i,j,now_pos;
        lineSize = matrix.size();
        rowSize = matrix[0].size();
        i = lineSize-1;
        j = 0;
        while(i>=0&&j<rowSize){//行和列都不超出范围
            now_pos = matrix[i][j];
            if(now_pos == target)
                return true;
            else if(now_pos>target){
                i--;
            }else if(now_pos<target){
                j++;
            }
        }
        return false;
    }
};