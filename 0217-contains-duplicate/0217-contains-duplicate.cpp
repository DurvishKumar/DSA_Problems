class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                count=1;
                break;
            }
        }
        if(count==0) return false;
        else return true;
        
    }
};