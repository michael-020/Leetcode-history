class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            ans.push_back(s[i]);
            
            if(ans.size() >= part.size() && ans.substr(ans.size()-part.size()) == part){
                for(int j=0; j<part.size(); j++){
                    ans.pop_back();
                }
            }
            
        }
        return ans;
    }
};