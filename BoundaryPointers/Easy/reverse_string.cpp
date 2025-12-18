#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // since its inplace swap, we can use two pointers
        int start = 0;
        int end = s.size()-1;

        if(end == 0) {
            return;
        }

        while(start < end) {
            int temp = s[end];
            s[end] = s[start];
            s[start] = temp;

            start++;
            end--;
        }
        return;
    }
};