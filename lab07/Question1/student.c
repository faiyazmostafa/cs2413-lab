#include <stdio.h>

/*
Question 1: Longest Common Prefix
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    // 1. If the input array is empty, return an empty string
    if (strsSize == 0) {
        return "";
    }

    // 2. Iterate through each string in the array starting from the second one
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        
        // 3. Compare characters of strs[0] with strs[i] 
        // until they differ or we hit the end of either string
        while (strs[0][j] != '\0' && strs[i][j] != '\0' && strs[0][j] == strs[i][j]) {
            j++;
        }

        // 4. Truncate strs[0] at the first point of divergence
        // This updates our "current prefix" for the next iteration
        strs[0][j] = '\0';

        // 5. Optimization: If the prefix becomes empty, we can stop early
        if (strs[0][0] == '\0') {
            return strs[0];
        }
    }

    // 6. Return the modified first string
    return strs[0];
}