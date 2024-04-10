// int lengthOfLongestSubstring(char *s) {
//     if (s == NULL || *s == '\0') return 0;
//     int max = 0;
//     int n = strlen(s);
//     int len = 0;
//     int start = 0;
//     for (int end = 0; end < n; end++) {
//         len = end - start + 1;
//         for (int i = start; i < end; i++) {
//             if (s[i] == s[end]) {
//                 start = i + 1;
//                 len = end - start + 1;
//                 break;
//             }
//         }
//         if (len > max) {
//             max = len;
//         }
//     }
//     return max;
// }



