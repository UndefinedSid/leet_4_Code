class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;

        string ans="";

        for(char ch : s){
            if(ch=='('){
                st.push(ans.size());
            }else if(ch== ')'){
                int start=st.top();
                st.pop();
                reverse(ans.begin() + start, ans.end());
            }else{
                ans += ch;
            }
        }
        return ans;
    }
};