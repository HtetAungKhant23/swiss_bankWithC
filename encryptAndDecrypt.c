//
// Created by User on 2/22/2023.
//
#include "stdio.h"

void ch_binary(int data);
int size_array(char size_arr[30]);
void enCrypt(char private_key[30], char data[30]);
void two_bi_or_operation(int one[16], int two[16]);
int ch_ascii(int to_ascii[16]);
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
}


int ch_ascii(int to_ascii[16]){
    int count = 0;
    for (int i=0; i<16; i++){
        if (to_ascii[i] == 1){
            break;
        } else{
            count++;
        }
    }
    for (int i=count+1; i<16; i++){
        to_ascii[count] = (2*to_ascii[count]) + to_ascii[i];
    }
    return to_ascii[count];
}

void two_bi_or_operation(int one[16], int two[16]){

    for (int i = 0; i < 16; i++) {
        if(one[i] == two[i]){
            encrypt_data_bi[i] = 0;
        } else{
            encrypt_data_bi[i] = 1;
        }
    }

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
    int ascii = 0;

    // 110110101

    ascii = adding_ascii_number(data);
    printf("ascii is = %d\n",ascii);
    ch_binary(ascii);
    printf("\n----------------------\n");

    for (int i=0; i<16; i++){
        user_private_key_bi[i] = bi[i];
    }

    ascii = 0;

    ascii = adding_ascii_number(private_key);
    printf("ascii is = %d\n",ascii);
    ch_binary(ascii);
    printf("\n----------------------\n");

    two_bi_or_operation(bi, user_private_key_bi);

    for(int i=0; i<16; i++){
        printf(" %d",encrypt_data_bi[i]);
    }

    int asc = ch_ascii(encrypt_data_bi);
    printf("\nencrypted ascii is %d and character is %c",asc,asc);

}

int main(){
    char public_key[30] = {'n','3','c','9','c'};

    char name[30] = {'h','t','e','t'};
    char pass[30] = {'g','C','c','#','2'};

    char private[30] = {'e','n','i','g','a','m','a'};

    enCrypt(private,name);

    return 0;
}
