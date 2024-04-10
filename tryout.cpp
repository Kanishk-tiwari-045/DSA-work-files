#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vec1;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec1.push_back(str);
    }
    string ch1 = "", ch2 = "";
    for (int i = 0; i < n; i++) {
        string res = vec1[i];
        int size = res.size();
        ch1 = res[size - 1];
        ch2 = res[size - 2];
        cout <<ch2<<ch1;
    }
    return 0;

//     char s[100];
//     char sub[50];
//     fgets(s, sizeof(s), stdin);
//     fgets(sub, sizeof(sub), stdin); 
//     int n = strlen(s);
//     int n1 = strlen(sub);
//     int i,j,c = 0;
//     for (i = 0; i <= n; i++) {
//         for (j = 0; j < n1; j++) {
//             if (s[i + j] != sub[j]) {
//                 break;
//             }
//         }
//         if(j == n1){
//             c = 1;
//             break;
//         }
//     }
//     if(c){
//         printf("Yes\n");
//     }
//     else{
//         printf("No\n");
//     }
//     return 0;
}


