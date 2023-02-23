//
// Created by User on 2/21/2023.
//

#include "stdio.h"

int nrc_format;
int country;

int size_array(char size_arr[30]){
    int count = 0;
    while (size_arr[count] != '\0'){
        count++;
    }
    return count;
}

void nrc_validation(char nrc[20]){
    nrc_format = 0;
    country = 0;
    int found = 0;
    int check[6]={0,0,0,0,0,0};
    int size = size_array(nrc);
    if (size >= 14) {
        for (int i = 1; i < 10; i++) {
            if (i < 7) {
                if (i == 1){
                    if (nrc[i-1] >= 48 && nrc[i-1] <= 57){
                        if (nrc[i] >= 48 && nrc[i] <= 57){
                            if (nrc[i+1] == 47){
                                check[0] = 1;
                                found = 1;
                            } else{
                                break;
                            }
                        } else if (nrc[i] == 47){
                            check[0] = 1;
                            found = 2;
                        } else{
                            break;
                        }
                    }
                    if (found == 2){
                        for (int j=2; j<size-9; j++){
                            if (nrc[j] >= 97 && nrc[j] <= 122 || nrc[j] >= 65 && nrc[j] <= 90){
                                check[1] = 1;
                            } else{
                                break;
                            }
                        }
                    } else if (found == 1){
                        for (int j=3; j<size-9; j++){
                            if (nrc[j] >= 97 && nrc[j] <= 122 || nrc[j] >= 65 && nrc[j] <= 90){
                                check[1] = 1;
                            } else{
                                break;
                            }
                        }
                    }
                }
                if (nrc[size - i] >= 48 && nrc[size - i] <= 57) {
                    check[2] = 1;
                } else {
                    break;
                }
            } else if (i == 7 && nrc[size - i] == 41) {
                check[3] = 1;
            } else if (i == 8 && nrc[size - i] == 78) {
                check[4] = 1;
            } else if (i == 9 && nrc[size - i] == 40) {
                check[5] = 1;
            } else{
                break;
            }
        }
        for (int i=0; i<6; i++){
            if (check[i] == 1){
                nrc_format = 1;
                country = 1;
            } else{
                nrc_format = 0;
                break;
            }
        }
    } else if (size == 9){
        if (nrc[0] == 83 || nrc[0] == 84 || nrc[0] == 77 || nrc[0] == 70 || nrc[0] == 71){
            if (nrc[size-1] >= 65 && nrc[size-1] <= 90){
                for (int i = 0; i < size-2; i++) {
                    if (nrc[i+1] >= 48 && nrc[i+1] <= 57){
                        nrc_format = 1;
                        country = 2;
                    } else{
                        nrc_format = 0;
                        country = 0;
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    char nrc_card[20];
    while (1) {
        printf("enter your nrc : ");
        scanf(" %[^\n]", &nrc_card[0]);
        nrc_validation(nrc_card);
        if (nrc_format == 1){
            printf("your nrc format is correct and save!\n");
            if (country == 1){
                printf("your country is Myanmar");
            } else if (country == 2){
                printf("your country is Singapore");
            }
            break;
        } else{
            printf("try again!");
        }
    }
    return 0;
}






//    int size = size_array(nrc);
//    int num_count[7] = {0,0,0,0,0,0,0};
//    for (int i=1; i<size+1; i++){
//
//        if (nrc[size-i] >= 48 && nrc[size-i] <= 57){
//            if (num_count[0] == 6){
//                num_count[6]++;
//            } else {
//                num_count[0]++;
//            }
//        } else if (nrc[size-i] == 41){
//            num_count[1]++;
//        } else if (nrc[size-i] == 78){
//            num_count[2]++;
//        } else if (nrc[size-i] == 40){
//            num_count[3]++;
//        } else if (nrc[size-i] >= 65 && nrc[size-i] <= 90 || nrc[size-i] >= 97 && nrc[size-i] <= 122){
//            num_count[4]++;
//        } else if (nrc[size-i] == 47){
//            num_count[5]++;
//        }
//
//    }
//
//    for (int i=0; i<7; i++){
//        if (num_count[i] >= 1 && num_count[0] == 6){
//            nrc_format = 1;
//        } else{
//            nrc_format = 0;
//            break;
//        }
//    }




