#include<stdio.h>
void linearSearch(int arr[], int len, int Item){
 int i;
 for (i = 0; i < len; i++)
 {
    if (arr[i] == Item)
    {
        printf("The number %d is found %d.\n", Item, i);
        break;
    }
 }
 if (i == len)
 {
    printf("The number %d isn't found \n",Item);
 }
}
void radixSort (int a[], int num){
 int bucket[10][10], bucket_cnt[10];
 int i, j, k, r, to = 0, divisor = 1, lar, pass, maxx = a[0];
 for (int i = 1; i < num; i++)
 if (a[i] > maxx)
 maxx = a[i];
 lar = maxx;
 while (lar > 0){
     to++;
     lar /= 10;
 }
 for (pass = 0; pass < to; pass++){
     for (i = 0; i < 10; i++){
        bucket_cnt[i] = 0;
     }
     for (i = 0; i < num; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
     }
     i = 0;
     for (k = 0; k < 10; k++){
        for (j = 0; j < bucket_cnt[k]; j++){
             a[i] = bucket[k][j];
             i++;
        }
     }
     divisor *= 10;
 }
}
void bubbleSort(int arr[], int len){
 int x, y, swapp;
 for (x = 0; x < len - 1; x++){
    for (y = 0; y< len - x - 1; y++)
     {
         if (arr[y] > arr[y + 1])
         {
             swapp = arr[y];
             arr[y] = arr[y + 1];
             arr[y + 1] = swapp;
         }
     }
 }
 printf("The number is in ascending order: ");
 for (x = 0; x< len; x++)
 printf("%d ", arr[x]);
 printf("\n");
}
void binarySearch(int arr[], int len, int Item) {
 int first = 0, last = len - 1;
 int mid = first + (last - first) / 2;
 while (first <= last){
     if (arr[mid] < Item)
        first = mid + 1;
     else if (arr[mid] == Item){
        printf("The number %d is found\n", Item, mid);
        break;
     }
     else
         last = mid - 1;
         mid = (first + last) / 2;
 }
 if(first > last)
    printf("%d isn't found\n", Item);
}
void insertionSort(int arr[], int len){
 int i, j,num;
 for (i = 1; i < len; i++)
 {
     num = arr[i];
     j = i - 1;
     while ((num < arr[j]) && (j >= 0))
     {
         arr[j + 1] = arr[j];
         j = j - 1;
     }
     arr[j + 1] = num;
 }
 printf("ascending order: ");
 for(i = 0; i < len; i++)
 printf("%d ",arr[i]);
 printf("\n");
}
void selectionSort(int arr[], int len){
 int i, j, num;
 for (i = 0; i < len; i++)
 {
     for (j = i + 1; j < len; j++)
     {
         if (arr[i] > arr[j])
         {
             num = arr[i];
             arr[i] = arr[j];
             arr[j] = num;
         }
     }
 }
 printf("The number is in ascending order: ");
 for(i = 0; i < len; i++)
     printf("%d ",arr[i]);
     printf("\n");
}
void quicksort(int arr[],int first, int last){
 int i, j, pivot, num;
 if(first<last){
     pivot=first;
     i=first;
     j=last;
     while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
             num=arr[i];
             arr[i]=arr[j];
             arr[j]=num;
         }
     }
     num=arr[pivot];
     arr[pivot]=arr[j];
     arr[j]=num;
     quicksort(arr,first,j-1);
     quicksort(arr,j+1,last);
 }
}
void countingSort(int a[],int num,int maxx){
 int countt[50]={0},i,j;
 for(i=0;i<num;++i)
 countt[a[i]]=countt[a[i]]+1;
 printf("the number is in ascending order: ");
 for(i=0;i<=maxx;++i)
 for(j=1;j<=countt[i];++j)
 printf("%d ",i);
 printf("\n");
}
int main()
{
 int choice;
 printf("1. Searching\n 2. Sorting\n");
 printf("Enter Your number: ");
 scanf("%d", &choice);
 if(choice == 1){
     int searching, length, item, i;
     printf(" 1. Linear Search.\n 2. Binary Search.\n");
     printf("Enter your number: ");
     scanf("%d", &searching);
     printf("How many numbers for add searching: ");
     scanf("%d", &length);
     int arr[length];
     printf("Enter %d your numbers: ", length);
     for (i = 0; i < length; i++)
     {
        scanf("%d", &arr[i]);
     }
     printf("Enter your search no: ");
     scanf("%d", &item);
     switch (searching)
     {
         case 1:
            linearSearch(arr, length, item);
            break;
         case 2:
            binarySearch(arr, length, item);
            break;
         default:
            printf("The number you search isn't found here.\n");
     }
 }
 else if(choice== 2){
     int sorting, length, i, high = 0;
     printf("1. Selection Sort.\n 2. Counting Sort.\n 3. Bubble Sort.\n 4. Radix Sort.\n5. Insertion Sort.\n 6. Quick Sort.\n");
     printf("Enter Your Choice: ");
     scanf("%d", &sorting);
     printf("How many numbers for add: ");
     scanf("%d", &length);
     int arr[length];
     printf("Enter %d your elements: ", length);
     for (i = 0; i < length; i++){
         scanf("%d", &arr[i]);
         if(arr[i] > high)
            high = arr[i];
     }
     switch (sorting)
     {
         case 1:
            selectionSort(arr, length);
            break;
         case 2:
             countingSort(arr, length, high);
             break;
         case 3:
             bubbleSort(arr, length);
             break;
         case 4:
             radixSort(arr, length);
             printf ("ascending order: ");
             for (i = 0; i < length; i++)
                 printf ("%d ", arr[i]);
                 printf ("\n");
             break;
         case 5:
             insertionSort(arr, length);
             break;
         case 6:
             quicksort(arr, 0, length - 1);
             printf("ascending order: ");
             for(i = 0;i < length; i++)
                 printf("%d ", arr[i]);
                 printf("\n");
             break;
         default:
            printf("not found.\n");
     }
 }
 else{
    printf("not found.");
 }
 return 0;
}
