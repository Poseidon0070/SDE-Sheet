// https://codeforces.com/blog/entry/73558

// There are total 5000 workers with different work day. Find two workers which have maximum inatersection of work day in 365 days.
// const k = MAX_DAYS/64+1;
//     vector<vector<long long>> v(workers,vector<long long>(k+1)); 
//     int intersection(int i,int j){
//     int total = 0;
//     for(int z=0;z<k;z++){
//         total += __builtin_popcount(v[i][z]&v[j][z]);
//     }
// }

// this is a possible way to handle some cases but cannot handle shifts and complesx to code in harder problems

// bitset<D> of some length D is binary number with that D bits and is capable to perform bitwise operation and shift

// #include <bits/stdc++.h>
// using namespace std;
// const int MAX_D = 365; // Define MAX_D to some value
// int n = 10; // Example 
// int main()
// {
//     std::vector<std::bitset<MAX_D>> v(n, std::bitset<MAX_D>());
//     return 0;
// }

// a = bitset<365>
// we can think it a longer binary mask or set that is able to give us quick intersection, number of element, shifting operation etc
// instead __popcount() , we have a.count()
// we can do a&b, a >> 5 etc....

// eg1.
// you are given N <= 1e7 numbers, each b/w 0 and 1e9. how many different value appear in the sequence.
// we can create a boolean array of size 1e9+1 , but each boolean take 1 byte causing total 1 GB space.
// we can create a bitset instead whith 1e9+1 bits and it will take memeory less 8 times as 8 bit = 1 byte.?

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int MX = 1e5;
// // 1 2 5 6 33 8
// signed main()
// {
//     int n; cin >> n;
//     bitset<MX+1> v;
// // TC to create this is MX/32 OR MX/64
//     for(int i{};i<n;i++){
//         int x; cin >> x;
//         v[x] = true;
//     }
//     cout << v.count() << "\n";
//     return 0;
// }


// eg2.
// you are given N <= 1000, each with some weight w[i]. Is there a subset with total weight exactly W. W <= 1e6; 

#include <bits/stdc++.h>
using namespace std;
#define _8bits  bitset<8>
#define _16bits  bitset<16>
#define _32bits  bitset<32>
#define _64bits  bitset<64>
int main()
{
    // convert decimal to binary using bitset
    cout << _8bits(5) << "\n";
    cout << _16bits(5) << "\n";
    cout << _32bits(5) << "\n";
    cout << _64bits(5) << "\n";
    cout << "--------------------------------------------------------" << "\n";
    _32bits set1;  // inits all to 0
    cout << set1 << "\n";
    // any return true if any bit is 1 or false otherwise
    cout << boolalpha << set1.any() << "\n";
    // none return true if all bit is 0 or false otherwise
    cout << boolalpha << set1.none() << "\n";
    // count to get number of 1
    cout << set1.count() << "\n";
    // count ans size to get number of 0
    cout << set1.size()-set1.count() << "\n";
    cout << "--------------------------------------------------------" << "\n";
    _32bits set2(21);  // inits all to 0
    cout << set2 << "\n";
    // any return true if any bit is 1 or false otherwise
    cout << boolalpha << set2.any() << "\n";
    // none return true if all bit is 0 or false otherwise
    cout << boolalpha << set2.none() << "\n";
    // count to get number of 1
    cout << set2.count() << "\n";
    // count ans size to get number of 0
    cout << set2.size()-set2.count() << "\n";
    cout << "--------------------------------------------------------" << "\n";
    _8bits set3(167);
    for(int i{};i<set3.size();i++){
        cout << set3.test(i) << " ";
    }
    return 0;
}