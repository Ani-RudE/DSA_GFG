#include <iostream>
#include <deque>
using namespace std;

int main()
{
     deque<int> dq={10,20,30};
     cout<<dq.size()<<endl;
     dq.push_back(40);
     dq.push_front(5);
     cout<<dq.size()<<endl;
     cout<<dq.front()<<" "<<dq.back()<<endl;

     for (auto x:dq)
     {
          cout<<x<<" ";
     }

     cout<<endl;
     dq.pop_back();
     dq.pop_front();
     cout<<dq.size()<<endl;
     cout<<dq.front()<<" "<<dq.back()<<endl;

     return 0;
}