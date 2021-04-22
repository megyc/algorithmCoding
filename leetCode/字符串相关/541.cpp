/**
 * 541. 反转字符串 II
*/
//自己的代码
class Solution {
public:
    string reverseStr(string s, int k) {
        if (k == 1) return s;
        int step = 1;//step记录现在正在处理的段，每一段k个元素，k为奇数时反转字符串，为偶数时不做处理
        int left,right;
        do {
            if (step % 2 == 0) {//判断是否为偶数段
                step++; 
                continue;
            }
            left = (step - 1) * k ;//上一段的结束
            right = step * k - 1 > s.size() - 1 ? s.size() - 1 : step * k - 1;
            while (left < right) {//交换
                swap(s[left++], s[right--]);
            }
            step++;
        } while ( (step - 1) * k <= s.size() - 1);
        return s;
    }
};
//思路清晰版本
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};