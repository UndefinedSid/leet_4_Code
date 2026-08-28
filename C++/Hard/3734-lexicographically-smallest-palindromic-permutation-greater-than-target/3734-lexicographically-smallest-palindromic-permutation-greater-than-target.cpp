class Solution {
public:

    char midChar='@';
    int halfLen=0;
    string ans="";

    bool finder(string& curr,string& target,vector<int>& freq,int idx,bool found){
        if(idx ==halfLen){
            string possibleAns=curr;
            string rightHalf=possibleAns;
            reverse(rightHalf.begin(),rightHalf.end());

            if(midChar != '@')
                possibleAns += midChar;

            possibleAns += rightHalf;

            if(possibleAns > target){
                ans = possibleAns;
                return true;
            }
            return false;
        }

        for(char ch='a';ch <='z';ch++){
            if(freq[ch-'a']==0)
                continue;

            if(!found && ch < target[idx])
                continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isFound=found || ch > target[idx];

            if(finder(curr,target,freq,idx+1,isFound))
                return true;

            curr.pop_back();
            freq[ch-'a']++;

            // if(ans != "")
            //     break;

        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26,0);
        for(char ch : s)
            freq[ch-'a']++;

        int oddFreq=0;
        for(int i=0;i<26;i++){
            if(freq[i] % 2 == 1){
                oddFreq++;
                midChar= i + 'a';
            }
        }

        if(oddFreq > 1)
            return "";

        string curr;
        vector<int> halfCnt(26,0);

        for(int ch=0;ch<26;ch++){
            halfCnt[ch] = freq[ch] / 2;
        }

        halfLen = n / 2;

        finder(curr,target,halfCnt,0,false);

        return ans;

    }
};