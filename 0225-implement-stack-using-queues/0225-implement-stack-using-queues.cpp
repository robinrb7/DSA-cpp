class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        if(q1.empty()) q1.push(x);
        else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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