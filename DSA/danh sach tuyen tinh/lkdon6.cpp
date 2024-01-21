#include<stdio.h>
void Xoadau(LIST &ds){
	NODE*p=new NODE;
	p=ds.pHead;
	ds.pHead=ds.pHead->next;
	p->next=NULL;
	delete p;
}
void Xoacuoi(LIST &ds){
	for(NODE*k=ds.pHead;k!=NULL;k=k->next)
	{
		if(k->next=ds.pTail){

			delete ds.pTail;
			k->next=NULL;
			ds.pTail=k;
		}
	}
}
void XoaKhoaK(LIST &ds,int data){
	NODE*p=new NODE;
	if(ds.pHead->data==data){
		Xoadau(ds);
		return;
	}
	if(ds.Tail->data==data){
		Xoacuoi(ds);
		return ;
	}
	for(NODE*k=ds.pHead;k!=NULL;k=k->next){
		if(k->data==data){
			p->next=k->next;
			delete k;
			return;
		}
		p=k;
	}
}
void HuyDS(LIST &ds){
    //duyet toan bo danh sach
    for(NODE *k = ds.pHead; k != NULL; k = k ->next)
    {
        //tao node p gan bang phan tu dau danh sach
        Node *p = ds.pHead;
        //gan phan tu dau danh sach bang p->next
        ds.pHead = p->next;
        //xoa di node p
        delete p;
    }
    //gan phan tu cuoi danh sach ve NULL vi khi k==ds.pTail thi delete p xong ds.Head==NULL
    ds.pTail = NULL;
}
int main()
{
	
}