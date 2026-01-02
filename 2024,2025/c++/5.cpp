#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
int* vis;
using namespace std;
int main(void) {
    
   
    int* arr;
    int n;
    int m ;
    cin >> n>>m;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count=0;
    sort(arr, arr + n);
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                count += (n - j);
                break;
            }
        }
    }
    cout << count;
  
    
    


}