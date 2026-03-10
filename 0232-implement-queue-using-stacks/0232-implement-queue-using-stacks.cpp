class MyQueue {
public:
    stack<int>st;

    MyQueue() {
        
    }
    
    void push(int x) {
        vector<int> v;
        int n = st.size();
        for(int i=0; i<n; i++){
            v.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for(int i = v.size()-1; i >= 0; i--){
            st.push(v[i]);
        }
    }
    
    int pop() {
        if(!st.size()) return -1;
        int front = st.top();
        st.pop();
        return front;
    }
    
    int peek() {
        if(!st.size()) return -1;
        return st.top();
    }
    
    bool empty() {
        return st.size() == 0;
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