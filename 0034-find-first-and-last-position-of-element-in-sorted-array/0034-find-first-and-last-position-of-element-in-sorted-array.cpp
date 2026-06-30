class Solution {
public:
    int first_occur(vector<int>&nums, int target){
        int first=-1;
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return first;
    }
    int last_occur(vector<int>&nums, int target){
        int last=-1;
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first= first_occur(nums,target);
        int last= last_occur(nums,target);
        if(first==-1) return{-1,-1};
        return {first,last};
    }
};