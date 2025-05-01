#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
    
   
    int n;
    cin >> n;
    int count = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >>arr[i];
    }
    sort(arr,arr+n);
    int i = 0;
    while (i <n) {
        int num = arr[i];
        i += num-1;
        if (i < n && arr[i] <= num) {
            count++;

        }
        i++;
      
    }   
    cout << count;

    


}