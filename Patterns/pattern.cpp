#include <iostream>
using namespace std;

void pattern10(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
    for (int k = 1; k < n; k++)
    {
        for (int l = 1; l <= n - k; l++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}

void pattern11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            (i + j) % 2 == 0 ? cout << "1 " : cout << "0 ";
        }
        cout << '\n';
    }
}

void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 1; k <= n - i; k++)
        {
            cout << " ";
        }
        for (int m = 1; m <= n - i; m++)
        {
            cout << " ";
        }
        for (int l = 1; l <= i; l++)
        {
            cout << i - l + 1;
        }
        cout << '\n';
    }
}

void pattern13(int n)
{
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << '\n';
    }
}

void pattern14(int n)
{
    char a = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(a + j - 1) << " ";
        }
        cout << '\n';
    }
}

void pattern15(int n)
{
    char a = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << char(a + j - 1) << " ";
        }
        cout << '\n';
    }
}

void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char('A' + i) << " ";
        }
        cout << '\n';
    }
}

void pattern17(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << char('A' + k - 1);
        }
        for (int l = i - 1; l > 0; l--)
        {
            cout << char('A' + l - 1);
        }
        cout << '\n';
    }
}

void pattern18(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char('A' + n - i + j - 1) << " ";
        }
        cout << '\n';
    }
}

void pattern19(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << '*';
        }
        for(int k = 1; k < i; k++) {
            cout<< " ";
        }
        for(int l = 1; l < i; l++) {
            cout<< " ";
        }
        for (int m = 1; m <= n - i + 1; m++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<< "*";
        }
        for(int k = 1; k <= n - i; k++) {
            cout<< " ";
        }
        for(int l = 1; l <= n - i; l++) {
            cout<< " ";
        }
        for(int m = 1; m <= i; m++) {
            cout<< "*";
        }
        cout<< '\n';
    }
}

void pattern20(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<< "*";
        }
        for(int k = 1; k <= n - i; k++) {
            cout<< " ";
        }
        for(int l = 1; l <= n - i; l++) {
            cout<< " ";
        }
        for(int m = 1; m <= i; m++) {
            cout<< "*";
        }
        cout<< '\n';
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout<< "*";
        }
        for(int k = 1; k <= i; k++) {
            cout<< " ";
        }
        for(int l = 1; l <= i; l++) {
            cout<< " ";
        }
        for(int m = 1; m <= n - i; m++) {
            cout<< "*";
        }
        cout<< '\n';
    }
}

void pattern21(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                cout<< "*";
            }
            else cout<< " ";
        }
        cout<< '\n';
    }
}

void pattern22(int n) {

    // Brute force approach

    // for(int i = 1; i < 2 * n; i++) {
    //     for(int j = 1; j < 2 * n; j++) {
    //         if(i == 1 || i == (2 * n) - 1 || j == 1 || j == (2 * n) - 1) {
    //             cout<< n;
    //         } else if(i == 2 || i == (2 * n) - 2 || j == 2 || j == (2 * n) - 2) {
    //             cout<< n - 1;
    //         } else if(i == 3 || i == (2 * n) - 3 || j == 3 || j == (2 * n) - 3) {
    //             cout<< n - 2;
    //         } else if(i == 4 || i == (2 * n) - 4 || j == 4 || j == (2 * n) - 4) {
    //             cout<< n - 3;
    //         } else if(i == 5 || i == (2 * n) - 5 || j == 5 || j == (2 * n) - 5) {
    //             cout<< n - 4;
    //         } else  {
    //             cout<< " ";
    //         }
    //     }
    //     cout<< '\n';
    // }

    for(int i = 0; i < (2*n) - 1; i++) {
        for(int j = 0; j < (2*n) - 1; j++) {
            int top = i;
            int left = j;
            int right = ((2 * n) - 2) - j;
            int bottom = ((2 * n) - 2) - i;
            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << "\n";
    }
}

void testPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for(int k = 1; k <= i; k++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<< " ";
        }
        for(int k = 1; k <= n - i; k++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    // pattern22(n);
    testPattern(n);
    return 0;
}