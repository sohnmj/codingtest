#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

typedef struct student {
    int kor, eng, mat;
    string name;
}strudent;
student arr[100000];

bool compare(student a,student b) {
    if (a.kor != b.kor) {
        return a.kor>b.kor;
    }
    else {
        if (a.eng != b.eng) {
            return a.eng < b.eng;
        }
        else {
            if (a.mat != b.mat) {
                return a.mat > b.mat;
            }
            else {
                return a.name < b.name;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].mat;
        
    }
    sort(arr, arr + n, compare);
   // sort(arr, arr + n-1, compare);
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << '\n';
    }
}