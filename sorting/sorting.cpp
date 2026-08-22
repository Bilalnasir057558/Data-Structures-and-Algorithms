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

int main() {

    vector<int> v = {5, 4, 3, 2, 1};
    selectionSort(v);

    for(auto el : v) {
        cout<< el << " ";
    }
    cout<< endl;
    return 0;
}