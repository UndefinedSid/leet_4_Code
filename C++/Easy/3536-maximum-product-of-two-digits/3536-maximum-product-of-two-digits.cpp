class Solution {
public:
    int maxProduct(int n) {
        /*  // brute force approach -> O(d^2)

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

        */

        /* 
        // less code approach->O(d log d)

        string str=to_string(n);

        sort(str.rbegin(),str.rend());

        int ans=(str[0]-'0') * (str[1]-'0');
        return ans;

        */

        // optimal approach -> O(d)

        int maxi=0;
        int maxi2=0;

        while(n > 0){
            int dgt=n % 10;
            if(dgt > maxi){
                maxi2=maxi;
                maxi=dgt;
            }else if(dgt > maxi2)
                maxi2=dgt;

            n /= 10;
        }
        return maxi * maxi2;
    }
};