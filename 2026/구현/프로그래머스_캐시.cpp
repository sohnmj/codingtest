
/*
vector, set, deque같은거는 다 erase(반복자)가 가능하다 string 은 erase(index,size)가 가능하다*/
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
typedef struct record{
    int time;
    string name;
    string um;
};
string upper(string city) {
    string upperCity = "";
    for (int i = 0;i < city.size();i++) {
        if (city[i] >= 97) {
            upperCity += city[i] - 32;
        }
        else {
            upperCity += city[i];
        }
    }
    return upperCity;
}
int cachemiss = 5;
int cachehit = 1;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int curSize = 0;
    deque<string>cache;
    for (auto city : cities) {
        string uCity = upper(city);
        bool hit = false;
        for (int i = 0;i < cache.size();i++) {
            string item = cache[i];
            if (item == uCity) {
                hit = true;
                answer += 1;
                cache.erase(cache.begin() + i);
                cache.push_back(uCity);
                break;
            }
        }
        if (!hit) {
            if (cacheSize == 0) {
                answer += 5;
                continue;
            }
            if (cache.size() >= cacheSize) {
                cache.pop_front();
            }
            cache.push_back(uCity);
            answer += 5;
        }

    }
    return answer;
}
int main() {


    cout<<solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" });
}