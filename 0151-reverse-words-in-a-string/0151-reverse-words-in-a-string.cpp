class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        reverse(s.begin(),s.end());
        while (!s.empty() && (s.front() == ' ' || s.back() == ' ')) {
            if (s.front() == ' ')
                s.erase(0, 1);
            else if (s.back() == ' ')
                s.erase(s.size() - 1, 1);
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ' && s[i-1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};