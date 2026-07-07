class Solution {
public:
    using ll=long long;

    long long sumAndMultiply(int n) {
        ll sum=0;
        ll ans=0;
        string str=to_string(n);
        for(char ch : str){
            int digit=ch - '0';
            if(digit==0)
                continue;
            ans=ans * 10 +digit;
            sum += digit;
            
        }
        return ans * sum;
    }
};