class Solution {
public:
    using p=pair<int,char>;

    string reorganizeString(string s) {
        int n=s.size();
        vector<int> freq(26,0);

        for(char ch : s){
            freq[ch-'a']++;

            if(freq[ch-'a'] > (n+1) / 2)
                return "";
        }

        string ans="";

        priority_queue<p,vector<p>> pq;

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.push({freq[i],i + 'a'});
            }
        }

        while(pq.size() >=2){
            auto p1=pq.top();
            pq.pop();

            auto p2=pq.top();
            pq.pop();

            ans.push_back(p1.second);
            p1.first--;

            ans.push_back(p2.second);
            p2.first--;


            if(p1.first > 0)
                pq.push(p1);

            if(p2.first > 0)
                pq.push(p2);

        }

        if(! pq.empty())
            ans.push_back(pq.top().second);

        return ans;

    }
};