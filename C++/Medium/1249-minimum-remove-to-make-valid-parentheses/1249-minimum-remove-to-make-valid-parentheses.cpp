class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();

        int open=0,close=0;
        string temp="";

        for(int i=0;i<n;i++){
            if(s[i]== '(' ){
                open++;
                temp += s[i];
            }
            else if(s[i]== ')'){
                if(open > 0){
                    open--;
                    temp += s[i];
                }
                    
            }else{
                temp += s[i];
            }

        }
        string ans="";

        for(int j=temp.size()-1;j>=0;j--){
            char ch= temp[j];
            if(ch== ')'){
                close++;
                ans += ch;
            }                                                        
            else if(ch == '('){
                if(close > 0){
                    close--;
                    ans += ch;

                }
            }else
                ans += ch;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};