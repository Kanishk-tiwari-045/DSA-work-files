#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;
    int a[n];
    cout<<"Array Elements: ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Entered Array Elements: ";
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
