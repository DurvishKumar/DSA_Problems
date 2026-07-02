class Solution {
public:
    long long check_value(vector<int>& nums, int mid){
        long long value =0;
        for(int i=0; i<nums.size(); i++){
            value+=(nums[i]+mid-1)/mid;
        }
        return value;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(threshold<nums.size()) return -1;
        int ans=INT_MAX;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check_value(nums,mid) <= threshold){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};