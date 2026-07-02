class Solution {
public:
    int maxele(vector<int>& piles){
        int largest=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]>largest) largest=piles[i];
        }
        return largest;
    }
    long long totalhours(vector<int>& piles, int mid){
        long long totalhrs=0;
        for(int i=0; i<piles.size(); i++){
            totalhrs += (piles[i]+mid-1)/mid;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxele(piles);
        int ans=1;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long total_hrs=totalhours(piles,mid);
            if(total_hrs<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};