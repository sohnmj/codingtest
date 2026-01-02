#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#define ll long long
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

class segment_tree {
    //배열의 길이
public:
    int n;
    //각 구간별 최소값
    vector<int >rangemin;

    vector<int>arr;


    segment_tree(vector<int>& arr, int n) {
        this->n = n;
        this->arr = arr;
        rangemin.resize(4*n);

    }
    int tree_size() { return n; }
    int segment(int left, int right, int node,int*depth) {
        if (left == right) {
            return rangemin[node] = depth[arr[left]];
        }
        int mid = (left + right) / 2;
        int small = segment(left, mid, 2 * node,depth);
        int small1 = segment(mid + 1, right, 2 * node + 1,depth);
        if (small > small1) {
            return rangemin[node] = small1;
        }
        else {
            return rangemin[node] = small;
        }
    }
    int query(int left, int right, int node, int s, int l) {
        if (left <= s and right >= l) {
            return rangemin[node];
        }
        else if (left > l or right < s) {
            return 10000;
        }
        else {
            int mid = (s + l) / 2;
            return min(query(left, right, 2 * node, s, mid), query(left, right, 2 * node + 1, mid + 1, l));
        }




        /*void update(int index, int num, int s, int l, int node) {
            if (s > index or l < index) {
                return ;
            }
            if (num < rangefre[node]) {
                rangefre[node] = num;
            }
            int mid = (s + l) / 2;
            if (s == l) {
                return;
            }
            update(index, num, s, mid, 2 * node);
            update(index, num, mid + 1, l, 2 * node + 1);

        }
        */
    };
};
class node {
public:
    int num;
    vector<int>childs;
    node(int num) :num(num) {

    };

};
void post_trave(int root,vector<int>* arr, vector<int>& result,int* fptr) {
    result.push_back(root);
    if (root!=0 and fptr[root] == 0) {
        fptr[root] = result.size()-1;
    }
    if (arr[root].size() == 0) {
        return;
    }
    for (int i = 0; i < arr[root].size(); i++) {
        post_trave(arr[root][i], arr, result,fptr);
        
        result.push_back(root);
    }
    
}
void deep(vector<int>* arr, int d, int root,int*depth) {
    depth[root] = d;
    if (arr[root].size() == 0) {
        return;
    }
    for (int i = 0; i < arr[root].size(); i++) {
        deep(arr, d + 1, arr[root][i], depth);

        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, q;
        cin >> n >> q;
        vector<int>result;

        vector<int>* arr = new vector<int>[n];
        int* depth = new int[n];
        int* fptr = new int[n];
        depth[0] = 0;
        fptr[0] = 0;
        for (int i = 1; i < n; i++) {

            int m;
            cin >> m;
            arr[m].push_back(i);
            fptr[i] = 0;


        }
        post_trave(0, arr, result,fptr);
        deep(arr, 0, 0, depth);
        int len = result.size();
        segment_tree seg(result, len);
       
        seg.segment(0, len-1, 1,depth);
        
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            int aptr = fptr[a];
            
            int bptr = fptr[b];
            if (aptr > bptr) {
                int temp=aptr;
                aptr = bptr;
                bptr = temp;
            }
            int dee=seg.query(aptr, bptr, 1, 0, len-1);
            cout << depth[a] + depth[b] - 2 * dee << '\n';
        }


    }



	
		
}
