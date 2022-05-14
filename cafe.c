#include <stdio.h>
#include <stdlib.h>
#include "cafe.h"

int loadFile(Cafe *c[]); //파일 불러오기 - 정승민
void saveFile(Cafe *c[],int count); //파일 저장 - 정승민
void searchName(Cafe *c[],int count){
    char name[100];
    int index = 0;
    printf("검색할 디저트 이름은?");
    getchar();
    scanf("%[^\n]s",name);
    getchaar();
    printf("이름\t설명\t종류\t맛\t가격\n");
    printf("============================");
    for(int i = 0; i<ount; i++, index++){
        char *ptr = {NULL};
        ptr = strstr(c[i]->name,name);
        if(ptr!= NULL) readProduct(*c[index]);
    }
}  //이름 검색 - 정지우
void searchPrice(Cafe *c[],int count); //가격 검색 - 정지우
void searchTaste(Cafe *c[],int count){
    char taste[100];
    int index = 0;
    printf("검색할 디저트 이름은?");
    getchar();
    scanf("%[^\n]s",taste);
    getchaar();
    printf("이름\t설명\t종류\t맛\t가격\n");
    printf("============================");
    for(int i = 0; i<ount; i++, index++){
        char *ptr = {NULL};
        ptr = strstr(c[i]->taste,taste);
        if(ptr!= NULL) readProduct(*c[index]);
    }
}  //맛 검색 - 정지우
void searchType(Cafe *c[],int count); //종류 검색 - 정지우
void addOrder();
void updateOrder();
void deleteOrder();
void listOrder();
void readOrder();
int selectMenu(){
    int menu;
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장(구현되지 않음)\n");
    printf("6. 이름검색\n");
    printf("7. 설명검색(구현되지 않음)\n");
    printf("8. 맛 검색\n");
    printf("9. 주문추가(구현되지 않음)\n");
    printf("10. 주문수정(구현되지 않음)\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
} //메뉴선택 - 정승민
int createProduct(Cafe *c){
    getchar();
    printf("상품의 이름은? ");
    scanf("%[^\n]s",c->name);
    getchar();
    printf("상품의 설명은? ");
    scanf("%[^\n]s",c->expl);
    getchar();
    printf("상품의 종류는? ");
    scanf("%[^\n]s",c->type);
    getchar();
    printf("상품의 맛은? ");
    scanf("%[^\n]s",c->taste);
    getchar();
    printf("상품의 가격은?");
    scanf("%d",&c->price);
    return 1;
} //새로운 상품을 추가하는 함수 - 정승민
void readProduct(Cafe c){
    printf("%s\t%s\t%s\t%s\t%d", c.name, c.expl, c.type, c.taste, c.price);
} //상품 하나를 출력하는 함수 - 정승민
int updateProduct(Cafe *c[], int count){
    int index;
    listProduct(c,count);
    printf("\n 번호는 (취소 :0)?");
    scanf("%d",&index);
    if(index == 0) {
        return 1;
    }
    else{
        printf("상품의 이름은? ");
        getchar();
        scanf("%[^\n]s",c[index-1]->name);
        getchar();
        printf("상품의 설명은? ");
        scanf("%[^\n]s",c[index-1]->expl);
        getchar();
        printf("상품의 종류는? ");
        scanf("%[^\n]s",c[index-1]->type);
        getchar();
        printf("상품의 맛은? ");
        scanf("%[^\n]s",c[index-1]->taste);
        getchar();
        printf("상품의 가격은?");
        scanf("%d",&c[index-1]->price);
        printf("=> 수정됨!\n");
        return 1;
    }
} //상품을 수정하는 함수 - 정승민
void deleteProduct(Cafe *c[], int count){
    int confirm, index;
    listProduct(c,count);
    printf("번호는? (취소:0)");
    scanf("%d",&index);
    if(index == 0) ;
    else {
        printf("정말 삭제하시겠습니까?(삭제:1)");
        scanf("%d",&confirm);
        if(confirm == 1) {
            free(c[index-1]);
            c[index-1] = NULL;
            printf("삭제됨!");
        }
    }
} //상품 삭제하는 함수 - 정승민
void listProduct(Cafe *c[],int count){
    printf("번호\t이름\t설명\t종류\t맛\t가격\n");
    printf("======================================\n");
    for(int i=0;i<count;i++){
        if(c[i]==NULL) continue;
        printf("%d\t",i+1);
        readProduct(*c[i]);
    }
    printf("\n");
} //모든 상품을 출력하는 함수 - 정승민
