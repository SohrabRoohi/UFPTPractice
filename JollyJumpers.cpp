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

vector<string> split(string input, char c) {
    stringstream test(input);
    string segment;
    vector<string> list;
    while(getline(test, segment, c))
    {
        list.push_back(segment);
    }
    return list;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    VI values;
    set<int> diff;
    do {
        getline(cin, line);
        if(line.empty()) {
            break;
        }
        vector<string> stringNum = split(line, ' ');
        for(int i = 0; i < stringNum.size(); i++) {
            values.push_back(stoi(stringNum[i]));
        }
        int n = values[0];
        values.erase(values.begin());
        int size = values.size();
        for(int i = 0; i < size - 1; i++) {
            int curD = abs(values[i] - values[i+1]);
            if(curD > 0 && curD < n) {
                diff.insert(curD);
            }
        }
        if(diff.size() ==  n - 1) {
            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
        values.clear();
        diff.clear();
    }
    while(!line.empty());
    
    return 0;
}