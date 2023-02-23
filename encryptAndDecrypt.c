//
// Created by User on 2/22/2023.
//

#include "stdio.h"

void ch_binary(int data);
int size_array(char size_arr[30]);
void enCrypt(char private_key[7], char data[10]);

int size_array(char size_arr[30]){
    int count = 0;
    while (size_arr[count] != '\0'){
        count++;
    }
    return count;
}

void ch_binary(int data){
    int arr[16];
    int two = 0;
    int count = 0;
    while (1){
        two = data % 2;
        data = data / 2;
        arr[count] = two;
        count++;
        printf("%d\n",data);
//        two = data % 2;
//        data = data / 2;
        if (data == 1 || data == 0){
            arr[count] = two;
            count++;
            arr[count] = data;
            count++;
            break;
        }
    }

    for (int i=1;  i<=count; i++){
        printf(" %d",arr[count-i]);
    }

//    1011010010



}

void enCrypt(char private_key[7], char data[4]){

    int size = size_array(data);
//    for (int i = 0; i < size; i++) {

        ch_binary(722);

//    }

}

int main(){

    char public_key[5] = {'n','3','c','9','c'};

    char name[4] = {'h','t','e','t'};
    char pass[5] = {'g','C','c','#','2'};

    char private[7] = {'e','n','i','g','a','m','a'};

    enCrypt(private,name);

    return 0;
}
