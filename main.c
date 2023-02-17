#include "stdio.h"

struct node{

    char name[20];
};

struct node db[10];

int main(){

    char *name;
    printf("enter name : ");
    scanf(" %[^\n]",&name[0]);

    printf("%s",name[0]);







//    printf("enter your name : ");
//    scanf(" %[^\n]",&db[0].name[0]);
//
//    printf("%s",db[0].name);

    return 0;
}
