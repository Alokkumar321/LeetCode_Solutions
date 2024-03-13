class MyQueue {
    stack<int> stackPush;
    stack<int> stackPop;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackPush.push(x);
    }
    
    int pop() {
        if(stackPop.empty()){
            while(!stackPush.empty()){
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        int front = stackPop.top();
        stackPop.pop();
        return front;
    }
    
    int peek() {
        if(stackPop.empty()){
            while(!stackPush.empty()){
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();
    }

    
    bool empty() {
        return stackPush.empty() && stackPop.empty();
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