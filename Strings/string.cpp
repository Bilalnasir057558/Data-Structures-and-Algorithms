#include <bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    return false;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

bool isPalindrome(string s)
{
    int n = s.size();

    int start = 0;
    int end = n - 1;

    while (start < end)
    {

        while (!isAlphaNumeric(s[start]) && start < end)
            start++;
        while (!isAlphaNumeric(s[end]) && start < end)
            end--;

        if (toLower(s[start]) != toLower(s[end]))
            return false;

        start++;
        end--;
    }

    return true;
}

bool isAnagram(string s, string t)
{
    /*

    // Brute Force
    // O(nlogn) + O(mlogm)
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
        return true;
    return false;

    */

    /*
    // Using Hash Map but not optimal
    // T.C = O(3n), S.C = O(2n)
    unordered_map<char, int> mpS;
    unordered_map<char, int> mpT;

    if(s.size() != t.size()) return false;

    for(char ch : s) {
        mpS[ch]++;
    }

    for(char ch : t) {
        mpT[ch]++;
    }

    for(char ch : s) {
        if(mpS[ch] != mpT[ch]) return false;
    }

    return true;

    */

    // Optimal - Using Single Hash
    // O(n) b/c sizes are equal and no extra space is used

    if (s.size() != t.size())
        return false;

    // constant space O(1)
    int freq[26] = {0};

    // storing freq of each letter corresponding to its index i.e. 0 for a, 25 for z
    // same letters cancel each other
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    // if all cancels -> anagram
    // takes O(26) -> constant time
    for (int count : freq)
    {
        if (count != 0)
            return false;
    }

    return true;
}

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.size(); i++)
    {   
        char ch1 = s[i];
        char ch2 = t[i];

        // check ch1 mapping already exists in mp1, if yes, then it should be map to the same ch2
        if(mp1.count(ch1) && mp1[ch1] != ch2) {
            return false;
        }

        // check ch2 mapping already exists in mp2, if yes, then it should be map to the same ch1
        if(mp2.count(ch2) && mp2[ch2] != ch1) {
            return false;
        }

        // if no conflicts, create mapping
        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }

    return true;

}


int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0; // to read and find consecutive characters
    int index = 0; // to write in the same array

    // T.C = O(n) b/c even though there is a while loop inside loop still every character is read only once (i only moves forward i.e. i++)
    while(i < n) {
        char current = chars[i];

        int count = 0;
        while(i < n && chars[i] == current) {
            count++;
            i++;
        }

        // write character
        chars[index] = current;
        index++; // points to the idx where we should write count

        // write digits in separate indices if more than one digits are present
        if(count != 1) {
            string num = to_string(count); // even if count is too large, digits are negligibly small -> constant space
            for(char digit : num) {
                chars[index] = digit;
                index++;
            }
        }

        return index;
    }
}

int main()
{
    // string s = "A man, a plan, a canal: Panama";

    // if (isPalindrome(s))
    //     cout << "True" << endl;
    // else
    //     cout << "False" << endl;

    // string s = "anagram";
    // string t = "nagaram";

    // if (isAnagram(s, t))
    //     cout << "True" << endl;
    // else
    //     cout << "False" << endl;

    // string s = "bbbaaaba";
    // string t = "aaabbbba";

    // if(isIsomorphic(s, t)) cout<< "True" << endl;
    // else cout<< "False" << endl;

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int ans = compress(chars);

    cout<< "New Length = " << ans << endl;

    return 0;
}