class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        if(n < 9)
            ans= n;
        else if( n < 17 ){
            int extra=n-8;
            ans= 8 + 2 * extra;
        }else if( n < 25){
            int extra=n-16;
            ans = 24 + 3 * extra;
        }
        else{
            int extra=n-24;
            ans = 48 + 4 * extra;
        }
        return ans;
    }
};