#include<iostream>
#include<vector>
using namespace std;

vector<bool>isPrime;

void sieve(int n) {
   // we assume that all the values are prime numbers
   isPrime.assign(n+1, true);
   isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
   


}