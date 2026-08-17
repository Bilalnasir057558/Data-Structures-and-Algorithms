#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>> arr[i];
    }

    // suppose maximum array element is 12 -> make hash array of size 13 because there should be idx 12 present to store frequency of query 12
    // space complexity is O(maxElement(arr) + 1)
    int hashArr[13] = {0};

    // pre-storing frequency before answering any query -> Takes O(n)
    for(int i = 0; i < n; i++) {
        hashArr[arr[i]] += 1; // increasing count of the ith idx in hashArr for i number in query arr e.g if query number is 1, we increase count of 1st idx in hash array
    }

    // takes O(q) time complexity
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        // fetching - Takes contant time O(1)
        cout << hashArr[number] << endl;
    }
    
    return 0;
}