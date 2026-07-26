class StockSpanner {
    int ind;
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        ind = -1;
        while(!st.empty()) st.pop();
    }
    
    int next(int price) {
        ind = ind+1;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = ind - ((!st.empty())? st.top().second : -1);
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */