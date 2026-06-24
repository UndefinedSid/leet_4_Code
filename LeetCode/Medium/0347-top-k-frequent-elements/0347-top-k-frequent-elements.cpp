class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int val : nums){
            mp[val]++;
        }

        vector<int> ans;
        vector<pair<int,int>> freq(mp.begin(),mp.end());

        sort(freq.begin(),freq.end(),[] (pair<int, int>& a,pair<int,int>& b){
            return a.second > b.second;
        });


       for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
       }
        return ans;
    }
};