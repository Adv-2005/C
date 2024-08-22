#include <stdio.h>

int lSearch(int arr[], int n, int key)
{
int i;
for ( i = 0; i < n; i++){
if (arr[i] == key) {
            return i;
        }}
    return 0;
}
int main() {
    int arr[10];
    int n;
    int key, i;

    printf("Enter the size of the array): ");
    scanf("%d", &n);

    printf("Enter %d elements for the array:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int pos = lSearch(arr, n, key);
    if (pos == 0) {
        printf("The element is not present in the array.");
    } else {
        printf("The element is present at position %d.", pos+1);
    }

    return 0;
}
