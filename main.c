#include <stdio.h>
#include "cafe.h"

int main(void){
    Cafe clist[20];
    int menu;
    int count = loadfile(clist);
    
 
    while (1){
        menu = selectMenu();
        if(menu == 0)break;
        if(menu == 1){
            listProduct(clist,count);
        }else if(menu == 2){
            createProduct(clist);
            count ++;
        }else if(menu == 3){
            updateProduct(clist,count);
        }else if(menu == 4){   
            deleteProduct(clist, count)
        }else if(menu == 5){

        }else if(menu == 6){

        }else if(menu == 7){

        }else if(menu == 8){

        }else if(menu == 9){

        }
    }
    printf("종료됨!\n");
    return 0;
}
