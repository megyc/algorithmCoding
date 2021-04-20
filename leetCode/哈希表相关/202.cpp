/**
 * 202. 快乐数
*/

//思路核心：判断死循环：
//思路一：记录所有节点，用哈希表加快查询
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1 && set.find(n) == set.end()) {
            set.insert(n);
            n = squareSum(n);
        }
        return n == 1;
    }
private:
    int squareSum(int m) {
        int sum = 0;
        while (m) {
            sum += (m % 10) * (m % 10);
            m /= 10;
        }
        return sum;
    }
};

//思路二：快慢指针：（同链表环）
class Solution {
public:
    bool isHappy(int n) {
        int fast,slow;
        slow = fast = n;
        do {
            fast = squareSum(fast);
            fast = squareSum(fast);
            slow = squareSum(slow);
        } while (fast != slow);
        return fast == 1;
    }
private:
    int squareSum(int m) {
        int sum = 0;
        while (m) {
            sum += (m % 10) * (m % 10);
            m /= 10;
        }
        return sum;
    }
};
