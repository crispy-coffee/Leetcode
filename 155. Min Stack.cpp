class MinStack {
public:
    stack<int> s;
    stack<int> mini;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(!mini.empty()){
            int lowest_num = min(mini.top(),val);
            mini.push(lowest_num);
        }else{
            mini.push(val);
        }
    }
    
    void pop() {
        s.pop();
        mini.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};