/**
 * 剑指 Offer 12. 矩阵中的路径
 * 
 * 一定要注意二维数组的长和宽！！！
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //对每个位置调用search算法
        bool ans = false;
        for(int i = 0;i < board.size() && ans == false;i++){
            for(int j = 0;j < board[0].size();j++){
                ans = search(board,word,i,j,0);
                if(ans == true)
                    break;
            }
        }
        return ans;
    }

    //搜索+剪枝
    bool search(vector<vector<char>>& board,string word,int i,int j,int k){
        // cout<<word[k]<<":"<<k<<" i:"<<i<<" j:"<<j<<endl;
        if(k>word.size()-1) return true;//找到路径了
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j] != word[k]) {return false;}//超出矩阵范围或者该字符不糊和，剪枝
        board[i][j] = '/0';    //标志该位置已经搜索过，避免重复搜索
        //按右，下，左，上进行搜索
        if(search(board,word,i,j+1,k+1)||search(board,word,i+1,j,k+1)||search(board,word,i,j-1,k+1)||search(board,word,i-1,j,k+1))
            return true;//如果找到了
        else{
            board[i][j] = word[k];//恢复矩阵
            return false;
        }
    }
};