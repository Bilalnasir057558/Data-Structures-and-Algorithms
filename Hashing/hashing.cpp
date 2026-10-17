#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int> &nums)
{

    // Using array hashing
    // In worst case where all the array elements are unique, it uses N unique elements -> space complexity = O(N)
    // vector<vector<int>> ans;

    // // O(n) - n = size of nums
    // auto maxIt = max_element(nums.begin(), nums.end());

    // // if M is maxElement then it uses O(M) auxiliary space
    // vector<int> hash(*maxIt + 1, 0);

    // // pre-computation takes O(n)
    // for(int i = 0; i < nums.size(); i++) {
    //     hash[nums[i]]++;
    // }

    // // takes O(M) -> M + 1 is the size of hash array
    // for(int i = 0; i < hash.size(); i++) {
    //     if(hash[i] > 0) {
    //         ans.push_back({i, hash[i]});
    //     }
    // }

    // // T.C = O(N) + O(N) + O(M) -> O(N + M)
    // // S.C = O(N + M)
    // return ans;

    // in worst case, if all elements are unique in array, then it takes n space
    vector<vector<int>> ans;

    // in worst case, if all elements are unique in array, then it takes n space
    unordered_map<int, int> mp;

    // takes O(n) n = size of nums
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] += 1; // takes O(1) in best and avg case and worst case is rare
    };

    // takes O(n)
    for (auto el : mp)
    {
        ans.push_back({el.first, el.second});
    };

    return ans;
}

int testMaxOccurrence(vector<int> nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    };

    int maxCount = 0;
    int maxElement = nums[0];
    for (auto el : mp)
    {
        if (el.second > maxCount)
        {
            maxCount = el.second;
            maxElement = el.first;
        }
    }

    return maxElement;
}

void testSumToTarget(vector<int> nums, int target)
{

    // Brute Force
    // for(int i = 0; i < nums.size() - 1; i++) {
    //     for(int j = i + 1; j < nums.size(); j++) {
    //         if(nums[i] + nums[j] == target) {
    //             cout<< nums[i] << " " << nums[j];
    //         }
    //     }
    // }
}

void testCharFrequency(string s)
{

    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    };

    // map does'nt preserve order, iteration order depends upon hashing order
    // In order to find first unique char in a string, we can't iterate over the map, iterate string order
    for (auto el : s)
    {
        if (mp[el] == 1)
        {
            cout << el << endl;
            break;
        }
    }
}

void twoSumHashSet(vector<int> nums, int target)
{

    // in worst case it can hold upto n elements O(n) space complexity
    unordered_set<int> seen;

    // takes O(n)
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (seen.count(complement))
        {
            cout << complement << " " << nums[i] << endl;
        }
        seen.insert(nums[i]);
    }
}

int longestConsecutive(vector<int> &nums)
{

    /*
    // Brute Force
    // O(nlogn)
    if(nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());

    int maxLen = 1;
    int len = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i - 1] == nums[i]) continue;


        if(nums[i] == nums[i - 1] + 1) {
            len++;
        } else {
            len = 1; // start new sequence
        }
        maxLen = max(len, maxLen);
    }

    return maxLen;

    */

    // Optimal Approach
    unordered_set<int> st(nums.begin(), nums.end());
    int maxLen = 1;

    for (int num : st)
    {

        // if num - 1 does not exist (iterator to num - 1 go to the end i.e. missing num - 1)
        if (st.find(num - 1) == st.end())
        {
            int curr = num;
            int len = 1;

            // if next number is found, it runs until chain breaks (iterator goes to end)
            while (st.find(num + 1) != st.end())
            {
                curr++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
    }
}

int longestSubarray(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSum_map;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        prefixSum += nums[i];

        // Case 1: subarray that sums to k start from the beginning
        if (prefixSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: check if x - k seen before
        int rem = prefixSum - k;
        if (prefixSum_map.find(rem) != prefixSum_map.end())
        {
            int len = i - prefixSum_map[rem];
            maxLen = max(maxLen, len);
        }

        // Case 3: check if x exists, if not then insert it
        if (prefixSum_map.find(prefixSum) == prefixSum_map.end())
        {
            prefixSum_map[prefixSum] = i;
        }
    }
    return maxLen;
}

int maxLength(vector<int> &arr)
{

    /*
    // Brute Force -> O(n^2)
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if(sum == 0) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;

    */

    // Optimal Approach - Using Hash maps
    // T.C = O(n)
    // S.C = O(n)
    int prefixSum = 0;
    int maxLen = 0;
    unordered_map<int, int> prefixSum_mp;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = prefixSum - 0;
        if (prefixSum_mp.find(rem) != prefixSum_mp.end())
        {
            int len = i - prefixSum_mp[rem];
            maxLen = max(maxLen, len);
        }

        if (prefixSum_mp.find(prefixSum) == prefixSum_mp.end())
        {
            prefixSum_mp[prefixSum] = i;
        }
    }
    return maxLen;
}

int main()
{

    // Number hashing
    // int n;
    // cin>> n;
    // int arr[n];
    // for(int i = 0; i < n; i++) {
    //     cin>> arr[i];
    // }

    // // suppose maximum array element is 12 -> make hash array of size 13 because there should be idx 12 present to store frequency of query 12
    // // space complexity is O(maxElement(arr) + 1)
    // int hashArr[13] = {0};

    // // pre-storing frequency before answering any query -> Takes O(n)
    // for(int i = 0; i < n; i++) {
    //     hashArr[arr[i]] += 1; // increasing count of the ith idx in hashArr for i number in query arr e.g if query number is 1, we increase count of 1st idx in hash array
    // }

    // // takes O(q) time complexity
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int number;
    //     cin >> number;

    //     // fetching - Takes contant time O(1)
    //     cout << hashArr[number] << endl;
    // }

    // // Character hashing
    // // 1) If all the characters are lowercase
    // string str;
    // cin>> str;

    // // a = 0 and z = 25, hash array mush contain the idx 25 (size 26) to store occurrence of z
    // // pre-compute
    // int hash[26] = {0};
    // for(int i = 0; i < str.size(); i++) {
    //     hash[str[i] - 'a']++;
    // }

    // int q;
    // cin >> q;
    // while(q--) {
    //     char character;
    //     cin>> character;

    //     // fetch frequency
    //     cout<< hash[character - 'a'] << endl;
    // }

    // 2) contains both upper and lower case
    // string s;
    // cin>> s;

    // int hash[256] = {0};
    // for(int i = 0; i < s.size(); i++) {
    //     hash[s[i]] += 1;
    // }

    // int q;
    // cin>> q;
    // while(q--) {
    //     char c;
    //     cin>> c;
    //     cout << hash[c] << endl;
    // }

    // What if we have 10000000000 maxElement in our array, then should we have to create an hash array of size 1 greater than it?
    // In this case unordered_maps and maps are used so that we use storage efficiently

    // int n;
    // cin>> n;
    // int arr[n];
    // for(int i = 0; i < n; i++) {
    //     cin>> arr[i];
    // }

    // map<int, int> mp;
    // // unordered_map<int, int> unorder_mp;
    // for(int i = 0; i < n; i++) {
    //     mp[arr[i]]++; // takes O(logN)
    //     // unorder_mp[arr[i]]++ // takes O(1) in best and avg case and worst take O(n) which is rare
    //  }

    // int q;
    // cin>> q;
    // while(q--) {
    //     int n;
    //     cin>> n;
    //     cout<< mp[n] << endl;
    // }

    /*
    vector<int> nums = {1, 2, 2, 1, 3};
    vector<vector<int>> ans = countFrequencies(nums);

    for(auto el : ans) {
        for(auto element : el) {
            cout<< element << " ";
        }
        cout << endl;
    }
    */

    vector<int> nums = {1, 0, 1, 2};
    cout << "Max consecutive length = " << longestConsecutive(nums) << endl;

    return 0;
}