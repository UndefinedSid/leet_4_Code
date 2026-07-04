class Solution {
public:

    void dfs(int u,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool>& visit,int& ans){
        visit[u]=true;

        for(auto& arr : adj[u]){
            int v=arr.first;
            int dist=arr.second;

            ans=min(ans,dist);

            if(!visit[v])
                dfs(v,adj,visit,ans);

        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        // sort(roads.begin(),roads.end(), [](const vector<int>& r1,const vector<int>& r2){
        //     return r1[2] < r2[2];
        // });
        // int dist=roads[0][2];
        // return dist;

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& arr : roads){
            int u=arr[0];
            int v=arr[1];
            int dist=arr[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});

        }

        vector<bool> visit(n,false);
        int ans=INT_MAX;
        dfs(1,adj,visit,ans);

        return ans;

    }
};