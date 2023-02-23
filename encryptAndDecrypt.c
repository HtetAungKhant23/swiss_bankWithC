//
// Created by User on 2/22/2023.
//

#include "stdio.h"

void ch_binary(int data);
int size_array(char size_arr[30]);
void enCrypt(char private_key[30], char data[30]);
int user_private_key_bi[16];
int encrypt_data_bi[16];
int bi[16];


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
        printf("data = %d\n",data);
        printf("count is = %d\n",count);
//        two = data % 2;
//        data = data / 2;
        if (data == 1 || data == 0){
//            arr[count] = two;
//            count++;
            arr[count] = data;
            count++;
            break;
        }
    }

    printf("count is = %d\n",count);

    for (int i=1; i<=count; i++){
        printf(" %d",arr[count-i]);
    }
    printf("\n");
    int locate = 1;
    for (int i=0; i<16; i++){
        if (i < 16-count){
            bi[i] = 0;
        } else{
            bi[i] = arr[count-locate];
            locate++;
        }
    }
    for(int i=0; i<16; i++){
        printf(" %d",bi[i]);
    }

//    1011010010

}

int adding_ascii_number(char arr[30]){
    int adding_result = 0;
    int size = size_array(arr);
    printf("%d\n",size);

    for (int i=0; i<size; i++){
        adding_result += arr[i];
    }

    return adding_result;

}

void enCrypt(char private_key[30], char data[30]){
    int ascii=0;

    // 110110101

    ascii = adding_ascii_number(data);

    printf("ascii is = %d\n",ascii);

    ch_binary(ascii);

    printf("\n----------------------\n");

    ascii = 0;

    ascii = adding_ascii_number(private_key);

    printf("ascii is = %d\n",ascii);

    ch_binary(ascii);

    printf("\n----------------------\n");

//    110110101

}

int main(){

    char public_key[30] = {'n','3','c','9','c'};

    char name[30] = {'h','t','e','t'};
    char pass[30] = {'g','C','c','#','2'};

    char private[30] = {'e','n','i','g','a','m','a'};

    enCrypt(private,name);

    return 0;
}
