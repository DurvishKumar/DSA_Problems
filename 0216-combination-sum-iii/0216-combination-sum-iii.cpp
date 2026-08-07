class Solution {
public:
    void validCombinations(int num, vector<int>& ds, vector<vector<int>>& ans, int k, int n){
        if(k == 0){
            if(n == 0) ans.push_back(ds);
            return;
        }
        
        if(num > 9 || n < 0 || k < 0) return;
        if (num > n) return;
        
        ds.push_back(num);
        validCombinations(num+1, ds, ans, k-1, n-num);
        ds.pop_back();
        
        validCombinations(num+1, ds, ans, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        validCombinations(1, ds, ans, k, n);

        return ans;
    }
};