class Solution {
public:
    void helper(int ind, vector<int>& ds, set<vector<int>>& st, vector<int>& nums){
        if(ind == nums.size()){
            st.insert(ds);
            return;
        }

        ds.push_back(nums[ind]);
        helper(ind+1, ds, st, nums);
        ds.pop_back();
        helper(ind+1, ds, st, nums);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        vector<int>ds;
        vector<vector<int>>ans;
        helper(0, ds, st, nums);
        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
        
    }
};