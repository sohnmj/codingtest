#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int* arr;
int n, x;
int binary_search_l(int s, int l,int tg){
    if (s > l) {
        return -1;
    }
    int mid = (s + l) / 2;
    if (arr[mid] == tg) {
        if (mid == 0||arr[mid-1]!=tg) {
            return mid;
        }
        else {
            return binary_search_l(s, mid - 1,tg);
        }
    }
    else if (arr[mid] < tg) {
        return binary_search_l(mid+1, l, tg);
    }
    else {
        return binary_search_l(s, mid - 1, tg);
    }
}
int binary_search_r(int s, int l, int tg) {
    return 0;
}
int main() {
    
    
    cin >> n >> x;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = binary_search_l(0, n - 1, x);
    int right = binary_search_r(0, n - 1, x);
    
}