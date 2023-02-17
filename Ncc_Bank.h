//
// Created by Htet Aung Khant (NCC) on 2/17/2023.
//

#ifndef SWISS_BANK_NCC_BANK_H
#define SWISS_BANK_NCC_BANK_H

#include "stdio.h"
#include "stdlib.h"
#define USIZE 100

struct transaction{
    char note[200];
};

struct database{
    unsigned int id;
    char name[30];
    char nrc[20];
    char email[40];
    char password[40];
    unsigned int phone_number;
    char encryption_key[50];
    char recovery_key[50];
    char account_status[50];
    int account_level;
    unsigned int min_opening_deposit;
    char currency[30];
    unsigned int current_amount;
    char loan_status[50];
    unsigned int monthly_income;
    unsigned int loan_amount;
    unsigned int loan_rate;
    char address[50];
    struct transaction tranRC[100];

};

struct database db[USIZE];

#endif //SWISS_BANK_NCC_BANK_H
