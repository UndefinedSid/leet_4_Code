class Solution {
public:
    int n;

    void backtrack(vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int> temp,int idx){
        if(target < 0)
            return;

        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i > idx && candidates[i]==candidates[i-1])
                continue;

            temp.push_back(candidates[i]);
            backtrack(candidates,target - candidates[i],ans,temp,i+1);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());

        backtrack(candidates,target,ans,temp,0);

        return ans;

    }
};