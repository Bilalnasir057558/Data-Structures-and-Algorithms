#include<bits/stdc++.h>
using namespace std;

void pairs() {
    // pairs are defined under utility header file and it is a type of container that 
    // contains a group of two elements. Used in returning coordinates, or making complex DS i.e array of pairs
    pair<int, int> p1 = {1, 3}, p3;
    cout<< p1.first << " " << p1.second << endl;

    p3.swap(p1);
    cout << p3.first << " " << p1.first << endl;

    pair<int, pair<int, int>> p2 = {10, {12, 14}};
    cout<< p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    pair<int, int> a[] = {{1, 2}, {2, 3}, {3, 4}};
    cout<< a[1].second << endl;
    for(auto el : a) {
        cout<< el.first << " " << el.second << endl;
    }
}

void vectors() {
    vector<int> v;
    int a = 5;
    v.push_back(a); // used when to append existing object (copy of an object)
    v.emplace_back(6); // used to append new data to build up the data structure
    v.push_back(7);
    v.push_back(8);
    v.pop_back();

    vector<pair<int, int>> v1;
    v1.push_back({1, 3});
    v1.emplace_back(4, 5);

    vector<int> v2(5, 100);
    vector<int> v3(5);
    vector<int> v4(v2);

    vector<int>::iterator it = v.begin(); // points to the first elements memory address
    cout<< *(it) << endl;
    it++;
    cout<< *(it) << endl;
    vector<int>::iterator itr = v.end(); // returns iterator to the very next element of the last element
    cout<< *(itr - 1) << endl; //  - 1 makes it to the last element

    // auto -> automatically infers the data type by looking at the data i.e. v.begin() returns an iterator therefor (it) is an iterator
    for(auto it = v2.begin(); it != v2.end(); it++) {
        cout<< *(it) << " ";
    }
    cout<< '\n';
    for(auto el : v2) {
        cout<< el << " ";
    }
    cout<< '\n';
    // v.erase(v.begin());
    v.erase(v.begin(), v.begin() + 2); // second parameter is exclusive i.e [start, end)

    for(auto el : v) {
        cout<< el << " ";
    }
    cout << '\n';

    vector<int> v5(4, 10);
    v5.insert(v5.begin(), {2, 3});
    v5.insert(v5.begin(), 2, 69);
    v5.pop_back();

    vector<int> v6(3, 50);
    v5.insert(v5.begin(), v6.begin(), v6.end() - 1); // first two 50 are inserted b/c v6.end() - 1 points to the last element which is not included
    v5.clear();
    cout<< v5.empty() << endl;
    for(auto el : v5) {
        cout<< el << " ";
    }
}

void lists() {
    // dynamic data structure implemented on doubly linked list, contains two pointers pointing to both ends
    // in vectors insert at start and specific positon is costly as it is singly linked list

    // in lists both side insertion and deletion is easier and less costly
    list<int> l;
    l.push_front(1); // {1}
    l.push_back(2); // { 1, 2 }
    l.pop_back(); // { 1 }
    l.emplace_front(20); // {20, 1}

    for(auto el : l) {
        cout<< el << " ";
    }
}

void stacks() {
    stack<int> st;
    st.push(1); // { 1 }
    st.emplace(2); // { 2, 1 };
    st.push(3); // {3, 2, 1};

    st.pop(); // { 2, 1 };
    cout << st.top() << endl; // 2
    cout<< st.size(); 
}

void priorityQueue() {
    // Max heap PQ - first element is largest
    priority_queue<int> pq;
    pq.push(1); // {1};
    pq.push(4); // {4, 1};
    pq.push(2); // {4, 2, 1};
    cout<< pq.top() << endl; // 4
    pq.pop();
    cout<< pq.top() << endl; // 2

    // Min heap
    priority_queue<int, vector<int>, greater<int>> p1;
    p1.push(5); // {5}
    p1.push(2); // {2, 5}
    p1.push(8); // {2, 5, 8}
    p1.push(10); // {2, 5, 8, 10}
    cout<< p1.top() << endl; // 2
    
}

void sets() {

    // set -> sorted and unique
    set<int> s = {1, 5, 2, 50};
    auto it = s.find(5);
    auto it2 = s.find(3); // gives iterator next to the last element
    s.erase(50);

    set<int> s2 = {1, 2, 3, 4, 5, 6};
    // s2.erase(s2.find(2), s2.find(4)); // {1, 4} [start, end)
    
    for(auto el : s2) {
        cout<< el << " ";
    }

    auto itr = s2.lower_bound(1); // iterator to 1
    cout<< *(itr) << endl;

    auto itr2 = s2.upper_bound(3); // iterator to 4;
    cout<< *(itr2) << endl;

    // unordered set => unique
    // multiordered set => sorted
    
}

void maps() {
    // maps => keys are unique and sorted
    map<int, int>m;
    m.insert({2, 4});
    m[1] = 2;

    map<int, pair<int, int>> m1;
    m1[2] = {3, 5};
    m1.insert({1, {2, 4}}); 

    for(auto it : m1) {
        cout<< it.first << " " << it.second.first << " " << it.second.second << endl;
    }
    cout << endl;

    auto it = m1.find(2);
    cout<< it->second.first << " " << it->second.second << endl;
}


// comparator => my way of sorting elements
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // second element is same
    if(p1.first > p2.first) return true;
    return false;
}

void algorithms() {
    vector<int> v = {4, 5, 2, 1};
    // sort(v.begin(), v.end());
    sort(v.begin(), v.begin() + 3);
    

    for(auto el : v) {
        cout<< el << " ";
    }
    cout << '\n';

    pair<int, int> a[] = { {1, 2} , {2, 1} , {4, 1} };
    // sort it a/c to the 2nd el
    // if 2nd el is same, then sort a/c to descending 1st element
    sort(a, a + 3, comp);
    for(auto el : a) {
        cout<< el.first << " " << el.second << endl;
    }

    int num = 7;
    int cnt = __builtin_popcount(num);
    cout<< cnt << endl;

    string s = "123";
    do {
        cout<< s << endl;
    } while(next_permutation(s.begin(), s.end())); // returns true when next larger permutation exists
}

int main() {
    // pairs();
    // vectors();
    // lists();
    // stacks();
    // sets();
    // maps();
    algorithms();
    return 0;
}