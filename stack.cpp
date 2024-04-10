#include <stack>
#include <iostream>
using namespace std;

int main(){
    stack <int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.pop();
    cout<<stack1.size();
    cout<<"\n";
    cout<<stack1.top();
    cout<<"\n";
    cout<<stack1.empty();
    
    return 0;
}