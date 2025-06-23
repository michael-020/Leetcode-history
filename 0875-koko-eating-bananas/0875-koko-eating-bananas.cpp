class Solution {
public:
    int maxInAnArray(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    long long getHours(vector<int>& nums, int mid){
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += ceil((double)nums[i]/(double)mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxInAnArray(piles);
        while(low <= high){
            int mid = (low+high)/2;
            long long ans = getHours(piles, mid);

            if(ans <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }    

        return low;
    }
};