class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<prefix.size();j++){
                if(prefix[j] == strs[i][j]) continue;
                else {
                    prefix.erase(j);
                }
            }
            
        }
        return prefix;
    }
};