/**
 * 383. 赎金信
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int sum[26] {};
        for (int i = 0; i < magazine.size(); i++) {
            sum[(int)magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (sum[(int)ransomNote[i] - 'a']-- < 1) return false;
        }
        return true;
    }
};