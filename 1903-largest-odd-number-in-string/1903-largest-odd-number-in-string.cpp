class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1;
        while(i>=0){
            if((num[i]-'0')%2==1){
                break;
            }
            else{
                num.erase(i,1);
                i--;
            }
        }
        return num;
    }
};