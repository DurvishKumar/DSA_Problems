class Solution {
public:
    int countdays(vector<int>& weights, int capacity){
        int count=1;
        long long sum=0;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum>capacity){
                count++;
                sum = weights[i];
            }
        }
        return count;
    }
    long long sum_of_array(vector<int>& weights){
        long long sum=0;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 1;
        long long low = *max_element(weights.begin(), weights.end());
        long long high = sum_of_array(weights);
        while (low<=high){
            long long mid = low + ( high - low ) / 2;
            int CountDays = countdays(weights, mid);
            if(CountDays <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return  ans;
    }
};