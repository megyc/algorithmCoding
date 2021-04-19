/**
 * 242. 有效的字母异位词
 * 
*/


//字符串只有小写字母的情况：
//数组可以当成一个特殊的哈希表，哈希映射就是 (int)String[i] - 'a',只要判断同样的字母出现字数是否相同即可
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[(int)(s[i] - 'a')]++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[(int)(t[i] - 'a')]--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};