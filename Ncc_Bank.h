//
// Created by Htet Aung Khant (NCC) on 2/17/2023.
//

#ifndef SWISS_BANK_NCC_BANK_H
#define SWISS_BANK_NCC_BANK_H

#include "stdio.h"
#include "stdlib.h"
#define USIZE 1000

struct transaction{
    char note[200];
};

struct database{
    unsigned int id;
    char name[30];
    char nrc[20];
    char email[40];
    char password[40];
    char phone_number[15];
    char encryption_key[50];
    char recovery_key[50];
    char account_status[50];
    int account_level;
    unsigned int min_opening_deposit;
    char currency[30];
    unsigned long long int current_amount;
    char loan_status[50];
    unsigned int monthly_income;
    unsigned int loan_amount;
    float loan_rate;
    char address[50];
    struct transaction tranRC[100];

};

struct database db[USIZE];

int g_idx = 0;
int e_found = 0;
int current_idx = 0;
int str_pass = 0;
int nrc_format = 0;


#endif //SWISS_BANK_NCC_BANK_H
