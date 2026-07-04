class Solution {
public:
    int countSubarrays(vector<int>& nums, long long maxsum) {
        int partitions = 1;
        long long sum=0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxsum){
                sum += nums[i];
            }
            else{
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    long long splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(),nums.end(), 0LL);
        while(low<=high){
            long long mid = low + (high - low) / 2;
            if(countSubarrays(nums,mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};