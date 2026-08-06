class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+10;i++){
            int temp=i;
            long long prod=1;
            while(temp > 0){
                int dgt=temp % 10;
                if(dgt==0){
                    prod=0;
                    return i;
                }
                prod *= dgt; 
                temp /= 10; 
            }
            if(prod % t==0)
                return i;
        }
        return 0;
    }
};