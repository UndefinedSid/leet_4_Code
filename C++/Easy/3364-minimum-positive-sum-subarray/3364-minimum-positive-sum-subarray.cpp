class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();

        int ans=INT_MAX;
        vector<int> pref(n,0);
        pref[0]=nums[0];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1] + nums[i];
        }

        int j=l-1;
        for(int i=0;i<n;i++){
            for(int j=l;j<=r;j++){
                int st=i-j+1;
                if(st >= 0){
                    int sum=pref[i] - (st > 0 ? pref[st-1] : 0);
                    if(sum > 0)
                        ans=min(ans,sum);
                }
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};