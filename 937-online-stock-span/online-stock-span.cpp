class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index = index+1;
        // we have to find the index of previous greater element 
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        // ans will be the diffrence between current index and index of previous greater element
        int ans = index - (st.empty()? -1:st.top().second);
        st.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */