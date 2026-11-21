class Solution {
public:
    int n;
    unordered_map<int,vector<int>> adj;
    vector<int> last;
    vector<int> ans;

    void dfs(int currNode,string& s,vector<int>& parent){
        int ch=s[currNode] -'a';
        int nearAncest=last[ch];
        last[ch]=currNode;

        for(int child : adj[currNode]){
            dfs(child,s,parent);
        }

        last[ch]=nearAncest;

         if(currNode != 0) {
            int newParent = parent[currNode]; 

            if(nearAncest != -1) {
                newParent = nearAncest;
            }

            parent[currNode] = newParent;

            ans[newParent] += ans[currNode];
        }

    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n=parent.size();

        ans.assign(n,1);
        last.assign(26,-1);

        for(int i=1;i<n;i++){
            int u=parent[i];
            int v=i;
            adj[u].push_back(v);
        }

        dfs(0,s,parent);
        return ans;
    }
};