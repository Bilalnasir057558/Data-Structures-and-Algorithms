#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
    
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

        // // T.C = O(N) + O(N) + O(N) -> O(N + M)
        // // S.C = O(N + M)
        // return ans;

    // in worst case, if all elements are unique in array, then it takes n space
    vector<vector<int>> ans;

    // in worst case, if all elements are unique in array, then it takes n space
    unordered_map<int, int> mp;


    // takes O(n) n = size of nums
    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]] += 1; // takes O(1) in best and avg case and worst case is rare
    };


    // takes O(n)  
    for(auto el : mp) {
        ans.push_back( { el.first, el.second } );
    };

    return ans;
}


int main() {

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

    vector<int> nums = {1, 2, 2, 1, 3};
    vector<vector<int>> ans = countFrequencies(nums);

    for(auto el : ans) {
        for(auto element : el) {
            cout<< element << " ";
        }
        cout << endl;
    }



    return 0;
}