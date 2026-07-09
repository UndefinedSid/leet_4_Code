class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(! mp.count(key))
            return "";

        const auto& val=mp[key];
        int st=0,end=val.size()-1;
        string ans="";

        while(st <= end){
            int mid=st + ( end - st) / 2;
            if(val[mid].second <= timestamp){
                ans=val[mid].first;
                st = mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */