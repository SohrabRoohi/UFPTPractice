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

    int s;
    cin >> s;
    for(int i = 0; i < s; i++) {
        int n;
        cin >> n;
        map<string, string> locations;
        vector<string> l;
        for(int j = 0; j < n - 1; j++) {
            string f;
            string se;
            cin >> f;
            cin >> se;
            l.push_back(f);
            l.push_back(se);
            locations.insert(pair<string,string>(f,se));
        }
        string result;
        for(int j = 0; j < locations.size(); j++) {
            bool found = false;
            for (auto it = locations.begin(); it != locations.end(); it++) {
                if (it->second == l[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result = l[j];
                break;
            }
        }
        string print = "d";
        cout << "Scenario #" << i + 1 << ":" << endl;
        cout << result << endl;
        while(!print.empty()) {
            print = locations[result];
            cout << print << endl;
            result = print;
        }
        cout << endl;
    }
    return 0;
}