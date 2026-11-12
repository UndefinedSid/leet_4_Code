class Solution {
public:
    int n;
    void backFinder(vector<int>& nums,vector<int>& temp,vector<bool>& used, vector<vector<int>>& ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i])
                continue;

            if(i > 0 && nums[i]==nums[i-1] && used[i-1]==false){
                continue;
            }

            used[i]=true;
            temp.push_back(nums[i]);

            backFinder(nums,temp,used,ans);
            temp.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<bool> used(n,false);

        backFinder(nums,temp,used,ans);

        return ans;

    }
};