class Solution {
public:
    bool isPossible(vector<int>& position,int force, int m){
        int ballsPlaced = 1;
        int lastball = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i]-lastball >= force){
                ballsPlaced++;
                lastball = position[i];
            }
            if(ballsPlaced >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1] - position[0];
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(isPossible(position, mid, m) == true) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};