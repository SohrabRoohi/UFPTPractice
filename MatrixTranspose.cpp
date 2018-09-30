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
    map<pair<int,int>,int> matrix;
    while(true) {
        int m, n;
        cin >> m >> n;
        if(cin.fail()) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            int rowLength;
            cin >> rowLength;
            if (rowLength == 0) {
                continue;
            }
            VI indexes;
            VI rowValues;
            for (int j = 0; j < rowLength; j++) {
                int ind;
                cin >> ind;
                indexes.push_back(ind);
            }
            for (int j = 0; j < rowLength; j++) {
                int rowV;
                cin >> rowV;
                rowValues.push_back(rowV);
            }
            for (int j = 0; j < rowLength; j++) {
                matrix.insert(make_pair(make_pair(indexes[j], i), rowValues[j]));
            }
        }
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++) {
            vector<pair<int, int>> currentRow;
            bool found = false;
            for (auto it = matrix.begin(); it != matrix.end(); it++) {
                if (it->first.first == i) {
                    currentRow.push_back(make_pair(it->first.second, it->second));
                    found = true;
                } else if (found) {
                    break;
                }
            }
            int size = currentRow.size();
            if (size == 0) {
                cout << 0 << endl << endl;
                continue;
            }
            cout << size << " ";
            for (int j = 0; j < size; j++) {
                cout << currentRow[j].first;
                if(j != size - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            for (int j = 0; j < size; j++) {
                cout << currentRow[j].second;
                if(j != size - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
        matrix.clear();
    }


    return 0;
}