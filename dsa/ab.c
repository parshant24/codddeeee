#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int arr[] = {5,2,15,25,11,19,65,23,34,44,64,74,73,2,15,29,55,65,26,64,38,12,16,49,11,78,65,63,57,42};
int n = 30;

int hashFunc(int key) {
    return key % SIZE;
}

int linear[SIZE];

void insertLinear(int key) {
    int index = hashFunc(key);
    while (linear[index] != -1)
        index = (index + 1) % SIZE;
    linear[index] = key;
}

int searchLinear(int key) {
    int index = hashFunc(key);
    while (linear[index] != -1) {
        if (linear[index] == key)
            return 1;
        index = (index + 1) % SIZE;
    }
    return 0;
}

int quadratic[SIZE];

void insertQuadratic(int key) {
    int index = hashFunc(key);
    int i = 0;
    while (quadratic[(index + i*i) % SIZE] != -1)
        i++;
    quadratic[(index + i*i) % SIZE] = key;
}

int dbl[SIZE];

int hash2(int key) {
    return 7 - (key % 7);
}

void insertDouble(int key) {
    int index = hashFunc(key);
    int step = hash2(key);
    while (dbl[index] != -1)
        index = (index + step) % SIZE;
    dbl[index] = key;
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* chain[10];

void insertChain(int key) {
    int index = key % 10;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = chain[index];
    chain[index] = newNode;
}

int main() {
    /* Initialize tables */
    for (int i = 0; i < SIZE; i++) {
        linear[i] = quadratic[i] = dbl[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        insertLinear(arr[i]);
        insertQuadratic(arr[i]);
        insertDouble(arr[i]);
        insertChain(arr[i]);
    }
    printf("Search 44: %s\n", searchLinear(44) ? "Found" : "Not Found");
    printf("Search 94: %s\n", searchLinear(94) ? "Found" : "Not Found");

    int freq[100] = {0};
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    printf("Count of 65: %d\n", freq[65]);

    printf("Array without duplicates:\n");
    int seen[100] = {0};
    for (int i = 0; i < n; i++) {
        if (!seen[arr[i]]) {
            printf("%d ", arr[i]);
            seen[arr[i]] = 1;
        }
    }
    printf("\n");

    int max = 0, elem;
    for (int i = 0; i < 100; i++) {
        if (freq[i] > max) {
            max = freq[i];
            elem = i;
        }
    }
    printf("Max frequency element: %d\n", elem);

    int Z;
    printf("Enter sum Z: ");
    scanf("%d", &Z);

    int hash[100] = {0};
    printf("Pairs:\n");
    for (int i = 0; i < n; i++) {
        if (hash[Z - arr[i]])
            printf("%d + %d = %d\n", arr[i], Z - arr[i], Z);
        hash[arr[i]] = 1;
    }
    return 0;
}