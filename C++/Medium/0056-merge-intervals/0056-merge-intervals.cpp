class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        // vector<int> temp;

        for(auto vec : intervals){
            if(ans.empty() || ans.back()[1] < vec[0])
                ans.push_back(vec);
            else{
                ans.back()[1]=max(ans.back()[1],vec[1]);
            }
        }

        return ans;
    }
};