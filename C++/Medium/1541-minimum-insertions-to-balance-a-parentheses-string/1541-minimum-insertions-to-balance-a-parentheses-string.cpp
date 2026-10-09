class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        int i=0;

        while(i < n){
            if(s[i]== '('){
                cnt++;
                i++;
            }else{
                if(cnt > 0){
                    cnt--;
                }else{
                    ans++;
                }

                if(i+1 < n && s[i+1]==')')
                    i += 2;
                else{
                    ans++;
                    i++;
                }

            }
        }
        return ans + cnt * 2;
    }
};