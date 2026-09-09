#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int st, int mid, int end)
{
    vector<int> ans;

    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            ans.push_back(nums[i++]);
        else
            ans.push_back(nums[j++]);
    }

    while (i <= mid)
    {
        ans.push_back(nums[i++]);
    }

    while (j <= end)
    {
        ans.push_back(nums[j++]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        nums[st + i] = ans[i];
    }
}

void mergeSort(vector<int> &nums, int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int mid = (st + end) / 2;

    mergeSort(nums, st, mid);

    mergeSort(nums, mid + 1, end);

    merge(nums, st, mid, end);
}

int partition(vector<int> &nums, int st, int end)
{
    int pivot = nums[st];
    // int i = st;
    // int j = end;

    // while (i < j)
    // {
    //     while (nums[i] <= pivot && i <= end - 1)
    //     {
    //         i++;
    //     }

    //     while (nums[j] > pivot && j >= st + 1)
    //     {
    //         j--;
    //     }

    //     if(i < j) swap(nums[i], nums[j]);
    // }

    // swap(nums[j], nums[st]);
    // return j;

    int i = st - 1; // boundary marking everything <= pivot seen so far

    // scan through the rest  if anything <= pivot is found, expand the boundary
    for (int j = st; j < end; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    // after the scan, swap the pivot into correct place (i + 1)
    swap(nums[i + 1], nums[st]);
    return i + 1;
}

void quickSort(vector<int> &nums, int st, int end)
{
    if (st >= end)
        return;

    int partitionIndex = partition(nums, st, end);

    quickSort(nums, st, partitionIndex - 1);
    quickSort(nums, partitionIndex + 1, end);
}

void insertionSortRecursive(vector<int> &nums, int i, int n)
{
    if (i == n)
        return;

    int key = nums[i];
    int j = i - 1;

    while (j >= 0 && nums[j] > key)
    {
        nums[j + 1] = nums[j];
        j--;
    }

    nums[j + 1] = key;

    insertionSortRecursive(nums, i + 1, n);
}


int main()
{
    // vector<int> v = {-1, 5, 2, -1, 5, -2, 9};
    // int n = v.size();

    // mergeSort(v, 0, n - 1);
    // quickSort(v, 0, v.size() - 1);
    // insertionSortRecursive(v, 1, v.size());

    // for (auto el : v)
    // {
    //     cout << el << " ";
    // }

    return 0;
}