class Solution {
public:
    int n;
    bool finder(int i,int j,string& str){
        while(i < j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(int x) {
        string str=to_string(x);
        n=str.size();
        if(x  < 0)
            return false;
        else{
           return finder(0,n-1,str);
        }

        return true;
    }
};