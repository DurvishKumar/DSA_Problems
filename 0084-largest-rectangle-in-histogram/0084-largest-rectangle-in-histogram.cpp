class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int maxArea = 0;
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                nse[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea,(heights[i] * (nse[i] - pse[i] - 1)));
        }
        return maxArea;
    }
};