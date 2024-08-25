#include <bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &st, stack<int> &newSt) {
     if (st.empty()) {
          return;
     }
     
     newSt.push(st.top());
     st.pop();
     reverseStack(st, newSt);
}

void reverseStack2(stack<int> &st) {
     if (st.empty()) {
          return;
     }
     
     int temp = st.top();
     st.pop();
     reverseStack2(st);
     st.push(temp);

     return;
}

int main() {
     // vector<int> vct = {1,2,3,4,5};
     vector<int> vct = {5,6,1,3,7};
     stack<int> st;
     for (auto &i: vct) {
          st.push(i);
     }

     stack<int> newSt;
     reverseStack(st, newSt);

     while (!newSt.empty()) {
          cout<<newSt.top()<<" ";
          newSt.pop();
     }
     cout<<endl;

/* -------------------- */

     vector<int> vct2 = {5,6,1,3,7};
     stack<int> st2;
     for (auto &i: vct2) {
          st2.push(i);
     }

     reverseStack2(st2);
     while (!st2.empty()) {
          cout<<st2.top()<<" ";
          st2.pop();
     }


     return 0;
}

inrcud hwo are t <int .