class Solution {
public:
    void helper(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int n){
        if(ind == n || target == 0){
            if(target == 0)
                ans.push_back(ds);
            return;
        }

        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            helper(ind, target-candidates[ind], candidates, ans, ds, n);
            ds.pop_back();
        }

        helper(ind+1, target, candidates, ans, ds, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
        
        helper(0, target, candidates, ans, ds, n);
        return ans;
    }
};