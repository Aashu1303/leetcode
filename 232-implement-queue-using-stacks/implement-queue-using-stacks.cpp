class MyQueue {
    stack<int> s , s1;
public:
    MyQueue() {
        s = stack<int>();
        s1 = stack<int>();
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(!s1.empty()){
            int top = s1.top();
            s1.pop();
            return top;
        }
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        if(!s1.empty()){
            int top = s1.top();
            return top;
        }
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        int top = s1.top();
        return top;
    }
    
    bool empty() {
        if(s1.empty() && s.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */