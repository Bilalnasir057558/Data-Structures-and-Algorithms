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

int singleNumber(vector<int> &nums)
{

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
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int longestSubArrayToSum(vector<int> nums, int k)
{

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

    while (right < nums.size())
    {
        curr_sum += nums[right];

        while (curr_sum > k && left <= right)
        {
            curr_sum -= nums[left];
            left++;
        }

        if (curr_sum == k)
        {
            max_len = max(right - left + 1, max_len);
        }

        right++;
    }
    return max_len;
}

vector<int> twoSum(vector<int> &nums, int target)
{

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
    while (left < right)
    {
        if (nums[left] + nums[right] < target)
        {
            left++;
        }
        else if (nums[left] + nums[right] > target)
            right--;
        else
            return {left, right};
    }

    return {-1, -1};
}

void sortZeroOneTwo(vector<int> &nums)
{
    /*
    // Brute Force -> O(2n) -> iterations are more
    int zeros = 0, ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zeros++;
        else if (nums[i] == 1)
            ones++;
        else
            twos++;
    }

    int i = 0;
    while(zeros > 0) {
        nums[i] = 0;
        i++;
        zeros--;
    }
    while(ones > 0) {
        nums[i] = 1;
        i++;
        ones--;
    }
    while(twos > 0) {
        nums[i] = 2;
        i++;
        twos--;
    }

    */

    // Optimal Approach -> O(n) complexity same as brute but less iterations
    int low = 0, mid = 0, high = nums.size() - 1;

    // loop until pointers don't cross means no elements in unsorted part
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int majorityElement(vector<int> &nums)
{
    int element = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i]; // giving throne to next person, previous person's army is wiped out
        }

        if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return element;
}

int maxSubArraySum(vector<int> &nums)
{

    // Brute Force -> O(n^3)
    /*
    int max_sum = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i; j < nums.size(); j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += nums[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
    */

    // Better Approach -> O(n^2)
    /*
    int max_sum = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
    */

    // Optimal Approach - Kadane's Algorithm -> O(n)
    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        current_sum += nums[i];
        max_sum = max(current_sum, max_sum);

        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }

    return max_sum;
}

int maxSubArrayElements(vector<int> &nums)
{
    int max_sum = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];

        if (sum > max_sum)
        {
            max_sum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
            start = i + 1; // when sum is zero, start fresh from the next element
        }
    }

    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << nums[i] << " ";
    }
    cout << '\n';

    return max_sum;
}

int bestTimeToBuyAndSell(vector<int> &prices)
{
    int max_profit = 0;
    int mini = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - mini;
        max_profit = max(max_profit, profit);
        mini = min(mini, prices[i]);
    }

    return max_profit;
}

vector<int> leaders(vector<int> &nums)
{
    /*
    vector<int> leaders;
    if(nums.empty()) return leaders;


    for (int i = 0; i < nums.size() - 1; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j]) {
                isLeader = false;
                break;
            }

        }
        if(isLeader) leaders.push_back(nums[i]);
    }
    leaders.push_back(nums[nums.size() - 1]);
    return leaders;

    */

    // Optimal Approach
    // T.C = O(n), S.C = O(n) in worst case b/c the extra space depends on input size, otherwise O(1) b/c extra space is used only for storing not solving
    int n = nums.size();
    if (n == 0)
        return {};
    vector<int> leaders;
    int maxi = nums[n - 1];
    leaders.push_back(maxi);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            leaders.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

vector<int> rearrageArray(vector<int> &nums)
{

    /*
    // Brute Force -> O(n + n/2) , S.C = 0(n)
    vector<int> pos, neg;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) neg.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }

    for(int i = 0; i < (nums.size() / 2); i++) {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }

    return nums;
    */

    /*
    // Optimal Approach
    vector<int> ans(nums.size(), 0);
    int negIdx = 1, posIdx = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) {
            ans[negIdx] = nums[i];
            negIdx += 2;
        } else {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
    }

    return ans;
    */

    // 2nd Variety => no. of pos and neg elements are not always equal
    // T.C = O(n), S.C = O(n) + O(n) = O(n);
    vector<int> neg, pos;
    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }

    for (int i = 0; i < min(neg.size(), pos.size()); i++)
    {
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }

    // if(pos.size() > neg.size()) {
    //     int idx = neg.size() * 2;
    //     for(int i = neg.size(); i < pos.size(); i++) {
    //         ans[idx] = pos[i];
    //         idx++;
    //     }
    // } else {
    //     int idx = pos.size() * 2;
    //     for(int i = pos.size(); i < neg.size(); i++) {
    //         ans[idx] = neg[i];
    //         idx++;
    //     }
    // }

    // General form of above if else
    int minSize = min(neg.size(), pos.size());
    int maxSize = max(neg.size(), pos.size());

    int idx = minSize * 2;
    for (int i = minSize; i < maxSize; i++)
    {
        ans[idx++] = (pos.size() > neg.size()) ? pos[i] : neg[i];
    }

    return ans;
}

void markRow(vector<vector<int>> &matrix, int n, int row)
{
    for (int j = 0; j < n; j++)
    {
        if (matrix[row][j] != 0)
        {
            matrix[row][j] = -9999999;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int m, int col)
{
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -9999999;
        }
    }
}

void setZeros(vector<vector<int>> &matrix)
{

    /*
    // Brute Force T.C = O(m * n) * O(m + n)
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                markRow(matrix, n, i);
                markCol(matrix, m, j);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -9999999) {
                matrix[i][j] = 0;
            }
        }
    }

    */

    // Better Approach T.C = O(m + n), S.C = O(m + n)
    /*
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }

    */

    // Optimal Approach T.C = O(m * n), S.C = O(1);
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;

    // Mark 1st row and 1st col, if zero is found
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {

                // mark ith row
                matrix[i][0] = 0;

                // mark jth col
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0; // first col tracker
                }
            }
        }
    }

    // updating inner cells
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // update first row
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // update first column
    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;

    int top = 0, left = 0;
    int bottom = m - 1, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {-1, 2, 3, 4, -3, 1};
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

    // vector<int> ans = twoSum(v, 8);

    // sortZeroOneTwo(v);

    // for (auto el : v)
    // {
    //     cout << el << " ";
    // }
    // cout << "\n";

    // int maj_el = majorityElement(v);
    // cout << "Majority Element " << maj_el << endl;

    // int maxSum = maxSubArraySum(v);
    // int maxSum = maxSubArrayElements(v);
    // cout << "Maximum subarray sum = " << maxSum << endl;

    // int maxProfit = bestTimeToBuyAndSell(v);
    // cout << "Maximum Profit = " << maxProfit << endl;

    // vector<int> ans = leaders(v);

    // vector<int> ans = rearrageArray(v);
    // for (auto el : ans)
    // {
    //     cout << el << " ";
    // }

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     };
    //     cout << endl;
    // }

    // setZeros(matrix);
    vector<int> ans = spiralOrder(matrix);

    for(auto el : ans) {
        cout << el << " ";
    }

    cout << '\n';
    return 0;
}
