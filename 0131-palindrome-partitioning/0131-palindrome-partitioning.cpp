class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        int i = start;
        int j = end;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void partitioning(string s, int ind, vector<string>& ds, vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i+1-ind));
                partitioning(s, i+1, ds, ans);
                ds.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;

        partitioning(s, 0, ds, ans);

        return ans;
        
    }
};