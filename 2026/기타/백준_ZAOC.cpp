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
using namespace std;


/*
행마다 열마다 1명은 최소로 앉을 수 있다는 것을 유의해야한다.
*/

int main() {
    
    int n, m;
    cin >> n >> m;
    int dn, dm;
    cin >> dn >> dm;
    int r = 1 + (n - 1) / (dn + 1);
    int c = 1 + (m - 1) / (dm + 1);
    cout << r * c;
}