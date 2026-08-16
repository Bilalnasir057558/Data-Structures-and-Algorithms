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

bool isAlphaNumeric(char c) {
    if((c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z')
    || (c >= '0' && c <= '9')) return true;
    return false;
}

void toLower(char &c) {
    if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
}

bool validPalindrome(string s, int i) {

    // O(n) both time and space complexity

    // base case = when i (current index) go half of the string means we have done all the comparisons and we don't find any mismatch
    // if(i >= s.length() / 2) return true;

    // if corresponding elements do not match, return false;
    // if(s[i] != s[s.length() - i - 1]) return false;

    // if corresponding elements are same then we again recursively call the same function with next index
    // return validPalindrome(s, i + 1);

    // Optimized Approach which gives O(1) space complexity
    int start = i;
    int end = s.size() - 1;

    while(start < end) {

        // skip non alphanumeric from start to middle
        while(start < end && !isAlphaNumeric(s[start])) {
            start++;
        }

        // skip non alphanumeric from end  to middle
        while(start < end && !isAlphaNumeric(s[end])) {
            end--;
        }

        toLower(s[start]);
        toLower(s[end]);
        
        if(s[start] != s[end]) return false;

        start++;
        end--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    // printName(n);

    // int i = n;
    // printNumberInDesc(i, n);

    // cout<< "Sum = " << printSum(n) << endl;
    
    // cout<< "Factorial = " << factorial(n) << endl;

    // vector<int> v = {9, 8, 7, 6, 5};
    // vector<int> ans = reverseArray(v);

    // for(auto el : ans) {
    //     cout<< el << " ";
    // }
    // cout << endl;

    string s = "A man, a plan, a canal: Panama";
    if(validPalindrome(s, 0)) {
        cout<< "Palindrome" << endl;
    } else {
        cout<< "Not a palindrome" << endl;
    }
}