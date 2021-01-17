#include <bits/stdc++.h>
using namespace std;

int numSquareSum(int n)
{
   int squareSum = 0;
   while (n)
   {
      squareSum += (n % 10) * (n % 10);
      n /= 10;
   }
   return squareSum;
}

//method return true if n is Happy number
bool isHappynumber(int n)
{
   int slow, fast;
   slow = fast = n;
   do
   {
      slow = numSquareSum(slow);
      fast = numSquareSum(numSquareSum(fast));
   } while (slow != fast);
   return (slow == 1);
}

bool isPrime(int n)
{
   if (n == 0 || n == 1)
   {
      return false;
   }
   else
   {
      for (int i = 2; i * i <= n; ++i)
         if (n % i == 0)
            return false;
   }
   return true;
}

int main()
{
   long long u;
   long long l;
   long long k;
   long long t_i;
   cin >> l;
   cin >> u;
   cin >> k;

   long long wyl = 0;

   for (long long i = l; (i < u && wyl < k); i++)
   {
      if (isPrime(i) && isHappynumber(i))
      {
         wyl++;
         t_i = i;
      }
   }
   if (wyl == k)
      cout << t_i << "\n";
   else
   {
      cout << "-1" << "\n";
   }

   return 0;
}