# C++ STL Notes

## 1. Introduction
The **Standard Template Library (STL)** in C++ provides pre-built data structures and algorithms, making coding efficient.
It makees C++ code efficient and reduces code complexity.

It has four main components:
- **Containers** – Store data (`vector`, `list`, `set`, `map`, etc.).
- **Iterators** – Traverse elements in containers.
- **Algorithms** – Sorting, Searching, etc.
- **Function Objects (Functors)** – Functions inside objects.

---
#include <bits/stdc++.h>
using namespace std;

## ** Pairs **
void explainPairs()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second; // 1 3

    pair<int, pair<int, int>> p = {1, {3, 4}};
    cout << p.first << " " << p.second.second << " " << p.second.first; // 1 4 3

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second; // 5
}
-----------------------------------------------------------------------------------------------------------------------------------
## ** Vector **
void explainVectors()
{
     vector<int> v;
     v.push_back(1);
    v.emplace_back(2); // push_back and emplace_back works the same
    // but generally emplace_back is faster than push_back()

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v(5, 100); //  {100, 100, 100, 100, 100} ; 5 is size of v and 100 is the value to be stored in v

    vector<int> v(5); // {0, 0, 0, 0, 0}

    vector<int> v1(5, 10); // {10, 10, 10, 10, 10}
    vector<int> v2(v1); // {10, 10, 10, 10, 10} ; copy of v1

    iterators point to the memory address

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);  
      // v is {10, 20, 30, 40, 50}

    vector<int>::iterator it = v.begin();  // iterator points to the memory where element is stored.
    it++;
    cout << *(it) << " "; // 20

    it = it + 2;
    cout << *(it) << " "; // 50
    
    vector<int>::iterator it = v.end();  // * end will not point to last elemnt
    it will point right after last element

    vector<int>::iterator it = v.rend(); // reverse end
    vector<int>::iterator it = v.rbegin(); // reverse begin

    cout << v[0] << " " << v.at(0) << " "; // 10 10

    cout << v.back() << " "; // 50

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " "; // 10 20 30 50
    }

    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " "; // 10 20 30 50
    }

    cout << endl;

    for (auto it : v)
    {
        cout << it << " "; // 10 20 30 50
    }
------------------------------------------------------------------------------------------------------------------
    *** Deletion of vectors ***
        
    {10,20,30,40,50}

    v.erase(v.begin() + 1);
    v.erase(v.begin() + 1, v.begin() + 3); // [start,end)

      - v.erase(v.begin() + index) →  // Removes a single element and shifts elements left.
      - v.erase(v.begin() + start, v.begin() + end) → // Removes a range of elements.
      - v.erase(remove(v.begin(), v.end(), value), v.end()) →  // Removes all occurrences of a value.
      - C++20 Only: erase(v, value); →  // Removes all occurrences in a cleaner way
      - Returns an iterator →  // Useful when working inside loops.
---------------------------------------------------------------------------------------------------------------------
    *** Insert Function ***

    vector<int> v(2, 100);          // {100,100}
       // - for adding one element
    v.insert(v.begin(), 300);      // {300, 100, 100}
       // -- for more elements but same ; eg- three 10's
    v.insert(v.begin() + 1, 3, 10); // {300, 10, 10, 10, 100, 100}
        
    vector<int> copy(2, 50);                                     // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    cout << v.size(); // 7  ; size of vector

    v.pop_back(); //{50, 50, 300, 10, 10, 100}  removes last element
    v.pop_front; //{50, 300, 10, 10, 100}  removes first element
    // v1 --> {10,20};  
    // v2 --> {30,40};
    v1.swap(v2); // v1 --> {30,40}, v2 --> {10,20}

    v.clear(); // erases the entire vector

    cout << v.empty(); // 1
       
    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
}
------------------------------------------------------------------------------------------------------------------------------------------
void explainList()
{
    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}
    ls.emplace_front(1); // {1,5,2,4}

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);      //{1}
    dq.emplace_back(2);  //{1,2}
    dq.push_front(4);    //{4,1,2}
    dq.emplace_front(3); //{3,4,1,2}

    dq.pop_back();  // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();

    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend , clear, insert, size, swap
}
-----------------------------------------------------------------------------------------------------------------------------------------
//***Stack --> LIFO (Last in First out)

void explainStack() // O(1) --> everythig happens in constant time
{           // LIFO - Last in First Out
            // imagine it as stacking books on top of each, the last one u put will be on top.
    stack<int> st;
    st.push(1);    // {1}                  |   5   | - top
    st.push(2);    // {2,1}                |   3   |
    st.push(3);    // {3,2,1}              |   3   |
    st.push(3);    // {3,3,2,1}            |   2   |
    st.emplace(5); // {5,3,3,2,1}          |___1___|

    cout << st.top(); // 5
    // when st.pop() it deletes

    st.pop();        // st looks like {3,3,2,1}
    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty(); // 0

    stack<int> st1, st2;
    st1.swap(st2);
}
------------------------------------------------------------------------------------------------------------------------------------------
void explainQuue()
{ // similar to stack but FIFO --> First in First Out
    // imagine it like people in line for buying tickets, first one on line gets first
    // O(1) --> all happens in constant time
    queue<int> q;
    q.push(1);    //{1}
    q.push(2);    // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;    // 9 --> here back will mean 4
    cout << q.back(); // 9

    // Q is {1,2,9}
    cout << q.front(); // 1

    q.pop(); // {2,9} --> deletes the front one

    cout << q.front(); // 2

    // size swap empty same as stack
}

/*
    ** Priority Queue **
    -> that has the largest value statys at the top
    push --> O(log n)
    top --> O(1)
    pop --> O(log n)
*/
---------------------------------------------------------------------------------------------------------------------------------------------
void explainPQ()       // priority queue
{
    // Maximum Heap
    priority_queue<int> pq;

    pq.push(5);    // {5}
    pq.push(2);    // {5,2}
    pq.push(8);    // {8,5,2}
    pq.emplace(10); // {10,8,5,2}
 
    cout << pq.top(); // 10

    pq.pop(); // {8,5,2} --> 10 poped (removed)

    cout << pq.top(); // 8

    // size, swap, empty function same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pqmin; // -> for minimum element at the top  

    pqmin.push(5);    // {5}
    pqmin.push(2);    // {2,5}
    pqmin.push(8);    // {2,5,8}
    pqmin.emplace(10); // {2,5,8,10}

    cout << pqmin.top(); // 2
}
    //   Time Complexity - push/pop : O(log n)
    //                     top : O(1)

    // ** Set Container **
    // -> It stores everything in the sorted order
    // -> Stores unique // *UNIQUE

--------------------------------------------------------------------------------------------------------------------------------------------------------
void explainSet() // O(lon n)
{
    set<int> st;

    st.insert(1);    // {1}
    st.emplace(2); // {1,2}
    st.insert(2);    // {1,2}
    st.insert(4);    // {1,2,4}
    st.insert(3);    // {1,2,3,4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size()
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // treturs to the iterator which point to the 3

    // {1, 2, 3, 4, 5}
    it = st.find(6); // if an element is not here in the set ,
    // it will always return st.end(); --> an iterator which point to right after the end

    // {1,4,5}
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt = st.count(1); // if 1 occerence it will gives 1 nor 0

    it = st.find(3);
    st.erase(it); // it takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1,4,5} [first, last)

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does

    // This is the syntax
    it = st.lower_bound(2);

    it = st.upper_bound(3);
}
-------------------------------------------------------------------------------------------------------------------------------------------------
void explainMultiSet()
{
    // everything is same as set
    // only stores duplicate elements also

    multiset<int> ms;

    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1); // -> counts number of 1 in the multiset

    // only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(2)); // erase(start address, end address) // errase both of them

    // rest of all functions same as set
}
------------------------------------------------------------------------------------------------------------------------------------------------------
void explainUSet()
{                                   // unordered set
    unordered_set<int> st; // everything is similar to set i.e unique

    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above, it does not stores in any
    // particular order it has a better complexity  // O(1) ; blue moon happens in worst case O(N)
    // than set in most cases, except some when collision happens
}
--------------------------------------------------------------------------------------------------------------------------------------------------------
void explainMap()
{
    // * map stores unique keys in sorted order
    // values can be duplicate
    map<int, int> mpp; // {key,value}

    // map<int, pair<int, int>> mpp; // here key is integer, value is 2 integer

    // map<pair<int, int>, int> mpp; // here key is 2 integer, value is 1 integer

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({2, 4});

    // mpp[{2, 3}] = 10;

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl; // 1 2, 2 4, 3 1
    }

    cout << mpp[1] << endl; // 2
    cout << mpp[5] << endl; // 0

    auto it = mpp.find(3);
    // cout << *(it).second;

    it = mpp.find(5); // if 5 not there it point to nothing but mpp.end();
    // .end() means after the mpp

    it = mpp.lower_bound(2);
    it = mpp.upper_bound(3);

    // erase(), swap(), size(), empty(), are same as above
}
------------------------------------------------------------------------------------------------------------------------------------------------
void explainMultimap()
{
    // everything is same as map, only it can store multiple keys
    // only mpp[key] can not be used here
}
------------------------------------------------------------------------------------------------------------------------------------------------
void explainUnorderedMap()
{
    // unique keys but not stored
    // same as set and unordered_Set differnce.
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // they are same

    if (p1.first > p2.first)
        return true;
    return false;
}
------------------------------------------------------------------------------------------------------------------------------------------------
void explainExtra()
{

    sort(a, a + n); // [start,end)
    sort(v.begin(), v.end());

    sort(a + 2, a + 4); // we can sort a portion

    sort(a, a + n, greater<int>); // sort in descending order

    // pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in decreasing

    sort(a, a + n, comp);  // comp in line 380. it is a bool function

    int num = 7;
    int cnt = __builtin_popcount(num); // returns 3 , the number of set bits
    // 1 1 1
    cout << cnt << endl; //3

    long long numll = 165786578687;
    cnt = __builtin_popcountll(numll); // if the number is long long
    cout<<cnt<<endl;
    

    string s = "123";
    sort(s.begin(), s.end()); // always start from sorted

    do
    {
        cout << s << endl; // 123, 132, 213, 231, 312, 321
    } while (next_permutation(s.begin(), s.end()));
    

    int arr[] = {4, 2, 8, 1};
    int maxi = *max_element(arr, arr + 4);
    // without * gives max elemement address ; with * gives element
    cout << maxi << endl; //8

    int mini = *min_element(arr, arr + 4);
    //  without * gives min elemement address ; with * gives element
    cout << mini << endl; //1
}
------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    // explainPairs();
    // explainVectors();
    // explainList();
    // explainDeque();
    // explainStack();
    // explainQuue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainUSet();
    // explainMap();
    // explainMultimap();
    // explainUnorderedMap();
    // explainExtra();

    return 0;
}

// its enough :)
