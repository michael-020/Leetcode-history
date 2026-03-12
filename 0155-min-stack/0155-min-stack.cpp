class MinStack {
public:
    stack< pair<int, int> > st;

    MinStack() {
        
    }
    
    void push(int val) {
        pair<int, int> p;
        if(st.empty()){
            st.push({val, val});
        }
        else{
            p.first = val;
            int prevMin = st.top().second;
            p.second = min(prevMin, val);
            st.push(p);
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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