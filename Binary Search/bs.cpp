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

int firstOcc(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int first = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) {
            first = mid;

            // target can also be in left side
            high = mid - 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return first;
}

int secondOcc(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int second = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) {
            second = mid;

            // target can also be in right side
            low = mid + 1;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return second;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {firstOcc(nums, target), secondOcc(nums, target)}; 
}       

int peakIndexInMountainArray(vector<int>& arr)  {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    // loop until low >= high (only one element is remaining i.e. peak element so no need to iterate further)
    while(low < high) {
        int mid = low + (high - low) / 2;

        // Case 1: mid element lies in the left increasing part b/c it is smaller than its next element
        // Move low to mid + 1
        if(arr[mid] < arr[mid + 1]) {
            low = mid + 1;

        // Case 2: mid element is probably peak element b/c it is greater than its next element, but peak element can also be found on left of mid
        } else {
            high = mid;
        }
    }
    // both ptrs point to the peak element, so return any of them
    return low;
}

int pivotIdx(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        // if mid element is greater than the first element means it is in the first sorted array
        if(nums[mid] >= nums[0]) {
            low = mid + 1;

        // if mid element might be the pivot, but it can also be found somewhere on left
        } else {
            high = mid;
        }
    }

    return low;
}

int searchInSortedRotatedArray(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = pivotIdx(nums);

    int low, high;

    // Binary Search on right sorted Array b/c target is b/w pivot and high (inclusive)
    if(nums[pivot] <= target && target <= nums[n - 1]) {
        low = pivot;
        high = n - 1;
    
    // Binary search on left side
    } else {
        low = 0;
        high = pivot - 1;
    }

    while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

    return -1;
}

int main()
{
    vector<int> nums = {1, 3};
    // vector<int> ans = searchRange(nums, 8);

    // for(auto el : ans) {
    //     cout<< el << " ";
    // }
    // cout<< '\n';

    // cout<< "Peak Element Idx = " << peakIndexInMountainArray(nums) << endl;

    cout << "Idx of target in sorted rotated array = " << searchInSortedRotatedArray(nums, 1) << endl;
    return 0;
}