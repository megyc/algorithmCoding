/**
 * 翻转字符串里的单词
*/

//思路1：额外创建一个o(n)的空间，然后将单词写进去
//思路1 - 方法1 库函数：split+reverse+joint
//思路1 - 方法2 双端队列，从前到后分割每个单词，并不断在头部空格和单词
//思路1 - 方法3 从后向前扫描单词，依次添加到答案尾部(自己的思路)，需要注意：判断结束的条件 
class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;//加一个空格，类似于头节点
        string ans;
        int right, left;
        left = s.size();
        while (left > 0) {
            while (left > 0 && s[--left] == ' ') ;//去除空格
            if (left == 0) break;//避免加上空串
            right = left;
            if (ans != "") ans += ' ';//如果不是第一次，而且还有单词，则在两个单词之间添加空格
            while (left > 0 && s[--left] != ' ') ;//找到下一个空格
            ans += string(s, left + 1, right - left);
        }
        return ans;
    }
};
//思路2 - 不创建额外空间
//思路：去掉多余的空格，将数组原地反转，依次扫描每个单词，反转每个单词