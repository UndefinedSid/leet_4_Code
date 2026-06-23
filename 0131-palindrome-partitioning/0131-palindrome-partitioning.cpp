class Solution {
public:
    int n;

    bool isPalindrome(string& s,int l,int r){
        while(l < r){
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }

    void backTrack(string& s, int i, vector<string>& curr,vector<vector<string>>& ans){
        if(i==n){
            ans.push_back(curr);
            return ;
        }

        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));

                backTrack(s,j+1,curr,ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>> ans;
        vector<string> curr;

        backTrack(s,0,curr,ans);
        return ans;
    }
};