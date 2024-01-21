#include<iostream>
#include<cstring>

// Nguyen Trung Thanh -20215482
using namespace std;

int max(int &a,int &b){
    return a>b?a:b;
}
int min(int &a , int &b){
    return a>b?b:a;
}

struct bigNum
{
    char sign;
    char num[101];
    bigNum(){
        sign='0';
        for(int i=0;i<101;i++){
        num[i]='a';
        }
    }
};

int length_bigNum(bigNum& a){
    int count=0;
    while(a.num[count]!='\0'){
        count++;
    }
    return count;
}
// cong 2 so khong dau
char* add (char* aNum , char* bNum){
    // char cNum[101];
    char cNum[101]="";
    int count1 =0;
    while(aNum[count1]!='\0'){
        count1++;
    }

    int count2=0;
    while(bNum[count2]!='\0'){
        count2++;
    }
    int max1=max(count1,count2);
    
    int min1=min(count1,count2);
    
    int distance=max1-min1;
    int flag=0;
    
    if(max1==count1){
        for (int i = 0; i < count1; i++)
        {
            if((i-distance)>=0)
            {
            int a=aNum[i]-'0';
            int b=bNum[i-distance]-'0';
            int c=(a+b+flag)%10;
            flag=(a+b)/10;
            char c_Num=c+'0';
            cNum.insert(0,c_Num);
            }
            else{
                int a=aNum[i]-'0';
                int c=a+flag;
                char c_Num=c+'0';
                cNum.insert(0,c_Num);
            }
        }
        
    }
    else{
        for (int i = 0; i < count2; i++)
        {
            if((i-distance)>=0)
            {
            int a=aNum[i]-'0';
            int b=bNum[i-distance]-'0';
            int c=(a+b+flag)%10;
            flag=(a+b)/10;
            char c_Num=c+'0';
            cNum.insert(0,c_Num);
            }
            else{
                int b=bNum[i]-'0';
                int c=b+flag;
                char c_Num=c+'0';
                cNum.insert(0,c_Num);
            }
        }
    }
    
    return cNum;
}

//tru 2 so khong dau
char* sub(char a[],char b[]){

}
bigNum operator + (const bigNum&a,const bigNum&b){
    bigNum c;
    c.num=add(a.num, b.num);
    c.sign=1;
    return c;
}
ostream& operator << (ostream& out,const bigNum &a){
    if(a.sign=='1'){
        out<<a.num;
    }
    else {
        out<<"-"<<a.num;
    }
    return out;
}
istream& operator>> (istream& in,const bigNum&a){
    in>>a.sign>>a.num;
    return in;
}

int main(){
    bigNum a;
    bigNum b;
    cin>>a;
    cin>>b;
    bigNum c=a+b;
    cout<<c<<endl;
    // cout<<a<<endl;
    // cout<<b<<endl;
}