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
    ifstream in("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\output.txt");
    cout.rdbuf(out.rdbuf());
    int N;
    cin >> N;
    map<int,int> Green;
    map<int, int> Blue;
    for(int i = 0; i < N; i++) {
        int B, SG, SB;
        cin >> B >> SG >> SB;
        for(int j = 0; j < SG; j++) {
            int value;
            cin >> value;
            Green[value]++;
        }
        for(int j = 0; j < SB; j++) {
            int value;
            cin >> value;
            Blue[value]++;
        }
        while(!Green.empty() && !Blue.empty()) {
            for(int j = 1; j < B + 1; j++) {
                auto gIt = Green.rbegin();
                auto bIt = Blue.rbegin();
                for(int k = 0; k < j; k++) {
                    gIt--;
                    bIt--;
                }
                int minV = min(gIt->first, bIt->first);
                int gDiff = gIt->first - minV;
                int bDiff = bIt->first - minV;
                if(gDiff != 0) {
                    Green[gDiff]++;
                }
                if(bDiff != 0) {
                    Blue[bDiff]++;
                }
                gIt->second--;
                bIt->second--;
                if(gIt->second == 0) {
                    Green.erase(gIt->first);
                }
                if(bIt->second == 0) {
                    Blue.erase(bIt->first);
                }
                if(gIt == Green.rend()) {
                    break;
                }
                if(bIt == Blue.rend()) {
                    break;
                }
            }
        }
        if(Green.empty() && Blue.empty()) {
            cout << "green and blue died" << endl;
        }
        else if(!Green.empty()) {
            cout << "green wins" << endl;
        }
        else if(Blue.empty()) {
            cout << "blue wins" << endl;
        }

        if(i != N - 1) {
            cout << endl;
        }
        Green.clear();
        Blue.clear();
    }
    return 0;
}