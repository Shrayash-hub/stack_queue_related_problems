class MyStack {
private: 
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        // sending all elements after the last element , so that we get that last element while pop()
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop(); // pop() , deletes the first element from the queue
        return val;
    }
    
    int top() {
       return  q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */