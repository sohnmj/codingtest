
/*
배열을 O(N)의 시간복잡도로 힙으로 구축하는게 핵심이었다. 이는 내부 노드의 가장 밑부터 차례대로 heapfipy를 시키면 된다.(리프노드는 내려갈 노드가 없음)
heapify에서 if else if구문으로 썻다가 잘못된 결과가 나왔다. 잘 구분한자 if의 결과를 다시 비교해야할때는 else if를 쓰면 안된다.
*/
#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& heap, int idx) {
    int n = heap.size();
    while (1) {
        int cur = idx;
        int right_child = cur * 2 + 2;
        int left_child = cur * 2 + 1;
        if (right_child<n && heap[right_child]>heap[cur]) {
            cur = right_child;
        }
        if (left_child<n && heap[left_child]>heap[cur]) {
            cur = left_child;
        }
        if (idx == cur) {
            break;
        }
        int temp = heap[cur];
        heap[cur] = heap[idx];
        heap[idx] = temp;
        idx = cur;
    }

}
void make_heap(vector<int>& heap) {
    int length = heap.size();

    // 마지막 내부 노드부터 루트(0번)까지 역순 진행
    for (int i = (length / 2) - 1; i >= 0; --i) {
        heapify(heap, i);
    }
}
int pop_heap(vector<int>& max_heap) {
    int temp = max_heap[0];
    int n = max_heap.size();
    max_heap[0] = max_heap[n - 1];
    max_heap.pop_back();
    heapify(max_heap, 0);
    return temp;
}
vector<int> findNLargestElements(const vector<vector<int>>& matrix, int n) {
    vector<int> largestElements;
    // TODO:
    //heap구축
    vector<int>max_heap;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            max_heap.push_back(matrix[i][j]);
        }
    }
    make_heap(max_heap);
    for (int i = 0;i < n;i++) {
        largestElements.push_back(pop_heap(max_heap));

    }



    return largestElements;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    vector<int> largestElements = findNLargestElements(M, n);

    for (int element : largestElements) {
        cout << element << "\n";
    }

    return 0;
}
