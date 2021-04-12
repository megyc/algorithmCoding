/**
 * 59. 螺旋矩阵 II
*/
//思想：分别设置上下左右的限制，从左到右，从上到下，从右到左，从下到上填充，达到极简代码的效果
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n,vector<int>(n));
        int tar = n * n;
        int num = 1;
        int l = 0, r = n - 1, t = 0, b = n - 1;
        while (num <= tar){
            for(int i = l; i <= r; i++) matrix[t][i] = num++;
            t++;
            for(int i = t; i <= b; i++) matrix[i][r] = num++;
            r--;
            for(int i = r; i >= l; i--) matrix[b][i] = num++;
            b--;
            for(int i = b; i >= t; i--) matrix[i][l] = num++;
            l++;
        }
        return matrix;
    }
};