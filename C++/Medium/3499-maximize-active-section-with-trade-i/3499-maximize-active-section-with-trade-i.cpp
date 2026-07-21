class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=count(s.begin(),s.end(),'1');
        vector<int> zeroSet;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                int st=i;
                while(s[i]=='0')
                    i++;

                zeroSet.push_back(i-st);
            }
        }
        int maxPair=0;

        for(int j=1;j<zeroSet.size();j++){
            maxPair=max(maxPair,zeroSet[j] + zeroSet[j-1]);
        }
        int ans=maxPair + ones;
        return ans;   
    }
};