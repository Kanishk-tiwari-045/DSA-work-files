// int firstUniqChar(char* s) {
//     int n = strlen(s);
//     for (int i = 0; i < n; i++) {
//         int c = 0;
//         for (int j = 0; j < n; j++) {
//             if (i != j && s[i] == s[j]) {
//                 c = 1;
//                 break;
//             }
//         }
//         if (!c) {
//             return i;
//         }
//     }
//     return -1;
// }