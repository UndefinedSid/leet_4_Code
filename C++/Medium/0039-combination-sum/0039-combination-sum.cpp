class Solution {
public:
    // vector<vector<int>> ans;
    int n;

    void backtrack(vector<int>& candidates,int target,vector<int>& temp,int idx,vector<vector<int>>& ans){
        if(target < 0)
            return ;

        if(target==0){
            ans.push_back(temp);
            return;

        }

        for(int i=idx;i<n;i++){
            if(i > idx && candidates[i]==candidates[i-1])
                continue;

            temp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],temp,i,ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,temp,0,ans);
        return ans;
    }
};