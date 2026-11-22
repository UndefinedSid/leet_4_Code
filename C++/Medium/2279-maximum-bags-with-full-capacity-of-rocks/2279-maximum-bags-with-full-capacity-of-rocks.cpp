class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> need(n,0);

        for(int i=0;i<n;i++){
            int req=capacity[i]-rocks[i];
            need[i]=req;
        }
        int ans=0;

        sort(need.begin(),need.end());
        for(int i=0;i<n;i++){
            if(need[i] <= additionalRocks){
                additionalRocks -= need[i];
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};