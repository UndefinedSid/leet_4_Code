class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<int> matched(n+1,0);
        int cnt=0;
        int i=n-1,j =m-1;
        bool canChange=true;

        while(i >=0){
            if(j >=0 && word1[i]==word2[j]){
                cnt++;
                j--;
            }
            matched[i]=cnt;
            i--;
        }

        vector<int> ans;
        int y=0;
        for(int x=0;x<n && y < m;x++){
            int haveSuffix=(x+1 < n) ? matched[x+1] : 0;
            if(word1[x]==word2[y]){
                ans.push_back(x);
                y++;
            }
            else if(canChange==true && haveSuffix >= m-y-1){
                canChange=false;
                ans.push_back(x);
                y++;
            }
        }

        if(y==m)  
             return ans;
        else
            return {};
    }
};