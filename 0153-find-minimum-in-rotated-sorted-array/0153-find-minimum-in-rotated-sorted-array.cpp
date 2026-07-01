class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini=INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[low]<=nums[high]){
                mini = min(nums[low],mini);
                break;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<mini) mini=nums[low];
                low=mid+1;
            }
            else{
                if(nums[mid]<mini) mini=nums[mid];
                high=mid-1;
            }
        }
        return mini;
    }
};