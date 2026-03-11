#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<cmath>
#include<set>
#include <unordered_map>
#include <iomanip> 
using namespace std;


/*
소수점 4자리를 구하는 것이 어렵다는 것을 깨달았다. 간단한 해쉬문제였다.
eof문자가 ctrl + z라는 것도 알게 되었다.
*/

unordered_map<string, int>woods;
vector<string>wood;
int main() {
    string s;
    int n=0;
    while (getline(cin, s)) {
        if (!woods.count(s)) {
            wood.push_back(s);
        }
        woods[s]++;
        n++;
    }
    sort(wood.begin(), wood.end());
    cout << fixed << setprecision(4);
    for (const string& name : wood) {
        double ratio = (double)woods[name] / n * 100;
        cout << name << ' ' << ratio << '\n';
    }
        
    
    
}