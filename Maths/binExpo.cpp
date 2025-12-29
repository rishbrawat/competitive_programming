#include<bits/stdc++.h>
using namespace std;

using ll = long long;


// find a's power b
ll binPow(ll a, ll b) {
   ll result = 1;

   // power is not 0
   while(b>0) {
      
      // rule b: if the power is odd we subtract one power and multiply it with the result
      if(b%2 == 1) result = result*a;

      // now apply rule one where we square the base
      a = a*a;

      // now half the power
      b = b/2;

   }

   return result;

}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   ll a = 2, b = 13;
   ll res = binPow(a, b);

   cout << "a's power b: " << res << endl;

   return 0;
}