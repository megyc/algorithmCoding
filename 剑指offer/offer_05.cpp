/*
 * 剑指 Offer 05. 替换空格
*/
class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for(char it:s){
            if(it == ' '){
                str+="%20";
            }
            else{
                str+=it;
            }
        }
        return str;
    }
};