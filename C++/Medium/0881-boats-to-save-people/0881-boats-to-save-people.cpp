class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int ans=0;

        int st=0;
        int end=n-1;
        while(st <= end){
            if(people[st] + people[end] <= limit){
                st++;
            }
            end--;
            ans++;
        }
        return ans;
    }
};