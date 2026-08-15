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

int main() {
    int n;
    cin >> n;
    printName(n);
}