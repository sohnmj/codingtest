#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void) {
    
   
    string s;
    cin >> s;
    int max=s[0]-'0';
    for (int i = 1; i < s.length(); i++) {
        if (max + (int)(s[i] - '0') > max * (int)(s[i] - '0')) {
            max += (int)(s[i] - '0');
        }
        else{
            max *= (int)(s[i] - '0');
        }

    }
    cout << max;

    


}