class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int temp=n;

        while(temp > 0){
            int dgt=temp % 10;
            sum += dgt;
            prod *= dgt;
            temp /= 10;
        }

        int val = sum + prod;
        if(n % val==0)
            return true;
        else 
        return false;
    }
};