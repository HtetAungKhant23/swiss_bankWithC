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
//void emailexist


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
    printf("Enter your email : ");
    scanf(" %[^\n]",&u_email[0]);


}


#endif //SWISS_BANK_NCC_BANK_FUN_H
