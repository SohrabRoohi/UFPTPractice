/*
  Sohrab Roohi
*/

#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int sign(int n) {
    if(n > 0) {
        return 1;
    }
    else if(n < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    VI nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        nums.push_back(ai);
    }
    int dp[n+1];
    dp[0] = 1;
    int maxLength = 0;
    for(int i = 0; i < n + 1; i++) {
        int max = 0;
        for(int j = i -1; j >= 0; j--) {
            if(dp[j] > max && abs(nums[j]) < abs(nums[i]) && sign(nums[j]) != sign(nums[i])) {
                max = dp[j];
            }
        }
        dp[i] = max + 1;
        if(dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    cout << maxLength;
    return 0;
}