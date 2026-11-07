class Solution {
public:
    using ll=long long;
    using P=pair<int,int>;
    using tup=tuple<ll,int,int>;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue<P,vector<P>,greater<P>> freeServ;
        priority_queue<tup,vector<tup>,greater<tup>> busyServ;

        for(int i=0;i<n;i++)
            freeServ.push({servers[i],i});

        vector<int> ans(m);

        for(int i=0;i<m;i++){
            while(! busyServ.empty() && get<0>(busyServ.top()) <= i){
                auto [waitTm,wt,idx]=busyServ.top();
                busyServ.pop();
                freeServ.push({wt,idx});
            }

            if(freeServ.empty()){
                auto[finishTm,wt,idx]=busyServ.top();
                busyServ.pop();
                ans[i]=idx;
                busyServ.push({finishTm + tasks[i],wt,idx});

            }else{
                auto[wt,idx]=freeServ.top();
                freeServ.pop();
                ans[i]=idx;
                busyServ.push({i + tasks[i],wt,idx});
            }
        }
        return ans;

    }
};