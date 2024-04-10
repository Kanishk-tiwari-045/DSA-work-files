#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
int main() {
    pair<int, int> p[] = {{1, 2},{5, 6},{3, 4},{7, 8},{9, 10}};
    int n = sizeof(p)/sizeof(p[0]); 
    pair<pair<int, int>,pair<int, int>> pair1;
    int min = 100000; 
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            int dis = sqrt(pow(p[i].first-p[j].first, 2) + pow(p[i].second-p[j].second, 2));
            if (dis<min){
                min = dis;
                pair1 = make_pair(p[i], p[j]);
            }
        }
    }
    cout<<"Closest-1:("<<pair1.first.first<<","<<pair1.first.second<<")";
    cout<<"\n";
    cout<<"Closest-2:("<<pair1.second.first<<","<<pair1.second.second <<")";
    return 0;
}