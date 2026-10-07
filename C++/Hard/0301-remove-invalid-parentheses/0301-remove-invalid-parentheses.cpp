class Solution {
public:
    unordered_set<string> st;
    int maxi,n;

    void backtrack(string& s,int idx,string& curr,int count){

        if(count < 0)
            return;

        if(idx==n){
            if(count==0){
                if(curr.size() > maxi){
                    maxi=curr.size();
                    st.clear();
                }

                if(curr.size()==maxi){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[idx] != '(' && s[idx] != ')'){
            curr.push_back(s[idx]);
            backtrack(s,idx+1,curr,count);
            curr.pop_back();
            return;
        }

        curr.push_back(s[idx]);

        backtrack(s,idx+1,curr,count + (s[idx]== '(' ? 1 : -1 ));

        curr.pop_back();

        backtrack(s,idx+1,curr,count);
    
    }

    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        st.clear();

        maxi=0;
        string curr="";

        backtrack(s,0,curr,0);

        return vector<string>(st.begin(),st.end());
    }
};