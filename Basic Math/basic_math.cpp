#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    // Brute force appraoch

    // if(n == 0) return 1;
    // int digitCount = 0;
    // while(n != 0) {
    //     digitCount++;
    //     n /= 10;
    // }
    // return digitCount;

    // Using formula
    if (n == 0)
        return 1;
    int digitCount = (int)(log10(n) + 1);
    return digitCount;
}

int reverseInteger(int n)
{
    if (n == 0)
        return 0;
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
            return 0; // Sometimes answer go out of the range of Integer [-2^31, 2^31 - 1], If answer to go out return 0;
        ans = (ans * 10) + digit;
        n /= 10;
    }
    return ans;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int reversed = 0;
    int n = x;
    while (n != 0)
    {
        int digit = n % 10;
        if (reversed < INT_MIN / 10 || reversed > INT_MAX / 10)
            return 0;
        reversed = (reversed * 10) + digit;
        n /= 10;
    }
    return x == reversed;
}

bool isArmstrong(int n) {
    int ans = 0;
    int x = n;
    int digitsCnt = log10(x) + 1;
    while(x != 0) {
        int digit = x % 10;
        ans += pow(digit, digitsCnt);
        x /= 10;
    }
    return ans == n;
}

vector<int> divisors(int n) {

    // Brute Force -> O(n)
    // vector<int> v;
    // for(int i = 1; i <= n; i++) {
    //     if(n % i == 0) {
    //         v.push_back(i);
    //     }
    // }
    // return v;

    // Optimized Approach
    vector<int> v;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n/i) v.push_back(n/i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

bool isPrime(int n) {

    // Brute force -> O(n - 2) -> O(n) and Space complexity is O(1)
    // if(n == 0 || n == 1) return false; 
    // for(int i = 2; i < n; i++) {
    //     if(n % i == 0) return false;
    // }
    // return true;

    // Optimized Approach
    // loop runs sqrt(n) times -> O(sqrt(n))
    if(n <= 1) return false;
    for(int i = 2; i * i < n; i++) { // i * i <= n is faster than i <= sqrt(n)
        if(n % i == 0) return false;
    }
    return true;
}

void GCD(int n1, int n2) {
  
    // Brute Force
    // vector<int> v1, v2, common;
    // for(int i = 1; i * i <= n1; i++) {
    //     if(n1 % i == 0) {
    //         v1.push_back(i);
    //         if(i != n1/i) v1.push_back(n1/i);
    //     }
    // }

    // for(int i = 1; i * i <= n2; i++) {
    //     if(n2 % i == 0) {
    //         v2.push_back(i);
    //         if(i != n2/i) v2.push_back(n2/i);
    //     }
    // }
    
    // sort(v1.begin(), v1.end());
    // sort(v2.begin(), v2.end());
    // set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(common));
    // cout<< "HCF: " << *max_element(common.begin(), common.end());

    // Brute Force -> O(min(n1, n2)) -> O(n)
    // int gcd = 1;
    // for(int i = min(n1, n2); i >= 1; i++) {
    //     if(n1 % i == 0 && n2 % i == 0) {
    //         gcd = i;
    //         break;
    //     }
    // }
    // cout << gcd << endl;

    // Optimized Approach -> Euclidean Algorithm -> O(log fi min(n1, n2))
    while(n1 > 0 && n2 > 0) {
        if(n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    int gcd = n1 == 0 ? n2 : n1;
    cout<< gcd << endl;
}

int main()
{
    // int n;
    // cin >> n;
    // cout<< "Number of digits: " << countDigits(n) << endl;
    // cout << "Reverse of Integer: " << reverseInteger(n) << endl;
    // if(isPalindrome(n)) cout << "Palindrome" << endl;
    // else cout<< "Not a Palindrome" << endl;

    // if(isArmstrong(n)) {
    //     cout<< "Armstrong" << endl;
    // } else {
    //     cout<< "Not an armstrong" << endl;
    // }

    // vector<int> ans = divisors(n);
    // for(auto el : ans) {
    //     cout << el << " ";
    // }

    // if(isPrime(n)) {
    //     cout<< "Prime" << endl;
    // } else cout<< "Not a prime" << endl;

    int n1, n2;
    cin >> n1 >> n2;
    GCD(n1, n2);
    return 0;
}