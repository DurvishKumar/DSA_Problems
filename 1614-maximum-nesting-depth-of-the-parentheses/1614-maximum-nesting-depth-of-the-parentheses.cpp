class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int nesting_depth = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                count++;
                nesting_depth = max(nesting_depth,count);
            }
            else if(s[i] == ')') count --;
        }   
        return nesting_depth;     
    }
};