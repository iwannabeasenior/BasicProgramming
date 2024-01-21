#include<stdio.h>
//nhap n phan tu  va chen dau vao dslk don
void Nhap(LIST&ds,int n){
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		NODE*p=new NODE;
		p=Taonode(x);
		Chendau(ds,p);
	}
}
// tuong tu chen cuoi va chen giua

//xuat n phan tu 
//cach 1: bang vong lap for
void Xuat(LIST ds){
    //khoi tao mot node
    NODE *p = new NODE;
    //duyet tu dau danh sach den cuoi danh sach voi dieu kien p!=NULL
    for(p = ds.pHead; p!= NULL; p=p->next){
        //hien thi du lieu cua tung node
        printf("%d\n",p->data);
    }
}
// cach 2: bang vong lap while
void Xuat(LIST ds){
    //tao node p
    NODE *p;
    p = ds.pHead;
    //trong khi node p chua bang NULL (p chua la phan tu cuoi)
    while (p!=NULL){
        //hien thi du lieu
        printf("%d\n",p->data);
        //chuyen sang node tiep theo
        p=p->next;
    }
}
int main()
{

}