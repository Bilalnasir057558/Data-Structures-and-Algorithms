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
        if (mp1.count(ch1) && mp1[ch1] != ch2)
        {
            return false;
        }

        // check ch2 mapping already exists in mp2, if yes, then it should be map to the same ch1
        if (mp2.count(ch2) && mp2[ch2] != ch1)
        {
            return false;
        }

        // if no conflicts, create mapping
        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }

    return true;
}

int compress(vector<char> &chars)
{
    int n = chars.size();
    int i = 0;     // to read and find consecutive characters
    int index = 0; // to write in the same array

    // T.C = O(n) b/c even though there is a while loop inside loop still every character is read only once (i only moves forward i.e. i++)
    while (i < n)
    {
        char current = chars[i];

        int count = 0;
        while (i < n && chars[i] == current)
        {
            count++;
            i++;
        }

        // write character
        chars[index] = current;
        index++; // points to the idx where we should write count

        // write digits in separate indices if more than one digits are present
        if (count != 1)
        {
            string num = to_string(count); // even if count is too large, digits are negligibly small -> constant space
            for (char digit : num)
            {
                chars[index] = digit;
                index++;
            }
        }

        return index;
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    /*

    // T.C = O(S); S is the number of characters across all strings,
    // In worst case if all strings are identical -> O(n * m)
    int n = strs.size();
    if (n == 1)
        return strs[0];

    int m = strs[0].size();
    string longestPrefix = "";

    for (int i = 0; i < m; i++)
    {
        char prefix = strs[0][i];

        for (int j = 1; j < n; j++)
        {
            if (i >= strs[j].size() || strs[j][i] != prefix)
            {
                return longestPrefix;
            }
        }

        longestPrefix.push_back(prefix);

    }
    return longestPrefix;

    */

    // Simplified
    if (strs.empty())
        return "";

    for (int i = 0; i < strs[0].size(); i++)
    {
        char prefix = strs[0][i];

        for (int j = 1; j < strs.size(); j++)
        {

            // If any string ends or mismatches, return prefix up to index i
            if (i >= strs[j].size() || strs[j][i] != prefix)
            {
                return strs[0].substr(0, i);
            }
        }
    }

    // whole string is the prefix
    return strs[0];
}

string keyGenerate(const string& word) {
    
    int freq[26] = {0};

    for(char ch : word) {
        freq[ch - 'a']++;
    }

    string key = "";
    for(int i = 0; i < 26; i++) {
        key += '#' + to_string(freq[i]);
    }

    return key;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    /*
    // Approach 1 -> not optimal
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    // T.C = O(n * klogk) + O(n) -> O(n * klogk)
    // S.C = O(n * k)

    // O(n * klogk)
    for (string &word : strs)
    {
        string key = word;
        sort(key.begin(), key.end());
        mp[key].push_back(word);
    }

    // O(n)
    for (auto &group : mp)
    {
        result.push_back(move(group.second)); // moves transfer ownership of internal memory ptr from hash map to array
    }
    return result;

    */

    // Optimal
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    // T.C = O(n * k) + O(n) -> O(n * k)
    // S.C = O(n * k)

    // O(n * k)
    for (string &word : strs)
    {
        string key = keyGenerate(word);
        mp[key].push_back(move(word));
    }

    // O(n)

    result.reserve(mp.size());
    for (auto &group : mp)
    {
        result.push_back(move(group.second)); // moves transfer ownership of internal memory ptr from hash map to array
    }
    return result;
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

    cout << "New Length = " << ans << endl;

    return 0;
}