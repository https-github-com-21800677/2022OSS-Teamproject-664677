#include <stdio.h>
#include "cafe.h"
#include <stdlib.h>

int main(void){
    Cafe *clist[20];
    int menu;
    //int count = loadFile(clist);
    int count = 0;
    Order *olist[20]={0};
    
    while (1){
        menu = selectMenu();
        if(menu == 0)break;
        if(menu == 1){
            listProduct( clist ,count);
        }else if(menu == 2){
             clist[count] = (Cafe *)malloc(sizeof(Cafe));
            count = count + createProduct(clist[count]);
        }else if(menu == 3){
            updateProduct(clist,count);
        }else if(menu == 4){   
            deleteProduct(clist, count);
        }else if(menu == 5){
             searchName(clist,count);
        }else if(menu == 6){

        }else if(menu == 7){
            searchTaste(clist,count);
        }else if(menu == 8){
             listOrder(clist,olist,count);
        }else if(menu == 9){
            olist[count] = (Order*)malloc(sizeof(Order));
            addOrder(clist, olist, count);
        }else if(menu == 10){
            updateOrder(clist, olist, count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
