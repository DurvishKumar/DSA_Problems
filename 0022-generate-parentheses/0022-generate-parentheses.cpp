class Solution {
public:
    void validCombos(int ind, int n, string s, vector<string>& ds, int countOfOpenPara, int countOfClosePara){
        if(ind == 2*n){
            if(countOfOpenPara == n && countOfClosePara == n) ds.push_back(s);
            return;
        }
        
        if(countOfOpenPara < n)
        validCombos(ind+1, n, s + '(' , ds, countOfOpenPara + 1, countOfClosePara);

        if(countOfClosePara < countOfOpenPara)
        validCombos(ind+1, n, s + ')' , ds,countOfOpenPara, countOfClosePara + 1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ds;
        string s;

        validCombos(0, n, s, ds, 0, 0);

        return ds;
        
    }
};