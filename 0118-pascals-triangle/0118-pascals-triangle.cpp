class Solution {
public:
    vector<int> generateRow(int n){
        vector<int> ans;
        int res = 1;
        ans.push_back(1);
        for(int i=1; i<=n; i++){
            res = res * (n-i+1);
            res = res / i;
            ans.push_back(res);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};