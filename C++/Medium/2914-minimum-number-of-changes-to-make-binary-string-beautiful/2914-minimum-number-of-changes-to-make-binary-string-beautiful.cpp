class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ones=0,zeros=0;

        vector<int> pref(n,0);
        pref[0]=s[0] - '0';
        if(pref[0]==0)
            zeros++;
        else
            ones++;

        for(int i=1;i<n;i++){
            int dgt=s[i] - '0';
            if(dgt==0)
                zeros++;
            else
                ones++;

            pref[i]=pref[i-1] + dgt;
        }

        int ans=0;
        
        if(ones==0 || zeros==0)
            return 0;
        else{
            for(int i=0;i<n;i+=2){
                if(s[i] != s[i+1])
                    ans++;
            }
        }
        return ans;
    }
};