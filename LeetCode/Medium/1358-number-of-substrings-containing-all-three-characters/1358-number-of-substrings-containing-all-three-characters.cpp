class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0;
        int cnt=0;
        int right=0;
        vector<int> freq(3,0);

        for(right=0;right<n;right++){
            freq[s[right] -'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] >0){
                cnt += n-right;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return cnt;
    }
};