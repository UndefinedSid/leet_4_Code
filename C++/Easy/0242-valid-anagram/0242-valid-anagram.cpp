class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        // for normal english letters
        vector<int> freq(26, 0);
        if(s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int cnt : freq)
            if (cnt > 0)
                return false;

        return true;

        */
        // when we have unicode characters i.e (alphabets,symbols,emoji) also then use just hash map instead of fixed size array

        unordered_map<char,int> freq;

        if(s.size() != t.size())
            return false;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto& p : freq){
            if(p.second > 0)
                return false;
        }
        return true;
    }
};