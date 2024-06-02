#include<windows.h>
#include<stdio.h>
void routin(int *n) {
    printf("hello im %d \n", *n);
}

int main() {
    int i, P[5]; DWORD ID;
    HANDLE HHandle[5];
    for (int i = 0; i < 5; i++) {
        P[i] = i;
        HHandle[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)routin, &P[i], 0, &ID);
        printf("thread %d was created \n", ID);
    }
    for (i=0;i < 5;i++) WaitForSingleObject(HHandle[i],INFINITE);

}