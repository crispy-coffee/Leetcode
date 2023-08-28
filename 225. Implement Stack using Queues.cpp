class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int value = q.front();
        q.pop();   
        return value;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
