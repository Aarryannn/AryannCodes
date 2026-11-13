class MinStack {
public:
stack <long long> st;
long long minVal;
    MinStack() {
        
    }
    
    void push(int v) {
        long long val = v;
        if(st.empty()){
            st.push(val);
            minVal = val;
        }else{
            if(val < minVal){
                st.push(2*val - minVal);
                minVal = val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() < minVal ){
            minVal = 2*minVal - st.top(); 
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < minVal) return minVal;
        return st.top();
        
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// pv = 2*mv - x;