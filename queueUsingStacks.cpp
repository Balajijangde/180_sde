class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s2.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        }else{
            while(!s1.empty()){
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            return s2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};