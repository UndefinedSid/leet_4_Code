class Solution {
public:
    using ll=long long;

    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.rbegin(),maximumHeight.rend());
        ll ans=0;
        ll prev=LLONG_MAX;

        for(int i=0;i<n;i++){
            ll val=min((ll)maximumHeight[i],prev-1);

            if(val <=0)
                return -1;

            ans += val;
            prev=val;
           
        }
        return ans;

    }
};