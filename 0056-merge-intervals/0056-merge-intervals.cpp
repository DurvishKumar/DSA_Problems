class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        for(int i=0;i<n; i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(ans.empty() || ans.back()[1]<start) ans.push_back(intervals[i]);
            else{
                ans.back()[1]=max(end,ans.back()[1]);
            }
        }
        return ans;
    }
};