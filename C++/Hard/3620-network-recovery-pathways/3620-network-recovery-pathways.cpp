class Solution {
public:
    using ll=long long;
    using P=pair<ll,int>;

    bool finder(int mid,int n,ll k,unordered_map<int,vector<vector<int>>>& adj){
        vector<ll> finalCost(n,LLONG_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        finalCost[0]=0;
        pq.push({0,0});
        while(! pq.empty()){
            ll dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(dist > k)
                return false;

            if(node==n-1)
                return true;

            if( finalCost[node] < dist)
                continue;

            for(auto& arr : adj[node]){
                int ngbr=arr[0];
                int cost=arr[1];

                if(cost < mid)
                    continue;

                if(dist + cost < finalCost[ngbr]){
                    finalCost[ngbr]=dist + cost;
                    pq.push({dist+ cost,ngbr});
                }
            }
        }
        return false;
    }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        unordered_map<int,vector<vector<int>>> adj;

        int l=INT_MAX, r=0;
        for(auto ed : edges){
            int u=ed[0];
            int v=ed[1];
            int cost=ed[2];

            if(! online[u] || ! online[v])
                continue;

            adj[u].push_back({v,cost});
            l=min(l,cost);
            r=max(r,cost);

        }
        int ans=-1;
        while(l <= r){
            int mid=l +(r-l) / 2;
            if(finder(mid,n,k,adj)){
                ans=mid;
                l=mid+1;
            }else
                r=mid-1;
        }
        return ans;
    }
};