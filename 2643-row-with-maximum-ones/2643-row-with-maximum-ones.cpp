class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ind = -1;
        int maxcount = -1;
        for(int row = 0; row < m; row++){
            int countrows = 0;
            for(int col = 0; col < n; col++){
                countrows += mat[row][col];
            }
            if(countrows > maxcount){
                maxcount = countrows;
                ind = row;
            }
        }  
        return {ind,maxcount};      
    }
};