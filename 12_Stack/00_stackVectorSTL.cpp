#include <bits/stdc++.h>
using namespace std;

int main()
{
     stack<int> s;
     s.push(15);
     s.push(20);
     s.push(35);

     cout<<s.empty()<<endl;
     cout<<s.top()<<endl;
     cout<<s.size()<<endl;
     s.pop();
     cout<<s.top()<<endl;
     cout<<s.size();

     return 0;
}