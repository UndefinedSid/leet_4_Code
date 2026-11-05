class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        int n=nums.size();
        vector<string> arr;

        for(int val : nums){
            arr.push_back(to_string(val));
        }

        sort(arr.begin(),arr.end(),[](string& a,string& b){
            return (a+b) > (b+a);
        });

        if(arr[0]== "0")
            return "0";

        for(string str: arr)
            ans += str;

        return ans;

    }
};