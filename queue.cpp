#include <queue>
#include <iostream>
using namespace std;

int main(){
    queue <int> queue1;
    queue1.push(5);
    queue1.push(6);
    queue1.push(7);
    queue1.push(8);
    queue1.push(10);
    queue1.pop();
    cout<<queue1.size();
    cout<<"\n";
    cout<<queue1.front();
    cout<<"\n";
    cout<<queue1.back();
    cout<<"\n";
    cout<<queue1.empty();

    return 0;
}
