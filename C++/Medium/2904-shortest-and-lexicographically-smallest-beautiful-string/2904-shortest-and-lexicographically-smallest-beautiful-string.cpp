class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;

        vector<string> ans;
        while (i < n) {
            int j = i;
            int ones = 0;
            while (j < n) {
                if (s[j] == '1') {
                    ones++;
                }
                if (ones == k) {
                    ans.push_back(s.substr(i,j-i+1));
                    break;
                }
                j++;
            }
            i++;
        }

        if(ans.empty())
            return "";

        sort(ans.begin(), ans.end(),[](const string& a,const string& b){
            if(a.size() != b.size())
                return a.size() < b.size();

            return a < b;
        });
        return ans[0];
    }
};