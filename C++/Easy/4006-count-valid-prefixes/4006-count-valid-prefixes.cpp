class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        vector<int> freq(n,0);
        if(s[0]=='1')
            freq[0]=1;
        else
            freq[0]=-1;

        int ans=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                freq[i]= freq[i-1] + 1;
            }
            else
                freq[i]= freq[i-1] -1;

            if(freq[i]==-1 || freq[i]==1 || freq[i]==0){
                ans++;
            }
        }
        return ans;
    }
};