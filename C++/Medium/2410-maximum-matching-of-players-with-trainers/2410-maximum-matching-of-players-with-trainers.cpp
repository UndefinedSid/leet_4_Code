class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        
        int ans=0;
        int n=players.size();
        int m=trainers.size();

        int i=0,j=0;
        while(i < n && j < m){
            if(players[i]  <= trainers[j]){
                ans++;
                i++;j++;
            }else if(players[i] > trainers[j]){
                j++;
            }
        }
        return ans;
    }
};