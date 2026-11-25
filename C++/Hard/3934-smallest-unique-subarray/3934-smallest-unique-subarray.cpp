class Solution {
public:
    using ll=long long;
    int MOD=1e9+7; 
    int n;

    ll powFinder(ll a,int base){
        if(base==0)
            return 1;

        ll half=powFinder(a,base / 2);
        ll res=half * half % MOD;

        if(base % 2==1){
            res=(res * a) % MOD;
        }
        return res;
    }

    bool check(vector<int>& nums,int mid,int base){
        n=nums.size();
        ll hash=0;
        unordered_map<ll,int> mp;
        ll p = powFinder(base, mid-1); 

        int i=0,j=0;
        while(j < n){
            hash = (hash * base + nums[j]) % MOD;
            if(j-i+1 < mid)
                j++;
            else{
                mp[hash]++;
                hash = (hash - (p * nums[i]) % MOD + MOD) % MOD;
                i++;
                j++;
            }
        }

        for(auto& it : mp){
            if(it.second==1)
                return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        n=nums.size();
        int base=*max_element(nums.begin(),nums.end()) + 1;

        int l=1,r=n;
        int ans=n;

        while(l <= r){
            int mid=l + (r-l) / 2;
            if(check(nums,mid,base)){
                ans=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};