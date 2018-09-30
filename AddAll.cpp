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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N != 0) {
        VI values;
        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            values.push_back(num);
        }
        int totalSum = 0;
        sort(values.begin(), values.end());
        while(values.size() > 1) {
            int added = values[0] + values[1];
            totalSum += added;
            values.erase(values.begin() + 1);
            values.erase(values.begin());
            values.push_back(added);
            sort(values.begin(), values.end());
        }
        cout << totalSum << endl;
        cin >> N;
        int gfddd;
    }
    return 0;
}