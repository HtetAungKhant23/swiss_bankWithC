//
// Created by Htet Aung Khant (NCC) on 2/17/2023.
//

#ifndef SWISS_BANK_NCC_BANK_FUN_H
#define SWISS_BANK_NCC_BANK_FUN_H

#include "Ncc_Bank.h"

char option_checking(char op[2]);
void main_menu();
void printing_all_user_info();
void sign_up();
void sign_in();
void strong_pass(char pass[30]);
void email_exist_checking(char u_em[50]);
int size_array(char size[50]);
int compare_two_arr(char first_arr[50], char second_arr[50], int len);
void main_page();

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
    printf("[4] view data!\n");
    printf("Enter your option : ");
    scanf(" %[^\n]", &menuOption[0]);

    char res_option = option_checking(menuOption);

    if (res_option == '1'){
        sign_in();
    } else if (res_option == '2'){
        sign_up();
    } else if (res_option == '3'){
        printf("thanks you for using our bank service!");
        exit(1);
    } else if(res_option == '4'){
        printing_all_user_info();
        main_menu();
    } else{
        printf("Invalid option!");
        main_menu();
    }

}


void check_pass(){

    printf("this is checking password!");

}



//void fill_password(){
//
//    wrong_pass = 5;
//    char u_pass[30];
//    while (1) {
//        printf("enter your password : ");
//        scanf(" %[^\n]", &u_pass[0]);
//        int re1 = size_array(db[current_idx].password);
//        int re2 = size_array(u_pass);
//        if (re1 == re2) {
//
//            int found = compare_two_arr(db[current_idx].password,u_pass,re1);
//            if (found == re1){
//
//
//
//                break;
//            } else{
//                printf("password wrong!");
//            }
//
//        } else {
//            wrong_pass--;
//            printf("password wrong!");
//            if (wrong_pass == 0){
//                break;
//            }
//            printf("you have %dtimes to try!",wrong_pass);
//        }
//    }
//
//}


void sign_in(){

    char u_email[40];
    printf("Enter your email : ");
    scanf(" %[^\n]",&u_email[0]);
    e_found = 0;
    email_exist_checking(u_email);
//    if (e_found == 1){
//        fill_password();
//    } else{
//        printf("your email not found!");
//        main_menu();
//    }

}


void sign_up(){
    char u_email[40];
    char u_pass[40];
    char confirm_pass[40];
    printf("this is sign_up function!");
    printf("Enter your email : ");
    scanf(" %[^\n]",&u_email[0]);

    e_found = 0;
    email_exist_checking(u_email);

    if (e_found == 1) {
        printf("your email is already register!!");
        sign_up();
    } else{
        while (1) {
            printf("enter your strong password : ");
            scanf(" %[^\n]", &u_pass[0]);
            str_pass = 0;
            strong_pass(u_pass);
            if (str_pass != 1) {
                printf("your password is not strong!!");
                printf("please try again!");
            } else{
                break;
            }
        }
        int r1 = 0;
        int r2 = 0;
        while (1) {
            printf("Confirm your password : ");
            scanf(" %[^\n]", &confirm_pass[0]);
            r1 = size_array(u_pass);
            r2 = size_array(confirm_pass);
            if (r1 == r2) {
                int same = compare_two_arr(u_pass, confirm_pass, r1);
                if (same == r1){
                    int em1 = size_array(u_email);
                    for (int i=0; i<em1; i++){
                        db[g_idx].email[i] = u_email[i];
                    }
                    for (int i=0; i<r1; i++){
                        db[g_idx].password[i] = u_pass[i];
                    }
                    g_idx++;
                    break;
                } else {
                    printf("your confirm password is not match!!");
                }
            } else {
                printf("your confirm password is not match!!");
            }
        }
        main_menu();
    }

}


void strong_pass(char pass[30]){
    int check_arr[4]={0,0,0,0};
    int size = size_array(pass);

    for (int i=0; i<size; i++){

        if (pass[i] >= 33 && pass[i] <= 42){
            check_arr[0] += 1;
        } else if (pass[i] >= 48 && pass[i] <= 57){
            check_arr[1] += 1;
        } else if (pass[i] >= 65 && pass[i] <= 90){
            check_arr[2] += 1;
        } else if (pass[i] >= 97 && pass[i] <= 122){
            check_arr[3] += 1;
        }

    }

    if (check_arr[0] >= 1 && check_arr[1] >= 1 && check_arr[2] >= 1 && check_arr[3] >= 1){
        str_pass = 1;
    }

}


void printing_all_user_info(){

    for (int i=0; i<g_idx; i++){
        printf("email is %s and password is %s",db[i].email,db[i].password);
        printf("\n");
    }

}



void main_page(){
    printf("welcome from main page");
}

void email_exist_checking(char u_em[30]){

    printf("g_index is %d",g_idx);
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
