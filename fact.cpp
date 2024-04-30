#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
        return n;
    int a = factorial(n - 1);
    int b = factorial(n - 2);
    return a + b;
}
int main()
{
    cout<<factorial(5);
}