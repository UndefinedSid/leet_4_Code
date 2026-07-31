class Solution {
public:
    int n;
    bool finder(string &s,int i,int j,bool flag){
        while(i < j){
            if(s[i]!= s[j]){
                if(flag)
                    return false;
                     
               return finder(s,i+1,j,true) || finder(s,i,j-1,true);
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        n=s.size();
        return finder(s,0,n-1,false);
    }
};