class MyStack {
public:
    queue<int> one;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        one.push(x);
        if(one.size() > 1){
            int s = one.size()-1;
            for(int i=0; i<s; i++){
                int x = one.front();
                one.pop();
                one.push(x);
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = one.front();
        one.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return one.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return one.empty();
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