class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=INT_MIN;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int dist = j-i;
            int area = dist * (min(height[i],height[j]));
            maxwater = max(area,maxwater);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxwater;
        
    }
};