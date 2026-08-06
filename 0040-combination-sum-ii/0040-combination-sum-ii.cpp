class Solution {
public:
    void helper(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int n){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < n; i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, ans, ds, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, ans, ds, n);

        return ans;
    }
};