typedef struct{
    char name[100];
    char expl[100];
    char type[100];
    char taste[100];
    int price;
}Cafe;

int loadFile(Cafe *c[]); //파일 불러오기 - 정승민
void saveFile(Cafe *c[],int count); //파일 저장 - 정승민
void searchName(Cafe *c[],int count);  //이름 검색 - 정지우
void searchPrice(Cafe *c[],int count); //가격 검색 - 정지우
void searchTaste(Cafe *c[],int count); //맛 검색 - 정지우
void searchType(Cafe *c[],int count); //종류 검색 - 정지우
int selectMenu(); //메뉴선택 - 정승민
int createProduct(Cafe *c); //새로운 상품을 추가하는 함수 - 정승민
void readProduct(Cafe c); //상품 하나를 출력하는 함수 - 정승민
int updateProduct(Cafe *c); //상품을 수정하는 함수 - 정승민
void deleteProduct(Cafe *c[], int count); //상품 삭제하는 함수 - 정승민
void listProduct(Cafe *c[],int count); //모든 상품을 출력하는 함수 - 정승민