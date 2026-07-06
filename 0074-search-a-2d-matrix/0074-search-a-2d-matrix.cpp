class Solution {
public:
    bool isPresent(vector<int> &matrix, int n, int target){
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid] == target) return true;
            else if(matrix[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int row = 0; row < m; row++){
            if(matrix[row][0] <= target && matrix[row][n-1] >= target){
                return isPresent(matrix[row], n, target);
            }
        }   
        return false;     
    }
};