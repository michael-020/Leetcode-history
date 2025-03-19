class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i <= N ; i++) {
            if(i<N) xor2 = xor2 ^ nums[i]; // XOR of array elements
            xor1 = xor1 ^ (i); //XOR up to [1...N-1]
        }


        return (xor1 ^ xor2); // the missing number
    }
};