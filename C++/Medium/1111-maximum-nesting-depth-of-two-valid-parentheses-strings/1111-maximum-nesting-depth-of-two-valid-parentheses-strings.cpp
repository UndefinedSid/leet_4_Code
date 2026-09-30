class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();

        vector<int> ans(n,0);
        int dep=0;

        for(int i=0;i<n;i++){
            char ch=seq[i];

            if(ch== '('){
                dep++;
                ans[i]=dep % 2;
            }else{
                ans[i]=dep % 2;
                dep--;
            }
        }
        return ans;
    }
};