class Solution {
public:
    using ll=long long;

    double finder(double x,ll n){
        if(n==0)
            return 1.0;

        double half=finder(x,n/2);

        if(n % 2==0)
            return half * half;
        else{
            if(n >0)
                return half * half * x;
            else
                return half * half * (1.0 / x);
        }
    }

    double myPow(double x, int n) {
        ll N=n;
          return finder(x,N);  
    }
};