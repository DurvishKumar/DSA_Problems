class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count ++;
                if(count == 1) continue;
                else ans += s[i];
            }
            else if(s[i] == ')'){
                count--;
                if(count == 0) continue;
                else ans += s[i];
            }

        }
        return ans;
    }
};