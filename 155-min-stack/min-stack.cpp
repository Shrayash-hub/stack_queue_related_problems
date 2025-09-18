class MinStack {
private: 
    stack<long long> st;
    long long min_val;
public:
    MinStack() {
       min_val = LLONG_MAX; 
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_val = val;
        }
        else if(val>=min_val){
            st.push(val);
        }
        else{
            // saving the encoded value using formula 2*val - oldmin = encoded_value because we have to keep track of the previous minimum also
            st.push(2LL *val-min_val);
            // new element is the most minimum so, updating the min_val
            min_val = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long top_val = st.top();
        st.pop();
        if(top_val<min_val){ // when the encoding is used , original element is saved in the min_val and encoded value is saved in stack , that why while decoding old_min = 2*val - Encoded value is converted into 2* min_val - top_val(stack value)
            min_val = 2LL *min_val - top_val;
        }
    }
    
    int top() {
        long long top_val = st.top();
        if(top_val>=min_val) return (int)top_val;
        else return (int)min_val;
    }
    
    int getMin() {
        return (int)min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */