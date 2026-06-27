class Solution {
public:
    using ll=long long;

    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        // sort(nums.rbegin(),nums.rend());
        if(n==1)
            return 1;

        map<ll,int> mp;
        for(int val : nums){
            mp[val]++;
        }
        int ans=0,temp=0;

        if(mp.count(1)){
            temp=mp[1];
            ans=(temp % 2==0) ? temp-1 : temp;
        }

        for(auto& [val,cnt] : mp){
            if(val > 1 && cnt > 1){
                ll curr=val;
                int len=0;
                while(mp.count(curr) && mp[curr] >=2){
                    len +=2;
                    curr=curr * curr;
                }

                if(mp.count(curr) && mp[curr]>=1)
                    len++;
                else
                    len--;
        
                ans=max(ans,len);
            }
        }
        return max(ans,1);
    }
};