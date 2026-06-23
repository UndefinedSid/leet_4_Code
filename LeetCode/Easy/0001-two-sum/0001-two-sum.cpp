class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            
            int val=nums[i];
            int compliment=target-val;

            if(mp.find(compliment) != mp.end() && mp[compliment]!= i)
                return {i,mp[compliment]};

            mp[val]=i;
        }
        return {};
    }
};