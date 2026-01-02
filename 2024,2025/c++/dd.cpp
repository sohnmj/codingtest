#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int isdominated(int x, int y, map<int, int>* app) {
	auto it = app->lower_bound(x);
	if (it == app->end()) {
		return 0;
	}
	if (it->second > y) {
		return 1;
	}
	else {
		return 0;
	}

}
void remove(int x, int y, map<int, int>* app) {
	auto it = app->lower_bound(x);
	if (it == app->begin()) {
		return;
	}
	--it;
	while (true) {
		if (it->second < y) {
			if (it == app->begin()) {
				app->erase(it);
				break;
			}
			else {
				map<int,int>::iterator j = it;
				j--;
				app->erase(it);
				
				it = j;
				
			}
		}
		else {
			break;
		}
	}
}
int result(int x, int y, map<int, int>* app) {
	if (isdominated(x, y, app) == 1) {
		return app->size();
	}
	remove(x, y, app);
	app -> insert({x,y});
	return app->size();
}
int main() {
	int t;
	cin >> t;
	for (int u = 0; u < t; u++) {
		int n;
		cin >> n;


		int ssum = 0;

		map<int, int>app;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			ssum += result(x, y, &app);


		}

		cout << ssum << endl;

	}
	


	
		
}
