class Solution {
public:
    int maxProduct(int n) {
        string str=to_string(n);
        int maxi=INT_MIN;

        for(int i=0;i<str.size();i++){
            for(int j=i+1;j<str.size();j++){
                if(str[j]=='0' || str[i]=='0')
                    continue;

                maxi=max((str[i]-'0') * (str[j]-'0'),maxi);
            }
        }
        return (maxi==INT_MIN) ? 0 : maxi;
    }
};