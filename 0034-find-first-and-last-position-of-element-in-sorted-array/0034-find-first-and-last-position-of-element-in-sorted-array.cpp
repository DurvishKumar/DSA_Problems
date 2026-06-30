class Solution {
public:
    int first_occur(vector<int>&nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans1=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans1=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans1;
    }
    int last_occur(vector<int>&nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans2=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ans2=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans2;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb= first_occur(nums,target);
        if(lb==n || nums[lb]!=target) return{-1,-1};
        return {lb,last_occur(nums,target)-1};
    }
};