class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int> lastIdx(26);
        vector<bool> seen(26,false);
        string ans="";

        for(int i=0;i<n;i++){
            char ch=s[i];
            lastIdx[ch-'a']=i;
        }

        for(int i=0;i<n;i++){

            if(seen[s[i]-'a'])
                continue;

            while(! ans.empty() && ans.back() > s[i] && lastIdx[ans.back() -'a'] > i ){
                seen[ans.back() -'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            seen[s[i]-'a']=true;

        }
        return ans;
    }
};