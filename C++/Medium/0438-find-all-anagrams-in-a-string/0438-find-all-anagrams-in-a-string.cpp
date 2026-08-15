class Solution {
public:
    bool finder(vector<int>& freq){
        for(int val : freq){
            if(val != 0){
                return false;
                break;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int sSize=s.size();
        int pSize=p.size();

        vector<int> ans;
        vector<int> freq(26,0);

        for(auto ch : p){
            freq[ch-'a']++;
        }

        int i=0,j=0;

        while(j < sSize){
            freq[s[j]-'a']--;
            if(j-i+1==pSize){
                if(finder(freq))
                    ans.push_back(i);

                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};