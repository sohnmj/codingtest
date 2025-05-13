#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<algorithm>
int* vis;
using namespace std;
int main(void) {


    string str;
    int sum = 0;
    int cur = 0;
    cin >> str;
    char* ch = new char[str.length()];
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            sum += (str[i] - 48);
        }
        else {
            ch[cur++] = str[i];
        }

    }
    sort(ch, ch + cur - 1);
    for (int i = 0; i < cur; i++) {
        cout << ch[i];
    }
    cout << sum;

}