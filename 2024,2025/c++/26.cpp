#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int* arr;
int n, x;
int binary_search(int s, int l) {
    if (s > l) {
        return -1;
    }
    int mid = (s + l) / 2;
    if (arr[mid] == mid) {
        
        return mid;
    }
    else if (arr[mid] < mid) {
        return binary_search(mid + 1, l);
    }
    else {
        return binary_search(s, mid - 1);
    }
}

int main() {


    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int right = binary_search(0, n - 1);
    
    if (right >= 0) {
        cout << right;
    }
    else {
        cout << -1;
    }
}