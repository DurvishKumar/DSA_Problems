class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;
        vector<int>tempans(nums2.size(),-1);
        vector<int>ans(nums1.size(),-1);
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(!st.empty()) tempans[i] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            mpp.insert({nums2[i],tempans[i]});
        }
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};