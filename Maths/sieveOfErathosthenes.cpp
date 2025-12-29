#include<iostream>
#include<vector>
using namespace std;

vector<bool>isPrime;

// O(n log log n)
void sieve(int n) {
   // we assume that all the values are prime numbers
   isPrime.assign(n+1, true);
   isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

   // iterate to sqrt(n)
   for(int i = 2; i*i <= n; ++i) {
      if(isPrime[i]) {
         for(int j = i*i; j<= n; j+=i) {
            isPrime[j] = false;
         }
      }
   }
}
int main() {
   int MAX = 1e5;
   // compute primes up to MAX, then print them
   sieve(MAX);
   for(int i = 0; i <= MAX; ++i) {
      if(isPrime[i]) {
         cout << i << ' ';
      }
   }
   cout << endl;

   // check an individuak
   cout << std::boolalpha << isPrime[200];

   return 0;
}