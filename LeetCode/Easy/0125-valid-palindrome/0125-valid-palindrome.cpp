class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";
        for(char ch : s){
            if(isalnum(ch)){
                str += tolower(ch);
            }
        }

        cout << str ;

        int i=0,j=str.size()-1;
        while(i < j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};