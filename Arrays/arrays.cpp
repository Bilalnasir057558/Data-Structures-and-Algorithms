#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &nums)
{

    // Brute Force
    // T.C = O(nlogn), S.C = O(1)
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() - 1];

    // Optimal Approach
    // T.C = O(n), S.C = O(1)
    int maxElement = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > maxElement)
            maxElement = i;
    }

    return maxElement;
}

int secondLargestElement(vector<int> &nums)
{

    // Brute Force
    // T.C = O(n), S.C = O(1);
    // int largest = INT_MIN, second_largest = INT_MIN;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > largest)
    //         largest = nums[i];
    // }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > second_largest && nums[i] != largest)
    //     {
    //         second_largest = nums[i];
    //     }
    // }

    // if (second_largest > INT_MIN)
    // {
    //     return second_largest;
    // }
    // else
    // {
    //     return -1;
    // }

    // Optimal Approach with a single loop
    // T.C = O(n), S.C = O(1)
    int largest = INT_MIN, second_largest = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        // if any element greater than largest is found, we make our previour largest the second largest and largest the current element
        if (nums[i] > largest)
        {
            second_largest = largest;
            largest = nums[i];

            // else if any element greater than the 2nd largest is found which is not the largest, then we just found the 2nd largest
        }
        else if (nums[i] > second_largest && nums[i] != largest)
        {
            second_largest = nums[i];
        }
    }

    if (second_largest > INT_MIN)
    {
        return second_largest;
    }
    else
        return -1;
}

bool isSorted(vector<int> &nums)
{

    // Brute Force
    // O(n^2)
    // for(int i = 0; i < nums.size() - 1; i++) {
    //     for(int j = i + 1; j < nums.size(); j++) {
    //         if(nums[j] > nums[i]) return false;
    //     }
    // }

    // return true;

    // Optimal Approach
    // T.C = O(n), S.C = O(1)
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        // if previous element is greater than the next element, means they are not in ascending order
        if (nums[i - 1] > nums[i])
            return false;
    }
    return true;
}

int removeDuplicates(vector<int> &nums)
{
    // set<int> s;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     s.insert(nums[i]);
    // }

    // return s.size();

    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] > nums[i])
        {                          // we found a new unique
            nums[i + 1] = nums[j]; // place it next to our current unique
            i++;
        }
    }
    return i + 1;
}

void rotateArrayByOne(vector<int> &nums)
{
    int first = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = first;
}

void rotateArrayLeftByK(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    // Brute Force
    vector<int> temp(k);

    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    }

    for (int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    };

    for (int i = 0; i < k; i++)
    {
        nums[n - k + i] = temp[i];
    }

    // Optimal Solution
    // reverse(nums.begin(), nums.begin() + k);
    // reverse(nums.begin() + k, nums.end());
    // reverse(nums.begin(), nums.end());
}

void rotateArrayRightByK(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    // Brute Force
    // vector<int> temp(k);

    // // store last k elements in a temporary vector
    // for(int i = n - k; i < n; i++) {
    //     temp[i - n + k] = nums[i];
    // }

    // // shifting n - k elements to the right
    // for(int i = n - k - 1; i >= 0; i--) {
    //     nums[i + k] = nums[i]; // moving k times forward
    // };

    // // copying last k elements at the front of the array
    // for(int i = 0; i < k; i++) {
    //     nums[i] = temp[i];
    // }

    // Optimal Solution
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

void moveZeroes(vector<int> &nums)
{

    // Brute Force 1 -> T.C = O(n^2)
    // int count = 0;
    // for(int i = 0; i < nums.size(); i++) {
    //     if(nums[i] == 0) {
    //         count++;
    //         for(int j = i + 1; j < nums.size(); j++) {
    //             nums[j - 1] = nums[j];
    //         }
    //         i--;
    //     }
    // }

    // for(int i = nums.size() - count; i < nums.size(); i++) {
    //     nums[i] = 0;
    // }

    // Brute Force 2 -> T.C = O(n), S.C = O(n)
    // vector<int> temp(nums.size());
    // int idx = 0;
    // for(int i = 0; i < nums.size(); i++) {
    //     if(nums[i] != 0) {
    //         temp[idx] = nums[i];
    //         idx++;
    //     }
    // }
    // nums = temp;

    // Optimal Approach
    int j = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

void addUnique(vector<int> &result, int el)
{
    if (result.empty() || result.back() != el)
    {
        result.push_back(el);
    }
}
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{

    /*
    // Brute Force Using Map
    // T.C = O((m+n)log(m+n))
    // S.C = O(m+n)
    map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < nums1.size(); i++) {
        mp[nums1[i]]++;
    }

    for(int j = 0; j < nums2.size(); j++) {
        mp[nums2[j]]++;
    }

    for(auto &it : mp) {
        ans.push_back(it.first);
    }

    return ans;
    */

    // Brute Force Using Set
    // T.C = O((m+n)log(m+n))
    // S.C = O(m+n)
    set<int> st;
    for (int i = 0; i < nums1.size(); i++)
    {
        st.insert(nums1[i]);
    }

    for (int j = 0; j < nums2.size(); j++)
    {
        st.insert(nums2[j]);
    }

    vector<int> ans(st.begin(), st.end());

    return ans;

    // Optimal Approach
    /*
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            addUnique(result, nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            addUnique(result, nums1[i]);
            i++;
        }
        else
        {
            addUnique(result, nums2[j]);
            j++;
        }
    }

    while (i < nums1.size())
    {
        addUnique(result, nums1[i]);
        i++;
    }

    while (j < nums2.size())
    {
        addUnique(result, nums2[j]);
        j++;
    }

    return result;
    */
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, max_count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            count++;
        else
            count = 0;

        // maximum of current streak and previous longest streak so far
        // if current streak is 3 and previous longest is 2, then we found our new longest that's why max(3, 2) -> 3
        // if current streak is less than the previous longest, then previous longest is the longest so far
        max_count = max(count, max_count);
    }

    return max_count;
}

int singleNumber(vector<int> &nums) {

    /*
    // Brute force -> O(n^2)
    for(int i = 0; i < nums.size(); i++) {
        int count = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }
        if(count == 1) return nums[i];
    }

    // this line should never be reacher, only to happy the compiler
    return -1;
    */

    /*
    // Better Appraoch -> T.C = O(N+M), S.C = O(M+1); M is the maxElement
    int max_element = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        max_element = max(nums[i], max_element);
    }

    vector<int> hash_array(max_element + 1, 0);
    for(int i = 0; i < nums.size(); i++) {
        hash_array[nums[i]]++;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(hash_array[nums[i]] == 1) return nums[i];
    }

    return -1;
    */

    // Optimal -> T.C = O(n)
     int xorr = 0;
    for(int i = 0; i < nums.size(); i++){
        xorr = xorr ^ nums[i];
    }
    return xorr;
}


int longestSubArrayToSum(vector<int> nums, int k) {

    // Better Approach -> O(n^2) , Brute includes third loop and goes to O(n^3)
    /*
    int max_length = 0;
    for(int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if(sum == k) {
                max_length = max(j - i + 1, max_length);
            }
        }
    }
    return max_length;
    */

    /*
    // Optimal Approach
    unordered_map<int, int> prefix_sum_mp; // [prefixSum -> index]
    int current_sum = 0;
    int max_len = 0;

    for(int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];

        // Case 1: Sub-array starts from index 0
        if(current_sum == k) {
            max_len = max(i + 1, max_len);
        }

        // Case 2: Check if (curr_sum - k) happened before
        int rem = current_sum - k;
        if(prefix_sum_mp.find(rem) != prefix_sum_mp.end()) {
            int length = i - prefix_sum_mp[rem];
            max_len = max(length, max_len);
        }

        // Case 3: Only store the first occurrence of curr_sum in map
        if(prefix_sum_mp.find(current_sum) == prefix_sum_mp.end()) {
            prefix_sum_mp[current_sum] = i;
        }
    }
    return max_len;
    */

    // Optimal Approach for +ve array (Sliding window approach)
    // T.C = O(n)
    int curr_sum = 0;
    int max_len = 0;
    int left = 0, right = 0;

    while(right < nums.size()) {
        curr_sum += nums[right];

        while(curr_sum > k && left <= right) {
            curr_sum -= nums[left];
            left++;
        }

        if(curr_sum == k) {
            max_len = max(right - left + 1, max_len);
        }

        right++;
    }
    return max_len;
}

vector<int> twoSum(vector<int> &nums, int target) {

    /*
    // Brute Force -> O(n^2)
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
    */

    /*
    // Optimal Approach with extra space -> O(n), S.C = O(n)
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(mp.find(complement) != mp.end()) 
            return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
    */

    // Optimal Solution without extra space -> only if the array is already sorted
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        if(nums[left] + nums[right] < target) {
            left++;
        } else if(nums[left] + nums[right] > target) right--;
        else return {left, right};
    }

    return {-1, -1};
}

int main()
{
    vector<int> v = {1, 4, 7, 9};
    // cout << "Largest Element =  " << largestElement(v) << endl;

    // cout << "Second Largest Element = " << secondLargestElement(v) << endl;

    // if (isSorted(v))
    // {
    //     cout << "Sorted" << endl;
    // }
    // else
    // {
    //     cout << "Not Sorted" << endl;
    // }

    // cout << "Length are removing duplicates = " << removeDuplicates(v) << endl;

    // rotateArrayByOne(v);

    // rotateArrayLeftByK(v, 3);

    // rotateArrayRightByK(v, 3);

    // moveZeroes(v);

    // for (auto el : v)
    // {
    //     cout << el << " ";
    // }
    // cout << '\n';

    // vector<int> v1 = {1, 2, 3, 4, 5};
    // vector<int> v2 = {1, 2, 7};
    // vector<int> ans = unionArray(v1, v2);

    // for (auto el : ans)
    // {
    //     cout << el << " ";
    // }
    // cout << '\n';

    // cout<< "Max Consecutive 1's = " << findMaxConsecutiveOnes(v) << endl;

    // cout<< "Element occurring once = " << singleNumber(v);

    // cout<< "Length of Longest Sub-array that sums to k = " << longestSubArrayToSum(v, 6) << endl;

    vector<int> ans = twoSum(v, 8);
    for(auto el : ans) {
        cout << el << " ";
    }
    cout<< "\n";
    return 0;
}
