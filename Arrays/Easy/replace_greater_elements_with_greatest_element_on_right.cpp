#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();

        if(size <= 1) {
            return {-1};
        }
        vector<int> suffixMax(size);
        suffixMax[size-1] = arr[size-1];

        for(int i = size-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], arr[i]);
        }
        vector<int> ans(size);
        for(int i = 0; i < size-1; i++) {
            ans[i] = suffixMax[i+1];
        }
        ans[size-1] = -1;

        return ans;
    }
};