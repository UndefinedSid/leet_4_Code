class Solution {
public:
    bool checkString(string s) {
        bool found=false;
        for(char ch : s){
            if(ch=='b'){
                found=true;
            }else if(found && ch== 'a'){
                return false;
            }
        }
        return true;
    }
};