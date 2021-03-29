/**
 * 剑指 Offer 13. 机器人的运动范围
*/
class Solution {
public:
    //判断数字所有位相加的结果
    int getSum(int x){
        int ans = 0;
        while(x){
            ans +=(x%10);
            x/=10;
        }
        return ans;
    }

    int movingCount(int m, int n, int k) {
        if(k == 0){
            return 1;
        }
        //递推法：v[i][j] = v[i-1][j]|v[i][j-1]
        //建立一个标记矩阵:
        //该矩阵m行，n列全为0
        vector<vector<int>> movingMap (m,vector<int>(n,0));
        //初始时的状态
        int ans = 1;
        movingMap[0][0] = 1;
        //循环判断地推条件
        for(int i = 0;i < m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j==0 || getSum(i)+getSum(j)> k) continue;//如果是[0][0],不用计算，如果相加大于k，则不用更改标记
                //第0行以下，说明可以向下移动到达这个格子
                if(i - 1 >= 0) movingMap[i][j] |= movingMap[i-1][j];
                //第0行以右，说明可以向右移动到达这个格子
                if(j - 1 >= 0) movingMap[i][j] |= movingMap[i][j-1];
                ans+=movingMap[i][j];
            }
        }
        return ans;
    }
};