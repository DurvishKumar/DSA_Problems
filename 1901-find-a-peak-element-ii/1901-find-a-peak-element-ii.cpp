class Solution {
public:
    int maxElementRow(vector<vector<int>>mat, int n, int col){
        int maxele = -1;
        int maxEle_row = -1;
        for(int row = 0; row < n; row++){
            if(mat[row][col] > maxele){
                maxele = mat[row][col];
                maxEle_row = row;
            }
        }
        return maxEle_row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int row = maxElementRow(mat,n,mid);
            int left = mid - 1 >=0 ? mat[row][mid-1] : -1;
            int right = mid + 1 < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right) return {row,mid};
            else if (mat[row][mid] < left) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};