class Solution {
public:
    using ll=long long;

    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans=0;
        if(need1==0 && need2==0)
            return 0;
        else if(need1==0 && need2 > 0){
            ans += min(cost2,costBoth) * need2;
            return ans;
        }else if(need1 > 0 && need2==0){
            ans += min(cost1,costBoth) * need1;
            return ans;
        }else{

            ll opt1=(ll)costBoth * max(need1,need2);
            ll opt2=(ll)cost1 * need1 + (ll)cost2 * need2;
            ll opt3=LLONG_MAX, opt4=LLONG_MAX;
            if(need1 < need2){
                opt3=(ll)cost2 * abs(need1- need2) + (ll)costBoth * need1;
            }else if(need1 > need2){
                opt4=(ll)cost1 * abs(need1 - need2) + (ll)costBoth * need2;
            }
            ans = min({opt1,opt2,opt3,opt4});

        }
        return ans;
    }
};