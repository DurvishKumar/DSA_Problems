class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto ch : s){
            freq[ch]++;
        }
        vector<string>bucket(s.size()+1);
        for(auto it : freq){
            bucket[it.second] += it.first;
        }
        string ans;
        for(int i = bucket.size()-1; i>0; i--){
            for(int j=0; j<bucket[i].size(); j++){
                ans.append(i, bucket[i][j]);
            }
        }
        return ans;

    }
};