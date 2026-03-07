#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

#include <stdio.h>
#include <stdlib.h>

int allDone(int freq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            return 0;
    }
    return 1;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int cooldown[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int time = 0;

    while (!allDone(freq)) {
        int taskIndex = -1;
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && cooldown[i] == 0 && freq[i] > maxFreq) {
                maxFreq = freq[i];
                taskIndex = i;
            }
        }

        if (taskIndex != -1) {
            freq[taskIndex]--;
            cooldown[taskIndex] = n + 1;
        }

        for (int i = 0; i < 26; i++) {
            if (cooldown[i] > 0)
                cooldown[i]--;
        }

        time++;
    }

    return time;
}

int main() {
    printf("Solution for Task Scheduler is implemented. Add test cases as needed.\n");
    return 0;
}