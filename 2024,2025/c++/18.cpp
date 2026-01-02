#include<iostream>
#include <string>
#include <vector>

using namespace std;
int* arr;
int math[4];
int first;
int mx=-1e9;
int sm = 1e9;
void dfs(int n,int d) {
    if (n == d) {
        if (first > mx) {
            mx = first;
        }
        if (sm > first) {
            sm = first;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (math[i] > 0) {
            if (i == 0) {
                math[i]--;
                first += arr[d];
                dfs(n, d + 1);
                first -= arr[d];
                math[i]++;
            }
            else if (i == 1) {
                math[i]--;
                first -= arr[d];
                dfs(n, d + 1);
                first += arr[d];
                math[i]++;
            }
            else if (i == 2) {
                math[i]--;
                first *= arr[d];
                dfs(n, d + 1);
                first /= arr[d];
                math[i]++;
            }
            else {
                math[i]--;
                int temp = first;
                if (first < 0) {
                    
                    first *= -1;
                    first /= arr[d];
                    first *= -1;
                    dfs(n, d + 1);
                    first = temp;

                }
                else {
                    
                    first /= arr[d];
                   
                    dfs(n, d + 1);
                    first = temp;
                }
                math[i]++;
            }
        }
    }
}
int main() {
    int n;
 

    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    first = arr[0];
    for (int i = 0; i < 4; i++) {
        cin >> math[i];
    }
    dfs(n, 1);
    cout << mx<<endl<<sm;
}