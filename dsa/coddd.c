#include <stdio.h> 
#include <limits.h>
int main() {
int arr[] = {12, 35, 1, 10, 34, 1};
int n = sizeof(arr)/sizeof(arr[0]);
int largest = INT_MIN, second = INT_MIN;
for(int i=0;i<n;i++){ if(arr[i] > largest){
second = largest; largest = arr[i];
} else if(arr[i] > second && arr[i] != largest){ second = arr[i];
}
}
printf("Second Largest: %d", second);
}
