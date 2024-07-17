#include <stdio.h>
#include <string.h>


unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}


unsigned long long count_anagrams(char *word) {
    int length = strlen(word);
    int counts[26] = {0};

    for (int i = 0; i < length; i++) {
        counts[word[i] - 'A']++;
    }
    
    unsigned long long total_permutations = factorial(length);

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 1) {
            total_permutations /= factorial(counts[i]);
        }
    }

    return total_permutations;
}

int main() {
    char word[15]; 

    printf("Введіть слово: ");
    scanf("%s", word);

    unsigned long long anagrams = count_anagrams(word);
    printf("Кількість анаграм: %llu\n", anagrams);

    return 0;
}
