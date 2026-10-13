#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
    int m = n;
    int sum = 0;
    int totalDigits = log10(n) + 1;

    // T.C = O(log10(n))
    while(m != 0) {
        int digit = m % 10;
        m /= 10;
        sum += pow(digit, totalDigits);
    }

    if(sum == n) return true;
    else return false;
}

int fib(int n) {
    if(n == 1) return 0;
    else if(n == 2) return 1;

    return fib(n - 1) + fib(n - 2);
}

vector<int> moveZeros(vector<int>& nums) {
    int i = 0, j = 1;
    while(i < nums.size()) {
        if(nums[i] == 0 && nums[j] != 0) {
            swap(nums[i], nums[j]);
        } 
    }
}

int main() {
    int n = 8;
    // if(isArmstrong(n)) cout<< "Armstrong";
    // else cout<< "not an armstrong";

    int fibAns = fib(n);
    cout<< "Fibonacci number = " << fibAns << endl;
    return 0;
}