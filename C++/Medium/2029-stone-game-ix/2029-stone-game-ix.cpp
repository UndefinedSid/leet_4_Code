class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>rem(3,0);

        for(int st : stones){
           rem[st % 3]++;
        }

        if(rem[0] % 2==0){
            if(rem[1] >= 1 && rem[2] >=1)
                return true;
            else
                return false;
        }else{
            if(abs(rem[1]-rem[2]) > 2)
                return true;
            else
                return false;
        }
        
    }
};