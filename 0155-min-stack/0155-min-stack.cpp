class MinStack {
    stack<long long>st;
    int mini = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val > mini) st.push(val);
            else{
                long long new_val = 2ll*val - mini;
                mini = val;
                st.push(new_val);
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()<mini){
                mini = 2ll*mini - st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            if(st.top()<mini) return mini;
            else return st.top();
        }

        return -1;
    }
    
    int getMin() {
        return mini;
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