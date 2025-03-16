function maxSubArray(nums: number[]): number {
    let n = nums.length
    let maxSum = Number.NEGATIVE_INFINITY
    let sum = 0
    for(let i=0; i<n; i++){
        sum += nums[i]

        if(sum > maxSum)
            maxSum = sum

        if(sum < 0)
            sum = 0; 
    }

    return maxSum;
};