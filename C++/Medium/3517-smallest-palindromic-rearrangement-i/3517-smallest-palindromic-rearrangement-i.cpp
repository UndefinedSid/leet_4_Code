class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        int n=s.size();
        string st="";
        string mid="";


        for(int i=0;i<n;){
            if(i+1<n && s[i]==s[i+1]){
                st += s[i];
                i+=2;
            }else{
                mid += s[i];
                i++;
            }

        }
        string end=st;
        reverse(end.begin(),end.end());
        string ans=st + mid + end;

        return ans;
    }
};