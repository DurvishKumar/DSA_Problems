class Solution {
public:
    void helper(int ind, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        helper(ind+1, ds, ans, nums);
        ds.pop_back();
        helper(ind+1, ds, ans, nums);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;

        helper(0, ds, ans, nums);

        return ans;
    }
};