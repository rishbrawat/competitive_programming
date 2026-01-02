#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        // in one single pass i have to compare adjacent chars and subtract i-i+1 and update the score
        int score = 0;
        int size = s.size();
        for(int i = 0; i < size-1; i++) {
            score = score + abs((s[i]-s[i+1]));
        }
        return score;
    }
};