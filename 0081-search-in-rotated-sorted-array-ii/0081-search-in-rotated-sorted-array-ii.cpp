class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            //if mid points the target
            if (arr[mid] == target) return true;

            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            //if left part is sorted:
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= target && target <= arr[mid]) {
                    //element exists in the left part:
                    high = mid - 1;
                }
                else {
                    //element exists in the right part:
                    low = mid + 1;
                }
            }
            else { //if right part is sorted:
                if (arr[mid] <= target && target <= arr[high]) {
                    //element exists in the right part:
                    low = mid + 1;
                }
                else {
                    //element exists in the left part:
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};