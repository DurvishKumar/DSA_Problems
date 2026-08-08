class Solution {
public:
    void possibleCombinations(int ind, string digits, string s, vector<string>& ans, vector<string>& combos){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }

        int digit = digits[ind] - '0';
        for(int i = 0; i < combos[digit].size(); i++){
            possibleCombinations(ind+1, digits, s + combos[digit][i], ans, combos);
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        string s;
        vector<string>ans;
        vector<string>combos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        possibleCombinations(0, digits, s, ans, combos);

        return ans;
    }
}; 