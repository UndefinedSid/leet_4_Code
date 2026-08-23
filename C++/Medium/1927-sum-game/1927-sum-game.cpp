class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int cntL=0,cntR=0;
        int lhs=0,rhs=0;

        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                cntL++;
            }
            else{
                lhs += (num[i]-'0');
            }
        }

        for(int j=n/2;j<n;j++){
            if(num[j]=='?')
                cntR++;
            else
                rhs += (num[j]-'0');
        }

        if((cntL + cntR)==0 && lhs==rhs)
            return false;
        else if((cntL + cntR) % 2 != 0){
            return true;
        }
        else{
            int sumDiff=lhs-rhs;
            int quesDiff=(cntR-cntL) * 4.5;
            if(sumDiff != quesDiff)
                return true;
            else return false;
        }
        return true;
    }
};