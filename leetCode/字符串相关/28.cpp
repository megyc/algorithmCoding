/**
 * 28. 实现 strStr()
*/
//kmp算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int next[needle.size()];
        int j = -1;//next数组-1的结果
        //得到next数组
        next[0] = -1;
        for (int i = 1; i < needle.size(); i++) {
            while (j >= 0 && needle[j + 1] != needle[i]) {//后缀和前缀不相等
                j = next[j];//回到前一个next的
            }
            if (needle[i] == needle[j + 1]) {//后缀前缀相等
                j++;
            }
            next[i] = j;
        }
        //匹配
        j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >=0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == (needle.size() - 1)) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};