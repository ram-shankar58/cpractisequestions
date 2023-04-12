#include <stdio.h>
#include <string.h>

int maximum(int arr[]) { 
    int max1 = arr[0];
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }
    return max1;
}

void gamestar(int arr[], char *names[]) {
    int x = maximum(arr); 
    int winplay[20];
    int k = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == x) {
            winplay[k] = i; 
            k++;
        }
    }
    printf("Game toppers: ");
    for (int i = 0; i < k; i++) {
        printf("%s ", names[winplay[i]]); 
    }
    printf("(Score: %d)\n", x);
}

void overallsum(int a1[], int b1[], int c1[], char *names[]) {  //here If you don't pass names as a pointer to the gamestar function, it will be treated as an array of characters, not as an array of strings. This means that each element of the names array will be treated as a single character, which will cause errors when you try to access individual elements of the strings using names[i][j].

//In order to pass names as an array of strings, you need to pass it as a pointer to a pointer to char (i.e., char **names). This allows you to create an array of pointers to char, where each pointer points to a string in memory.
    int score[10];
    for (int i = 0; i < 10; i++) {
        score[i] = a1[i] + b1[i] + c1[i];
    }
    int l = maximum(score); 
    printf("Overall winner(s): ");
    gamestar(score, names); 
}

int main() {
    int football[10] = {10, 0, 7, 4, 6, 9, 5, 9, 0, 10};
    int Gymnastics[10] = {8, 10, 9, 7, 4, 10, 9, 8, 7, 0};
    int Athletics[10] = {8, 10, 5, 10, 8, 4, 7, 8, 9, 9};
    char *names[10] = {"JoAhn", "Alex", "Emily", "Kate", "Oliver", "Sarah", "Tom", "Lucy", "Mike", "Anna"};
    printf("Football:\n");
    gamestar(football, names);
    printf("\nGymnastics:\n");
    gamestar(Gymnastics, names);
    printf("\nAthletics:\n");
    gamestar(Athletics, names);
    printf("\nOverall:\n");
    overallsum(football, Gymnastics, Athletics, names);
    return 0;
}
