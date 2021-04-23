/**
 * 剑指 Offer 58 - II. 左旋转字符串
*/
//思路：1.拆分 + 合并(需要额外存储空间)||扩充 + 复制
//思路：2.反转整体，反转前半部本，反转后半部分o(1)额外存储空间
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};