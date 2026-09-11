class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int evenCnt=0;
        int ans=0;
        vector<int> freq(10,0);
        for(int val : digits){
            if(val % 2 ==0)
                evenCnt++;
           
            freq[val]++;
        }
        if(evenCnt == 0)
            return 0;
        else{
            for(int i=100;i<999;i+=2){
                int dgt= i % 10;
                int tens= (i / 10) % 10;
                int hund= i / 100;

                vector<int> need(10,0);
                need[hund]++;
                need[tens]++;
                need[dgt]++;

                bool poss=true;
                for(int d=0;d<10;d++){
                    if(freq[d] < need[d]){
                        poss=false;
                        break;
                    }
                }

                if(poss)
                    ans++;
            }
            return ans;
        }

    }
};