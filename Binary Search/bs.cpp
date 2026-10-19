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
int main()
{
}