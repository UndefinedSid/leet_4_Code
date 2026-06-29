class Solution {
public:

    // brute force approach fo smaller n
    
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto& pat : patterns){
            if(word.find(pat) != string::npos){
                ans++;
            }
        }
        return ans;
    }

    /*.  // KMP algo for higher n=10^5 constraint

    vector<int> computeLPS(const string& pat){
        int m=pat.size();
        vector<int> lps(m,0);

        int len=0;
        int i=1;
        while(i < m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else if(len !=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
        return lps;
    }

    bool kmpSearch(const string& words,const string& pat){
        int n=words.size();
        int m=pat.size();
        if(m > n)
            return false;

        vector<int> lps=computeLPS(pat);

        int i=0,j=0;
        while(i < n){
            if(pat[j]==words[j]){
                i++;
                j++;
            }

            if(j==m)
                return true;

            else if(i < n && pat[j] != words[i]){
                if(j != 0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return false;
        
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto& pat : patterns){
            if(word.find(pat) != string::npos){
                if(kmpSearch(word,pat))
                    ans++;
            }
        }
        return ans;
    }

    */

};