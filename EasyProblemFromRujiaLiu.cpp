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
    vector<pair<int, int>> values;
    while(true) {
        int n, m;
        cin >> n >> m;
        if(cin.fail()) {
            break;
        }
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            values.push_back(make_pair(num, i + 1));
        }
        sort(values.begin(), values.end());
        for (int i = 0; i < m; i++) {
            int k, v;
            cin >> k >> v;
            int index = 0;
            int low = 0;
            int high = values.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (v == values[mid].first) {
                    index = mid;
                    break;
                } else if (v > values[mid].first) {
                    low = mid + 1;
                } else if (v < values[mid].first) {
                    high = mid - 1;
                }
            }
            int result = 0;
            while (values[index - 1].first == v) {
                index--;
            }
            for (int j = 0; j < k - 1; j++) {
                index++;
            }
            if (values[index].first == v) {
                result = values[index].second;
            }
            cout << result << endl;
        }
        values.clear();
        int gfd;
    }
    
    return 0;
}