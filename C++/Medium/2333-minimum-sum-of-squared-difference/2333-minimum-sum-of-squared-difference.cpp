class Solution {
public:
    using ll=long long;

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        ll k=(ll)k1 + k2;

        vector<int> mp(100001,0);

        for(int i=0;i<n;i++){
            ll diff=abs(nums1[i]-nums2[i]);
            mp[diff]++;
        }

        for(int i=1e5;i>0 && k > 0;i--){
           int cntOps=min((ll)mp[i],k);
           mp[i] -= cntOps;
           mp[i-1] += cntOps;

           k -= cntOps;
        }

        ll ans=0;
        for(ll d=1;d<=1e5;d++){
            ans += (mp[d] * d * d);
        }
            
        return ans;
    }
};