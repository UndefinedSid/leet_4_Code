class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        if(k==n)
            return maxi;

        unordered_map<int,int> mp;

        for(int i=0;i<=n-k;i++){
            unordered_set<int> st;
            for(int j=i;j<i+k;j++){
              st.insert(nums[j]);
            }

            for(int val : st){
                mp[val]++;
            }
        }

        vector<pair<int,int>> vecMp(mp.begin(),mp.end());

        sort(vecMp.begin(),vecMp.end(),[](auto& a,auto& b){
            return a.first > b.first;
        });


        for(auto& p : vecMp){
            if(p.second==1){
                return p.first;
            }
        }      
       
        return -1;
    }
};