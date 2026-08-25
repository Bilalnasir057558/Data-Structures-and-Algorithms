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

int main() {

    vector<int> v = {5, 4, 3, 2, 1};
    // selectionSort(v);
    // bubbleSort(v);
    insertionSort(v);

    for(auto el : v) {
        cout<< el << " ";
    }
    cout<< endl;
    return 0;
}