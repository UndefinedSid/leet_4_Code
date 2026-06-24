class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto& word : strs){
            string temp=word;
            sort(word.begin(),word.end());
            mp[word].push_back(temp);
        }
       vector<vector<string>> ans;
       for(auto& pair : mp){
            ans.push_back(pair.second);
       }

       return ans;
    }
};