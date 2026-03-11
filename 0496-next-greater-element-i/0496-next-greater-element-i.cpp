class Solution {
public:
    int search(vector<int> nums, int target){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target)
                return i;
        }

        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<n; i++){
            int num = nums1[i];
            int index = search(nums2, num);
            cout << "index: " << index << endl;
            if(index == -1) {

                continue;
            }
            for(int j=index; j<m; j++){
                if(nums2[j] > num){
                    ans.push_back(nums2[j]);
                    break;
                }
                else {
                    if(j == m-1){
                        ans.push_back(-1);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};