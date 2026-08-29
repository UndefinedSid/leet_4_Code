class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int groupCnt = 0;
        unordered_map<int, int> numMap;
        numMap[arr[0]]=groupCnt;

        unordered_map<int, list<int>> groupNum;
        groupNum[groupCnt].push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) > limit) {
                groupCnt++;
            }
            
            numMap[arr[i]] = groupCnt;
            groupNum[groupCnt].push_back(arr[i]);
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int val=nums[i];
            int grp=numMap[val];

            ans[i]= *groupNum[grp].begin();
            groupNum[grp].pop_front();
        }

        return ans;
    }
};