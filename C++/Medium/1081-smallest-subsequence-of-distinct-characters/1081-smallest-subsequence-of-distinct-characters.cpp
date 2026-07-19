class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int> lastIdx(26);
        vector<bool> seen(26,false);

        for(int i=0;i<n;i++){
            int val=s[i] - 'a';
            lastIdx[val]=i;
        }

        string ans;
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']==true)
                continue;

            while(!ans.empty() && ans.back() > s[i] && lastIdx[ans.back()-'a'] > i){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;
        }
        return ans;
    }
};