#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& nums) {

    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    // loop from 0 to n - 1. After each iteration, one element would be sorted
    for(int i = 0; i < nums.size() - 1; i++) {

        // in each iteration, select first element of that range to be the mininum element
        int min = i;

        // inner loop runs from i to n 
        for(int j = i + 1; j < nums.size(); j++) {

            // if smaller number is found, update min
            if(nums[j] < nums[min]) {
                min = j;
            }
        }

        // swap minimum element with the first element of the particular range
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}

void bubbleSort(vector<int>& nums) {

    // Brute Force
    // Time Complexity is O(n^2)
    // Outer loop runs n times
    // for(int i = nums.size() - 1; i >= 0; i--) {

    //     // inner loop runs i times
    //     for(int j = 0; j <= i - 1; j++) {
    //         if(nums[j] > nums[j+1]) {
    //             swap(nums[j], nums[j+1]);
    //         }
    //     }
    // };

    // Optimal Approach
    // for best case when already sorted -> outer loop runs only one time. if i = 4, inner loop runs 4 times and break after it
    // Means total operations are n - 1 i.e 4 so time complexity in this case is reduced to O(n)
    for(int i = nums.size() - 1; i >= 0; i--) {
        bool didSwap = 0; 
        // inner loop runs i times
        for(int j = 0; j <= i - 1; j++) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                didSwap = 1;
            }
        }

        // If the array is already sorted no swap will occur and we will break out from the loop
        if(!didSwap) {
            break;
        }
    };
}

void insertionSort(vector<int>& nums) {

    int n = nums.size();
    for(int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;

        while(j >= 0 && nums[j] > key) {

            // shift larger element to the right to free up the space
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

void merge(vector<int>& nums, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    vector<int> temp;

    while(left <= mid && right <= end) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
        }
    };

    // copy remaining elements of the left half
    while(left <= mid) {
        temp.push_back(nums[left++]);
    };

    // copy remaining elements of the right half
    while(right <= end) {
        temp.push_back(nums[right++]);
    }

    // copy temp vector to the original array
    for(int i = 0; i < temp.size(); i++) {
        nums[i + start] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int start, int end) {
    if(start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    // Apply mergeSort on left half
    mergeSort(nums, start, mid);

    // Apply mergeSort on right half
    mergeSort(nums, mid + 1, end);

    // merge
    merge(nums, start, mid, end);

}

int partition(vector<int>& nums, int st, int end) {
    int pivot = nums[st];
    int i = st;
    int j = end;


    // partition logic -> moving smaller elements on left and larger on right
    while(i < j) {
        while(nums[i] <= pivot && i <= end - 1) {
            i++;
        }
        while(nums[j] > pivot && j >= st + 1) {
            j--;
        }
        
        // swapping only if pointers donot cross each other
        if(i < j) {
            swap(nums[i], nums[j]);
        }   
    }

    // move the pivot at its correct place i.e. j (the last index of smaller elements)
    swap(nums[st], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int st, int end) {
    if(st >= end) return;

    int pivotIndex = partition(nums, st, end);

    quickSort(nums, st, pivotIndex - 1);

    quickSort(nums, pivotIndex + 1, end);
}

int main() {

    vector<int> v = {4, 6, 2, 5, 7, 9, 1, 3};
    // selectionSort(v);
    // bubbleSort(v);
    // insertionSort(v);

    // mergeSort(v, 0, v.size() - 1);
    quickSort(v, 0, v.size() - 1);

    for(auto el : v) {
        cout<< el << " ";
    }
    cout<< endl;
    return 0;
}