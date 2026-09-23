class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        // if (nums[0] > x && nums[n - 1] > x)
        //     return -1;

        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            mp[sum]=i;
        }

        if(sum < x)
            return -1;

        int rem=sum - x;
        int ans=INT_MIN;

        sum=0;

        for(int j=0;j<n;j++){
            sum += nums[j];
            int findSum = sum -rem;
            if(mp.find(findSum) != mp.end()){
                int idx=mp[findSum];
                ans=max(ans,j-idx);
            }

        }

        if(ans==INT_MIN)
            return -1;
        
        return n - ans;
    }
};