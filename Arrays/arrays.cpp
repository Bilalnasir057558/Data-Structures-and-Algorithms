#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &nums)
{

    // Brute Force
    // T.C = O(nlogn), S.C = O(1)
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() - 1];

    // Optimal Approach
    // T.C = O(n), S.C = O(1)
    int maxElement = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > maxElement)
            maxElement = i;
    }

    return maxElement;
}

int secondLargestElement(vector<int> &nums)
{

    // Brute Force
    // T.C = O(n), S.C = O(1);
    // int largest = INT_MIN, second_largest = INT_MIN;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > largest)
    //         largest = nums[i];
    // }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > second_largest && nums[i] != largest)
    //     {
    //         second_largest = nums[i];
    //     }
    // }

    // if (second_largest > INT_MIN)
    // {
    //     return second_largest;
    // }
    // else
    // {
    //     return -1;
    // }

    // Optimal Approach with a single loop
    // T.C = O(n), S.C = O(1)
    int largest = INT_MIN, second_largest = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        // if any element greater than largest is found, we make our previour largest the second largest and largest the current element
        if (nums[i] > largest)
        {
            second_largest = largest;
            largest = nums[i];

            // else if any element greater than the 2nd largest is found which is not the largest, then we just found the 2nd largest
        }
        else if (nums[i] > second_largest && nums[i] != largest)
        {
            second_largest = nums[i];
        }
    }

    if (second_largest > INT_MIN)
    {
        return second_largest;
    }
    else
        return -1;
}

bool isSorted(vector<int> &nums)
{
    // Optimal Approach
    // T.C = O(n), S.C = O(1)
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {

        // if previous element is greater than the next element, means they are not in ascending order
        if (nums[i - 1] > nums[i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> v = {10, 50, 30, 40, 50};
    // cout << "Largest Element =  " << largestElement(v) << endl;

    // cout << "Second Largest Element = " << secondLargestElement(v) << endl;

    if(isSorted(v)) {
        cout<< "Sorted" << endl;
    } else {
        cout<< "Not Sorted" << endl;
    }
    return 0;
}
