class Solution {
public:
    int digitProduct(int n){
        int product = 1;
        while(n>0){
            int last = n%10;
            product = product*last;
            n = n/10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(n){
            int num = digitProduct(n);
            if(num % t == 0) break;
            n = n+1;
        }
        return n;
    }
};