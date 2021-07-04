class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty()){
            minStack.push({val, val});
        }else{
            int min = minStack.top().second;
            if(val >= min){
                minStack.push({val, min});
            }else{
                minStack.push({val, val});
            }
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};