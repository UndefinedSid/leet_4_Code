class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }

        int prev=10;
        int aTurn=0;
        while(n >= prev){
            if(n >= prev){
                n -= prev;
                aTurn++;
                prev--;
            }
        }
        if(aTurn % 2 == 0)
            return false;
        else
            return true;
    }
};