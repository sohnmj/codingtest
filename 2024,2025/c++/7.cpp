#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
int* vis;
using namespace std;
int main(void) {
    
   
    string str;
    int fsum = 0;
    int lsum = 0;
    cin >> str;
    for (int i = 0; i < str.length() / 2; i++) {
        fsum += str[i];
    }
    for (int i = str.length() / 2; i < str.length(); i++) {
        lsum += str[i];

    }
    if (fsum == lsum) {
        cout << "LUCKY";

    }
    else {
        cout << "READY";
    }
  
    
    


}