/*
next_permutation은 원소를 사전 순으로 탐색하여 다음 순열을 생성한다.
따라서 초기에 마스크 배열을 [1, 0, 0, 0, 0]처럼 설정하면 이는 사전 순상 가장 마지막 순열에 해당하여 나머지 4가지 경우를 탐색하지 못하고 단 한 번만 실행된 후 루프가 종료된다.
모든 조합을 빠짐없이 확인하기 위해서는 반드시 사전 순상 가장 앞선 오름차순 형태인 [0, 0, 0, 0, 1]로 초기화해야 한다.
또한 튜플의 유일성을 검사할 때 컬럼 값을 단순 결합하면 ["a", "ab"]와 ["aa", "b"]가 모두 "aab"로 처리되는 예외가 발생할 수 있으므로
값 사이에 고유한 구분자(예: "/")를 추가하여 결합하는 것이 훨씬 안전하고 정확한 구현 방식이다.*/
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include<set>
#include<deque>
typedef long long ll;
using namespace std;
bool is_avail_candidate(vector<int>&candidate, vector<vector<string>>& relation) {
    int rown = relation.size();
    unordered_map<string, int>um;
    for (auto row : relation) {
        string record="";
        for (int i = 0;i < candidate.size();i++) {
            if (candidate[i]) {
                record+=row[i];
            }
        }
        um[record]++;
    }
    for (auto temp : um) {
        if (temp.second > 1) {
            return false;
        }
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int>candidates;
    if (relation.size() == 0) {
        return answer;
    }

    int coln = relation[0].size();
    for (int j = 1;j <= coln;j++) {
        vector<int> mask(coln, 0);
        fill(mask.end()-j, mask.end(), 1);
        do {
            int candidate=0;
            
            for (int i = 0; i < coln; i++) {
                if (mask[i]) {
                    candidate += (1 << i);
                }
            }

            bool avail_candidate = is_avail_candidate(mask, relation);
            if (avail_candidate) {
                bool valid_candidate = true;
                for (int key : candidates) {
                    if ((candidate & key) == key) {
                        valid_candidate = false;
                        break;
                    }
                }
                if (valid_candidate) {
                    candidates.push_back(candidate);
                }
            }
        } while (next_permutation(mask.begin(), mask.end()));

    }

    answer = candidates.size();
    return answer;
   
}
int main() {

    vector<vector<string>> relation = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
    cout<<solution(relation);
}