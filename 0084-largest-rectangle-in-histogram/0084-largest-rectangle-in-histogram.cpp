class Solution {
public:
    vector<int> nextSmaller(vector<int> nums, int n){
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> nums, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = prevSmaller(heights, n);
        vector<int> next = nextSmaller(heights, n);

        for(int &num: next){
            if(num == -1)
                num = n;
        }

        int maxArea = INT_MIN;

        for(int i=0; i<n; i++){
            int length = heights[i];
            int width = next[i] - prev[i] - 1;
            int currArea = length * width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};