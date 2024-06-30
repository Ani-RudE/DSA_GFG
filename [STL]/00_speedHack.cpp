#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Speed optimization
auto speedHack = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/* ****************************** */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")

#pragma pack(1) // For struct to remove struct size padding