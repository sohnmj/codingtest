#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int* arr;
int n, c,sm;
void binary_search(int s, int l) {
    if (s>l) {
        return;
    }
    int mid = (s + l) / 2;
    int start = arr[0];
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] - start >= mid) {
            count++;
            start = arr[i];
        }
    }
    if (c > count) {
        binary_search(s, mid - 1);
    }
    else {
        sm = mid;
        binary_search(mid + 1, l);
    }
    
}

int main() {


    cin >> n>>c;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    binary_search(1, arr[n-1]-arr[0]);
    cout << sm;
    
}