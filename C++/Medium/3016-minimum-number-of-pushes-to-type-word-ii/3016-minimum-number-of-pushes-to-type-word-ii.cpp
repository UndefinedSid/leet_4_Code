class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> freq(26,0);
        for(auto& ch : word){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int ans=0;

        for(int i=0;i<26;i++){
            if(freq[i]==0)
                break;

            int temp=(i / 8) + 1;
            ans += freq[i] * temp;
        }
        return ans;
    }
};