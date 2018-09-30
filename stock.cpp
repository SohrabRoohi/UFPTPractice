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

/*
    ifstream in("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("C:\\Users\\Sohrab\\CLionProjects\\CodeforcesGIT\\output.txt");
    cout.rdbuf(out.rdbuf());
     */

int maxProfit(vector<int>& prices) {
    int profit = 0;
    vector<pair<int,int>> numbers;
    for(int i = 0; i < prices.size(); i++) {
        numbers.push_back(make_pair(prices[i],i));
    }
    sort(numbers.rbegin(), numbers.rend());
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = numbers.size() - 1; j > i; j--) {
            int diff = numbers[i].first - numbers[j].first;
            if(diff > 0 && numbers[i].second > numbers[j].second) {
                profit += diff;
                numbers.erase(numbers.begin() + j);
            }
        }
    }
    return profit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}