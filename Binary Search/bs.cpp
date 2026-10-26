#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int lowerBound(vector<int> &nums, int x)
{
    int s = 0, e = nums.size() - 1;
    int lower = nums.size();

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] >= x)
        {
            lower = mid;
            e = mid - 1;
        }

        if (nums[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return lower;
}

int upperBound(vector<int> &nums, int x)
{
    int s = 0;
    int e = nums.size() - 1;
    int upper = nums.size();

    while (s <= e)
    {

        int mid = s + (e - s) / 2;
        if (nums[mid] > x)
        {
            upper = mid;
            e = mid - 1;
        }

        if (nums[mid] <= x)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return upper;
}

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int answer = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            answer = mid;
            high = mid - 1;
        }

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return answer;
}

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    int low = 0;
    int high = nums.size() - 1;
    int floor = -1;
    int ceil = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == x)
        {
            return {x, x};
        }
        else if (nums[mid] > x)
        {
            ceil = nums[mid];
            high = mid - 1;
        }
        else
        {
            floor = nums[mid];
            low = mid + 1;
        }
    }
    return {floor, ceil};
}

int firstOcc(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;

            // target can also be in left side
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return first;
}

int secondOcc(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int second = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            second = mid;

            // target can also be in right side
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return second;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {firstOcc(nums, target), secondOcc(nums, target)};
}

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    // loop until low >= high (only one element is remaining i.e. peak element so no need to iterate further)
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // Case 1: mid element lies in the left increasing part b/c it is smaller than its next element
        // Move low to mid + 1
        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;

            // Case 2: mid element is probably peak element b/c it is greater than its next element, but peak element can also be found on left of mid
        }
        else
        {
            high = mid;
        }
    }
    // both ptrs point to the peak element, so return any of them
    return low;
}

int pivotIdx(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // if mid element is greater than the first element means it is in the first sorted array
        if (nums[mid] >= nums[0])
        {
            low = mid + 1;

            // if mid element might be the pivot, but it can also be found somewhere on left
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int searchInSortedRotatedArray(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivot = pivotIdx(nums);

    int low, high;

    // Binary Search on right sorted Array b/c target is b/w pivot and high (inclusive)
    if (nums[pivot] <= target && target <= nums[n - 1])
    {
        low = pivot;
        high = n - 1;

        // Binary search on left side
    }
    else
    {
        low = 0;
        high = pivot - 1;
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

bool searchInSortedRotatedArrayII(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Case 1: mid is the target
        if (nums[mid] == target)
            return true;

        // Case 2: Sorted part can't be find due to duplicates
        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }

        // Case 3: left part is sorted
        else if (nums[mid] >= nums[low])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        // Case 4: Right part is sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Optimization: If array is already sorted, min is the nums[low] element
        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }

        // If left half is sorted
        if (nums[mid] >= nums[low])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;

            // right half is sorted
        }
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int findKRotation(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int answer = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < answer)
            {
                answer = nums[low];
                index = low;
            }
        }

        if (nums[mid] >= nums[low])
        {
            if (nums[low] < answer)
            {
                answer = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < answer)
            {
                answer = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // if mid is odd
        if (mid % 2 == 1)
            mid--;

        // if pair is correct, go the right side
        if (nums[mid] == nums[mid + 1])
        {
            low = mid + 2;

            // if pair is broken, single is mid or to its left
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
}

int countOccurrences(vector<int>& arr, int target)  {
    int lower = lowerBound(arr, target);

    int upper = upperBound(arr, target);

    // if target is absent, their is nothing to count
    if(lower == arr.size() || arr[lower] != target) {
        return 0;
    }
    return upper - lower;
}

int floorSqrt(int n)  {
      long long low = 0;
      long long high = n;
      long long ans = 0;

      while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid == n) return mid;
        else if(mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
      }
      return ans;
    }

int comparePower(int mid, int M, int N) {
    long long ans = 1;

    for(int i = 1; i <= N; i++) {

        // check overflow before calculating power
        if(ans > M / mid) { // mid^N > M
            return 1;
        }

        ans *= mid;
    }

    if(ans == M) return 0; // mid^N = M
    return -1;
}

int nthRoot(int M, int N) {
    int low = 1; 
    int high = M;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int result = comparePower(mid, M, N);

        if(result == 0) return mid;
        else if(result == 1) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int smallestDivisor(vector<int>& nums, int threshold) {

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int sum = 0;
        for(auto& num : nums) {
            sum += ((num + mid - 1) / mid);
        }
        if(sum <= threshold) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    // vector<int> ans = searchRange(nums, 8);

    // for(auto el : ans) {
    //     cout<< el << " ";
    // }
    // cout<< '\n';

    // cout<< "Peak Element Idx = " << peakIndexInMountainArray(nums) << endl;

    // cout << "Idx of target in sorted rotated array = " << searchInSortedRotatedArray(nums, 1) << endl;

    // cout << "Minimum in a Rotated Array = " << findMin(nums) << endl;

    // cout<< "Total Occurrences = " << countOccurrences(nums, 4) << endl;

    // cout<< "Nth Root = " << nthRoot(27,5) << endl;

    cout << "Smallest Divisor = " << smallestDivisor(nums, 7) << endl;
    return 0;
}