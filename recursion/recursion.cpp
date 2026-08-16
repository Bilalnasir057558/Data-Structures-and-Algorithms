#include<bits/stdc++.h>
using namespace std;

 // T.C = O(n) S.C = O(n) -> stack space used in recursive calls
void printName(int n) {
    if(n == 0) {
        return;
    }
    cout << "Bilal" << endl;
    printName(n - 1);
}

// O(n)
void printNumberInAsc(int i, int n) {
    // Forward recursion
    if(i > n) {
        return;
    }
    cout<< i << endl;
    printNumberInAsc(i + 1, n);

    // Using Backtracking -> first all the call are sat on the stack until the base case is executed, then print from the last function call in reverse order
    // printNumberInAsc(i + 1, n);
    // cout<< i << endl;
}

void printNumberInDesc(int i, int n) {

    // Forward recursion
    if(i < 1) {
        return;
    }
    // cout<< i << endl;
    // printNumberInDesc(i - 1, n);

    // Backtracking
    printNumberInDesc(i - 1, n);
    cout<< i << endl;
}

int printSum(int n) {
    if(n == 1) return 1;
    return n + printSum(n - 1);

    // Optimized way -> O(1)
    // return (n * (n + 1)) / 2;
} 

// we divide the problem into smaller sub problems and all subproblems results are multiplied together as the function call returns
int factorial(int n) {
    if(n == 0) return 1; // factorial of 0 is 1
    return n * factorial(n - 1);
}

vector<int> reverseArray(vector<int> &arr) {

    // Brute force 
    // O(n) -> loop runs n times
    // Space complexity O(n) -> extra vector space of size n is used
    // int n = arr.size();
    // vector<int> ans(n);

    // // loop runs n times
    // for(int i = 0; i < n; i++) {
    //     ans[i] = arr[n - i - 1];
    // }

    // return ans;

    // Better Approach - Using two pointers
    // O(n) -> no of iterations increases linearly as the input size grows
    // space complexity -> O(1) -> no extra space used for storing array elements
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        swap(arr[start], arr[end]);

        // increment start
        start++;

        // decrement end
        end--;
    }
    return arr;

    // using stl reverse function 
    reverse(arr.begin(), arr.end()); // it still uses two pointers approach internally therefore
    // complexity is O(n);
    return arr;
}

int main() {
    int n;
    cin >> n;
    // printName(n);

    // int i = n;
    // printNumberInDesc(i, n);

    // cout<< "Sum = " << printSum(n) << endl;
    
    // cout<< "Factorial = " << factorial(n) << endl;

    vector<int> v = {9, 8, 7, 6, 5};
    vector<int> ans = reverseArray(v);

    for(auto el : ans) {
        cout<< el << " ";
    }
    cout << endl;
}