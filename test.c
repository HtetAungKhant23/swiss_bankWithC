////
//// Created by User on 2/22/2023.
//

#include "stdio.h"

int main(){

    int one = 0;
    int two = 0;
    int data = 24;
    int arr[16];
    int true_arr[16];
    int count = 0;

    one = data / 2;
    two = data % 2;
    while (1){
        arr[count] = two;
        count++;
        printf("%d\n",one);
        two = one % 2;
        one = one / 2;
        if (one == 1 || one == 0){
            arr[count] = two;
            count++;
            arr[count] = one;
            count++;
            break;
        }
    }

    printf("%d\n",count);
    printf("%d\n",arr[count-1]);

    for (int i=1; i<=count; i++){
        printf(" %d",arr[count-i]);
        true_arr[i-1] = arr[count-i];
    }

    printf("\n");

//    printf("%d",arr[count-1]);

    for (int i=0; i<count; i++){
        printf(" %d",true_arr[i]);
    }


    return 0;
}


