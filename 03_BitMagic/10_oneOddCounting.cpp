//Find out the number that occurs odd number of times in the array
/*
Naive approach is to use two loops, and iterate over them by initializing a `count` variable as `count=0`
Time complexity will be O(n2) then.
Naive approach - https://cdn.discordapp.com/attachments/1210088566542311444/1210157061426380830/image.png?ex=65e98997&is=65d71497&hm=0322801c1350410dd08980e7005a36698588cf395ef1f7d23055f52530da20ad&


Best Approach - Use XOR Operation, it is bcoz:    X^0=X     X^X=0

So running a loop and doing XOR of every element will result in the answer as the element that occurs odd number of times, if all elements occur even number of times then the answer will be "0".
Time comp: O(n)          Space comp: O(1)

My approach is to to use map.
*/

#include <bits/stdc++.h>
using namespace std;

int oddCountUsingXOR(int arr[], int n)
{
     int key=arr[0];
     
     for (int i=1; i<n; i++)
     {
          key^=arr[i];
     }
     
     return key;
}

int main()
{
     int n;
     cin>>n;
     
     int arr[n];
     for (int i=0; i<n; i++)
          cin>>arr[i];
     
     cout<<"Answer: "<<oddCountUsingXOR(arr, n);

     return 0;
}