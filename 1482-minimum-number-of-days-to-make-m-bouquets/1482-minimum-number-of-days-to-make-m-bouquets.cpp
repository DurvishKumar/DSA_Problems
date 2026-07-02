class Solution {
public:
    bool BouquetNo(vector<int>& bloomDay,int day, int m, int k){
        int cnt = 0;
        int bouquets = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<= day){
                cnt++;
            }
            else{
                bouquets+=cnt/k;
                cnt=0;
            }
        }
        bouquets+=cnt/k;
        if (bouquets>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        if((long long)m*k>bloomDay.size()) return ans;
        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high= *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            bool NoOfBouquets=  BouquetNo(bloomDay,mid,m,k);
            if (NoOfBouquets == true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};