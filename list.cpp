#include <iostream>
#include <list>
using namespace std;

int main(){
    list <int> list1;
    list1.push_front(1);
    list1.push_front(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_front(5);
    list1.push_front(6);
    list1.pop_front();
    list1.pop_back();
    cout<<list1.front();
    cout<<"\n";
    cout<<list1.back();
    cout<<"\n";
    cout<<list1.size();
}