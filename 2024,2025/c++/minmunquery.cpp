#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
class segment_tree {
    //배열의 길이
    int n;
    //각 구간별 최소값
    vector<int>rangemin;
    vector<int>arr;
    
public:
    segment_tree(vector<int>& arr, int n) {
        this->n = n;
        this->arr = arr;
        rangemin.resize(4 * n, 1000000);
    }
    int tree_size() { return n; }
    int segment(int left, int right, int node) {
        if (left == right) {
            return rangemin[node]=arr[left];
        }
        int mid = (left + right) / 2;
        int small = segment(left, mid, 2 * node);
        int small1 = segment(mid + 1, right, 2 * node + 1);
        if (small > small1) {
            return rangemin[node] = small1;
        }
        else {
            return rangemin[node] = small;
        }
    }
    int query(int left, int right,int node,int s,int l) {
        if (left <= s and right >= l) {
            return rangemin[node];
        }
        else if (left>l or right<s) {
            return 10000;
        }
        else {
            int mid = (s + l) / 2;
            return min(query(left, right, 2 * node, s, mid), query(left, right, 2 * node + 1, mid + 1, l));
        }

 
        
    }
    void update(int index, int num,int s,int l,int node) {
        if (s > index or l < index) {
            return ;
        }
        if (num < rangemin[node]) {
            rangemin[node] = num;
        }
        int mid = (s + l) / 2;
        if (s == l) {
            return;
        }
        update(index, num, s, mid, 2 * node);
        update(index, num, mid + 1, l, 2 * node + 1);

    }
};
int main() {
    vector<int>arr = { 5,2,3,4 };
    segment_tree s(arr, 4);
    s.segment(0, 3, 1);
    cout<<s.query(1, 3, 1,0, s.tree_size() - 1);
    s.update(2, 1, 0, s.tree_size() - 1, 1);
    cout << s.query(0, 1, 1, 0, s.tree_size() - 1);

	


	
		
}
