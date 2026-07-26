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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxRectangle = 0;
        vector<vector<int>> preSum(n, vector<int>(m));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0')sum = 0;
                preSum[i][j] = sum;
            }
        }
        for(int i = 0; i < n; i++){
            maxRectangle = max(maxRectangle , largestRectangleArea(preSum[i]));
        }
        return maxRectangle;
    }
};