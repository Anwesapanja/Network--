#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int sd,cadl;
    struct sockaddr_in sad,cad;
    char str[50];

    sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");

    connect(sd,(struct sockaddr *)&sad,sizeof(sad));
    int len=0,count=0;
    char A[50],B[50],C[50];
    printf("the dataword will be: ");
    scanf("%s",A);
    len=strlen(A);
    printf("the length will be: %d",len);
     for(int i=0;i<len;i++)
    {
        if(A[i]=='1')
        {
            count++;
        }
    }
    printf("\n the number of one will be: %d",count);
    strcpy(B,A);
    if(count%2==0)
    {
        C[0]='0';
        C[1]='\0';
        strcat(B,C);
        printf("\n\n\nthe even parity bit will be: ");
        puts(B);
        C[0]='1';
        C[1]='\0';
        strcat(A,C);
        printf("\nthe odd parity bit will be: ");
        puts(A);
    }
    else
    {
        C[0]='1';
        C[1]='\0';
        strcat(B,C);
        printf("\nthe even parity bit: ");
        puts(B);
        C[0]='0';
        C[1]='\0';
        strcat(A,C);
        printf("\nthe odd parity bit will be: ");
        puts(A);
    }    
    send(sd,A,sizeof(A),0);

    close(sd);
    return 0;
}