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

        int n;
        cin >> n;
        int set = 1;
        VI values;
        while(n != 0) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                int height;
                cin >> height;
                values.push_back(height);
                sum += height;
            }
            int avg = sum / n;
            int moves = 0;
            for(int i = 0; i < values.size(); i++) {
                if(values[i] > avg) {
                    moves += values[i] - avg;
                }
            }
            cout << "Set #" << set << endl;
            cout << "The minimum number of moves is " << moves << "." << endl;
            cout << endl;
            cin >> n;
            values.clear();
            set++;
            int gfdf;
        }
        return 0;
    }