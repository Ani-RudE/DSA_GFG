#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
     stack<char> s;

     for (char x : str){
          if (x=='(' || x=='[' || x=='{') //Specifically use `' '`, not `" "` . It's giving an Error Messgae upon using `" "`: operand types are incompatible ("char" and "const char *").
               s.push(x);
          else {
               
          }
     }

     return true;
}

int main()
{
     string str = "[][]{()}{}";

     cout << balancedParenthesis(str);

     return 0;
}