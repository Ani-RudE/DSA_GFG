#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
     stack<char> s;

     for (char x : str){
          if (x=='(' || x=='[' || x=='{') //Specifically use `' '`, not `" "` . It's giving an Error Messgae upon using `" "`: operand types are incompatible ("char" and "const char *").
               s.push(x);
          else if (s.empty()==false) {
               if (s.top()=='[' && x==']')
                    s.pop();
               else if (s.top()=='(' && x==')')
                    s.pop();
               else if (s.top()=='{' && x=='}')
                    s.pop();
               else
                    return false;
          }
     }

     if (s.empty()==true)
          return true;
     
     return false;
}

int main()
{
     string str = "[][]{()}{}}";

     cout << isBalanced(str);

     return 0;
}