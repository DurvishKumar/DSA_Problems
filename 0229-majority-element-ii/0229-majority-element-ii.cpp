class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int count1=0, count2=0;
        int element1=0,element2=0;
        for(int i=0; i<n; i++){
            if(count1==0 && nums[i]!=element2){
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && nums[i]!=element1){
                count2=1;
                element2=nums[i];
            }
            else if (nums[i]==element1) count1++;
            else if (nums[i]==element2) count2++;
            else count1--, count2--;
        }
        count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==element1) count1++;
            else if(nums[i]==element2) count2++;
        }
        int mini=(int)(n/3)+1;
        if(count1>=mini) ans.push_back(element1);
        if(count2>=mini) ans.push_back(element2);
        return ans;
        
    }
};