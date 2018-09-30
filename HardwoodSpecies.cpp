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
    cout << fixed;
    cout << setprecision(4);
    map<string,int> val;
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    getline(cin, line);
    for(int i = 0; i < N; i++) {
        double total = 0;
        do {
            getline(cin, line);
            if(line.empty()) {
                break;
            }
            val[line]++;
            total++;
        }
        while(!line.empty());
        for(auto it = val.begin(); it != val.end(); it++) {
            cout << it->first << " " << ((double)it->second / total) * 100 << endl;
        }
        val.clear();
        if(i != N - 1) {
            cout << endl;
        }
        int dddg;
    }
    return 0;
}