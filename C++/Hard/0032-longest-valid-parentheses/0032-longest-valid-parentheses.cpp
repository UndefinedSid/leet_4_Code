/*
// Two pass approach -> T.C (O(N)) & S.C (O(1))

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int left=0,right=0,maxi=0;

        for(int i=0;i<n;i++){
            if(s[i]== '(')
                left++;
             else
                right++;

            if(left==right)
                maxi=max(maxi, 2 * right);
            else if(right > left)
                left=right=0;

        }
           
        left=right=0;

        for(int j=n-1;j>=0;j--){
            if(s[j]== '(')
                left++;
            else
                right++;

            if(left==right)
                maxi=max(maxi,2 * left);
            else if(left > right)
                left=right=0;

        }

        return maxi;
    }
};

*/
//  Stack Approach --> T.C (O(N)) & S.C (O(N))

class Solution{
    public:
    int longestValidParentheses(string s){
        stack<int> st;
        int n=s.size();
        st.push(-1);
        int maxi=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    maxi=max(maxi,i-st.top());
            }
        }
        return maxi;

    }
};