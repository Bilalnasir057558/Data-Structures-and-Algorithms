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

    // Brute Force
    // O(n^2)
    // for(int i = 0; i < nums.size() - 1; i++) {
    //     for(int j = i + 1; j < nums.size(); j++) {
    //         if(nums[j] > nums[i]) return false;
    //     }
    // }

    // return true;

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

int removeDuplicates(vector<int> &nums)
{
    // set<int> s;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     s.insert(nums[i]);
    // }

    // return s.size();

    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] > nums[i])
        {                          // we found a new unique
            nums[i + 1] = nums[j]; // place it next to our current unique
            i++;
        }
    }
    return i + 1;
}

void rotateArrayByOne(vector<int>& nums) {
        int first = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = first;
}

void rotateArrayLeftByK(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Brute Force
        vector<int> temp(k);

        for(int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        for(int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        };

        for(int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }

        // Optimal Solution
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
        // reverse(nums.begin(), nums.end());
}

void rotateArrayRightByK(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Brute Force
        // vector<int> temp(k);

        // // store last k elements in a temporary vector
        // for(int i = n - k; i < n; i++) {
        //     temp[i - n + k] = nums[i];
        // }

        // // shifting n - k elements to the right
        // for(int i = n - k - 1; i >= 0; i--) {
        //     nums[i + k] = nums[i]; // moving k times forward
        // };

        // // copying last k elements at the front of the array
        // for(int i = 0; i < k; i++) {
        //     nums[i] = temp[i];
        // }

        // Optimal Solution
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
}

void moveZeroes(vector<int>& nums) {

    // Brute Force 1 -> T.C = O(n^2) 
    // int count = 0;
    // for(int i = 0; i < nums.size(); i++) {
    //     if(nums[i] == 0) {
    //         count++;
    //         for(int j = i + 1; j < nums.size(); j++) {
    //             nums[j - 1] = nums[j];
    //         }
    //         i--;
    //     }
    // }

    // for(int i = nums.size() - count; i < nums.size(); i++) {
    //     nums[i] = 0;
    // }

    // Brute Force 2
    vector<int> temp(nums.size());
    int idx = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            temp[idx] = nums[i];
            idx++;
        }
    }
    nums = temp;
}

int main()
{
    vector<int> v = {0, 0, 0, 3, 12};
    // cout << "Largest Element =  " << largestElement(v) << endl;

    // cout << "Second Largest Element = " << secondLargestElement(v) << endl;

    // if (isSorted(v))
    // {
    //     cout << "Sorted" << endl;
    // }
    // else
    // {
    //     cout << "Not Sorted" << endl;
    // }

    // cout << "Length are removing duplicates = " << removeDuplicates(v) << endl;

    // rotateArrayByOne(v);

    // rotateArrayLeftByK(v, 3);

    // rotateArrayRightByK(v, 3);

    moveZeroes(v);

    for(auto el : v) {
        cout<< el << " ";
    }
    cout << '\n';
    return 0;
}
