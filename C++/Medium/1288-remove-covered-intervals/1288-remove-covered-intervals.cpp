class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0])
                return a[1] > b[1];
            else 
                return a[0] < b[0];
        });

        int ans=0;
        int endMax=0;
        for(auto& inter : intervals){
            if(inter[1] <= endMax){
                ans++;
                continue;
            }
            endMax=inter[1];
        } 
        return n-ans;
    }
};