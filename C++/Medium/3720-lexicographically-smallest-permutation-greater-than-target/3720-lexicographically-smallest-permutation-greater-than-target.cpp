class Solution {
public:
    string ans="";

    bool finder(string& curr,vector<int>& freq,string& target,int idx,bool found){
        if(idx==target.size()){
            if(found){
                ans =curr;
                return true;
            }
            return false;
        }

        for(char c='a';c <='z';c++){
            if(freq[c-'a']==0)
                continue;

            if(found==false && c < target[idx])
                continue;

            curr.push_back(c);
            freq[c-'a']--;

            bool isFound=found || c > target[idx];

            if(finder(curr,freq,target,idx+1,isFound))
                return true;

            curr.pop_back();
            freq[c-'a']++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26,0);
        for(char ch : s)
            freq[ch-'a']++;

        string curr;

        finder(curr,freq,target,0,false);

        return ans;
    }
};