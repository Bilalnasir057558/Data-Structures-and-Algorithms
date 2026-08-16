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
    if(i > n) {
        return;
    }
    cout<< i << endl;
    printNumberInAsc(i + 1, n);

    // Using Backtracking -> first all the call are sat on the stack until the base case is executed, then print from the last function call in reverse order
    // printNumberInAsc(i + 1, n);
    // cout<< i << endl;
}

int main() {
    int n;
    cin >> n;
    // printName(n);

    int i = 1;
    printNumberInAsc(i, n);
}