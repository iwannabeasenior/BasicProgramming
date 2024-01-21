#include<stdio.h>
//dao nguoc danh sach lien ket

void DaoNguocDS(LIST &ds){
    //khoi tao NODE hien tai
    NODE *current = ds.pHead;
    //khoi tao NODE truoc NODE hien tai
    NODE *prev = NULL;
    //khoi tao NODE sau NODE hien tai
    NODE *next = NULL;
    //duyet tu dau den cuoi danh sach
    while (current != NULL) {
        //gan next bang node phia sau node hien tai
        next = current->next;
        //gan con tro next cua/ node hien tai ve node phia sau no
        current->next = prev;
        //gan node phai sau bang node hien tai
        prev = current;
        //gan hien tai bang node phia sau
        current = next;
    }
    //gan lai node dau danh sach lien ket
    ds.pHead = prev;
}
int main()
{

}