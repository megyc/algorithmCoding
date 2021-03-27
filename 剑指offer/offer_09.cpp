/*
 * 剑指 Offer 09. 用两个栈实现队列
 * /
class CQueue {
private:
    stack<int> stack1,stack2;
public:
    CQueue() {
        //初始化时确保stack1，stack2均为空
        while(!stack1.empty()){
            stack1.pop();
        }
        while(!stack2.empty()){
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        //stack1当作栈
        stack1.push(value);
    }
    
    int deleteHead() {
        //如果stack2为空，则把stack1倒入stack2
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()){
            return -1;
        }else{
            int ans = stack2.top();
            stack2.pop();
            return ans;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */