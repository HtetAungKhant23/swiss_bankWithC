//
// Created by Htet Aung Khant (NCC) on 2/17/2023.
//

#ifndef SWISS_BANK_NCC_BANK_FUN_H
#define SWISS_BANK_NCC_BANK_FUN_H

#include "Ncc_Bank.h"

char option_checking(char op[2]);
void main_menu();
void sign_up();
void sign_in();
void email_exist_checking(char u_em[50]);
int size_array(char size[50]);
int compare_two_arr(char first_arr[50], char second_arr[50], int len);

void home(){
    printf("hello swiss bank!!");
    main_menu();
}

char option_checking(char op[2]){

    if (op[0] && op[1] == '\0'){
        return op[0];
    }

    return 'n';

}

void main_menu(){

    char menuOption[2];
    printf("[1] For Sign in!\n");
    printf("[2] For Sign up!\n");
    printf("[3] Exit!\n");
    printf("Enter your option : ");
    scanf(" %[^\n]", &menuOption[0]);

    char res_option = option_checking(menuOption);

    if (res_option == '1'){
        sign_in();
    } else if (res_option == '2'){
//        sign_up();
    } else if (res_option == '3'){
        printf("thanks you for using our bank service!");
        exit(1);
    } else{
        printf("Invalid option!");
        main_menu();
    }

}

void sign_in(){

    char u_email[30];
    char u_pass[30];
    printf("Enter your email : ");
    scanf(" %[^\n]",&u_email[0]);
    e_found = 0;
    email_exist_checking(u_email);
    if (e_found == 1){
        printf("enter your password : ");
        scanf(" %[^\n]",&u_pass[0]);
        int re1 = size_array(db[current_idx].password);
        int re2 = size_array(u_pass);
        if (re1 == re2){

        } else{

        }
    } else{
        printf("your email not found!");
        main_menu();
    }

}

void email_exist_checking(char u_em[30]){

    int found = 0;
    int result1 = size_array(u_em);

    for (int i = 0; i < g_idx; i++){

        int result2 = 0;
        result2 = size_array(db[i].email);

        if (result1 == result2){

            found = compare_two_arr(db[i].email,u_em, result1);

            if (found == result1){
                current_idx = i;
                e_found = 1;
                return;
            }

        }

    }

}

int compare_two_arr(char first_arr[30], char second_arr[30], int len){

    int same = 0;

    for (int i = 0; i < len; i++){

        if (first_arr[i] == second_arr[i]){
            same++;
        } else{
            break;
        }

    }

    return same;

}

int size_array(char size_arr[30]){
    int count = 0;

    while (size_arr[count] != '\0'){
        count++;
    }

    return count;

}


#endif //SWISS_BANK_NCC_BANK_FUN_H

//some comments
