class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        int ans=0;
        vector<int> freq(60,0);
        
        for(int t: time){
            int rem= t % 60;
            int comp=(60 - rem) % 60;

            ans += freq[comp];

            freq[rem]++;
        }
        return ans;
    }
};