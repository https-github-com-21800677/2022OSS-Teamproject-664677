#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cafe.h"

int loadFile(Cafe *c[]){
    int count = 0;
    FILE *fp;
    fp = fopen("cafe.txt","r"); //파일 오픈
    if (fp == NULL){ //파일이 없으면 종료
        printf("=>파일없음\n");
        return 0;
    }
    for(int i=0;i<20;i++,count++){
        c[i] = (Cafe *)malloc(sizeof(Cafe));
        if(feof(fp)) break;
        fscanf(fp,"\n%[^\n]",c[i]->name);
        fscanf(fp,"\n%[^\n]",c[i]->expl);
        fscanf(fp,"\n%[^\n]",c[i]->type);
        fscanf(fp,"\n%[^\n]",c[i]->taste);
        fscanf(fp,"%d",&c[i]->price);
        fscanf(fp,"%d",&c[i]->ordernum);
        fscanf(fp,"%d",&c[i]->orderprice);
    }
    fclose(fp);
    printf("로딩 완료!\n");
    return count;
} //파일 불러오기 - 정승민
void saveFile(Cafe *c[],int count){
    FILE *fp;
    fp = fopen("cafe.txt","wt");
    for(int i=0;i<count;i++){
        if (c[i] == NULL) continue;
        fprintf(fp,"%s\n%s\n%s\n%s\n%d\n%d\n%d",c[i]->name, c[i]->expl, c[i]->type, c[i]->taste, c[i]->price, c[i]->ordernum, c[i]->orderprice);
    }
    fclose(fp);
    printf("저장 성공!");
} //파일 저장 - 정승민
void searchName(Cafe *c[],int count){
    char name[100];
    int index = 0;
    printf("검색할 디저트 이름은?");
    getchar();
    scanf("%[^\n]s",name);
    getchar();
    printf("이름\t설명\t종류\t맛\t가격\n");
    printf("============================\n");
    for(int i = 0; i<count; i++, index++){
        char *ptr = {NULL};
        ptr = strstr(c[i]->name,name);
        if(ptr!= NULL) readProduct(*c[index]);
    }
}  //이름 검색 - 정지우
void searchTaste(Cafe *c[],int count){
    char taste[100];
    int index = 0;
    printf("검색할 디저트의 맛은?");
    getchar();
    scanf("%[^\n]s",taste);
    getchar();
    printf("이름\t설명\t종류\t맛\t가격\n");
    printf("============================\n");
    for(int i = 0; i<count; i++, index++){
        char *ptr = {NULL};
        ptr = strstr(c[i]->taste,taste);
        if(ptr!= NULL) readProduct(*c[index]);
    }
}  //맛 검색 - 정지우

void addOrder(Cafe *c[],  int count){
    int index;
    listProduct(c,count);
    int numb;
    printf("\n 주문할 상품 번호는 (취소 :0)?");
    scanf("%d",&index);
    if(index == 0) {
        return;
    }
    else{
        printf("주문할 갯수는? ");
        scanf("%d",&numb);
        
        c[index-1]->ordernum +=  numb;
        return;
    }
}//주문 추가 - 정지우
void updateOrder(Cafe * c[], int count){
    int index;
    listProduct(c,count);
    listOrder(c,count);
    printf("\n 수정할 상품 번호는 (취소 :0)?");
    scanf("%d",&index);
    if(index == 0) {
        return;
    }
    else{
        printf("수정할 갯수는? ");
        scanf(" %d", &c[index-1]->ordernum);
        return;
    }
}//주문 수정 - 정지우
void listOrder(Cafe * c[], int count){
    printf("번호\t상품명\t 수량\t 가격\t\n");
    printf("======================\n");
    int total = 0;
    for(int i=0;i<count;i++){
        if(c[i]==NULL) continue;
        c[i]->orderprice = c[i]->price*c[i]->ordernum;
        printf("%d\t",i+1);
        readOrder(*c[i]);
        total +=c[i]->orderprice;
    }
    printf("\n");
    printf("총 가격은 %d원입니다\n", total);
}//모든 주문 출력 - 정지우
void readOrder(Cafe c){
    printf("%s\t %d\t %d\n", c.name, c.ordernum, c.orderprice);
}//1개의 주문 출력, 정지우
int selectMenu(){
    int menu;
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 맛 검색\n");
    printf("8, 주문 조회\n");
    printf("9. 주문추가\n");
    printf("10. 주문수정\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    printf("\n");
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
    printf("상품의 가격은? ");
    scanf("%d",&c->price);
    c->ordernum = 0;
    c->orderprice = 0;
    return 1;
} //새로운 상품을 추가하는 함수 - 정승민
void readProduct(Cafe c){
    printf("%s\t%s\t%s\t%s\t%d\n", c.name, c.expl, c.type, c.taste, c.price);
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
        printf("상품의 가격은? ");
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
} 
//모든 상품을 출력하는 함수 - 정승민
