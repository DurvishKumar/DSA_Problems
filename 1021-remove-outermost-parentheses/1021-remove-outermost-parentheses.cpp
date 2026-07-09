class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        int j = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if (level > 0){
                    s[j]= s[i];
                    j++;
                }
                level++;
            }
            else if(s[i] == ')'){
                level--;  
                if (level > 0){
                    s[j]= s[i];
                    j++;
                }
            }

        }
        s.erase(j);
        return s;
    }
};