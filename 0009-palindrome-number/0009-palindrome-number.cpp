class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long original = x;
        long long reversenumber=0;
        while(x>0){
            long long lastdigit = x%10;
            x=x/10;
            reversenumber=(reversenumber*10)+lastdigit;
        }
        if(reversenumber==original) return true;
        return false;
    }
};