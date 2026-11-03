class Solution {
public:
    int n;
    void finder(vector<int>& nums,int idx,vector<int> vec,vector<vector<int>>& ans){
        ans.push_back(vec);

        for(int i=idx;i<n;i++){
            vec.push_back(nums[i]);
            finder(nums,i+1,vec,ans);

            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        n=nums.size();

        vector<int> vec;

        finder(nums,0,vec,ans);

        return ans;
    }
};