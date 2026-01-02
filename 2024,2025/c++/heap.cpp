#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
void push_heap(vector<int>&arr,int n) {
    arr.push_back(n);
    int i = arr.size()-1;
    
    while (i >0) {
        int con = (i - 1) / 2;
        if (arr[con] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[con];
            arr[con] = temp;
            i = con;
        }
        else break;
    }
}
int pop_heap(vector<int>& arr) {
    int cur = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    int i = 0;
    
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >=arr.size() ) {
            break;
        }
        int next = i;
        if (arr[left] > arr[next]) {
            
            next= left;
            
        }
       
        if (right<arr.size() and arr[right] > arr[next]) {

            next = right;
        }
        
        if (next != i) {
            int temp = arr[i];
            arr[i] = arr[next];
            arr[next] = temp;
            i=next;
        }
        else {
            break;
        }
    }
    return cur;
}

int main() {
	
	int t;
	cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        int a;
        int b;
        ll result = 1983;
        int cen;
        vector<int>left;
        vector<int>right;
        cin >> n>>a>>b;
        int num = 1983;
        cen = 1983;
        push_heap(left,num);
        for (int i = 1; i < n; i++) {
            num = ((num * (long long)a) + b) % 20090711;
            
            if (left.size() == right.size()) {
                push_heap(left, num);
            }
            else {
                push_heap(right, -num);
            }
            if (left.size() != 0 and right.size() != 0 and left[0] > -right[0]) {
                int small = -right[0];
                int big = left[0];
                pop_heap(left);
                pop_heap(right);
                push_heap(left, small);
                push_heap(right, -big);


            }
            cen = left[0];
            result = (result +(ll) cen) % 20090711;
            

        }
        cout << result<<endl;

    }

	


	
		
}
