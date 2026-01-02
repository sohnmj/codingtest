#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
int* vis;
using namespace std;
int main(void) {
    
   
    int* arr;
    int n;
    int sum = 1;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (sum <arr[i]) {
            break;

        }
        sum += arr[i];
    }
    cout << sum;
    
    


}