class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[n-1];
        vector<int> ans;

        for(int i=mini;i<=maxi;i++){
            if(! binary_search(nums.begin(),nums.end(),i))
                ans.push_back(i);
        }
        return ans;
    }
};