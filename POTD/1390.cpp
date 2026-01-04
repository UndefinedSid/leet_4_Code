/*
PROBLEM --> 1390 (MEDIUM) -->> FOUR DIVISORS
TOPICS -->>  ARRAY, MATH

Given an integer array nums,
return the sum of divisors of the integers in that array
that have exactly four divisors. If there is no such integer in the array,
return 0.

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        
        for(int val : nums){
            vector<int> temp;
            int cnt=0;
            for(int i=1;i*i<=val;i++){
                if(val % i==0){
                    temp.push_back(i);
                    cnt++;

                    if (i != val / i) {
                        temp.push_back(val / i);
                        cnt++;
                    }
                    if(cnt > 4)
                    break;
                }
            }
            if(cnt==4){
                for(int t : temp)
                    ans += t;
            }   
        }
        return ans;
    }
};

// TIME COMPLEXITY -->> O(N * Sqrt(M))   
