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


pair<string,string> getBook(string line) {
    string title = "\"";
    int index = 1;
    for(int i = 1; line[i] != '"'; i++) {
        title += line[i];
        index++;
    }
    title += "\"";
    string author = "";
    for(int i = index + 5; i < line.length(); i++) {
        author += line[i];
    }
    return make_pair(author,title);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,bool> inStock;
    map<string,string> orderBooks;
    map<string,string> titleToAuthor;
    priority_queue<string, vector<string>, std::greater<string>> queue;

    string line;
    getline(cin, line);
    while(line != "END") {
        pair<string,string> book = getBook(line);
        inStock[book.second] = true;
        orderBooks[book.first] = book.second;
        titleToAuthor[book.second] = book.first;
        getline(cin, line);
    }
    string command;
    cin >> command;
    while(command != "END") {
        if(command == "BORROW") {
            string book;
            cin >> book;
            inStock[book] = false;
        }
        else if(command == "RETURN") {
            string book;
            cin >> book;
            if(!inStock[book]) {
                queue.push(titleToAuthor[book]);
            }
        }
        else if(command == "SHELVE") {
            while(!queue.empty()) {
                string book = queue.top();
                queue.pop();
                string lastTrue;
                for(auto it = orderBooks.begin(); it->second != book; it++) {
                    if(inStock[it->second]) {
                        lastTrue = it->second;
                    }
                }
                if(lastTrue.empty()) {
                    cout << "Put " << book << " first" << endl;
                }
                else {
                    cout << "Put " << book << " after " << lastTrue << endl;
                }
                inStock[book] = true;
            }
            cout << "END" << endl;
        }
        cin >> command;
    }

    return 0;
}