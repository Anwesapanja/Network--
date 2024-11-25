#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    /******************************************* */
    /******************************************* *//**/
    int A_length,B_length,i,j;
    char A[100],B[100],C[100];
    printf("enter the string: ");
    scanf("%s",A);
    printf("\n\nenter the divisor: ");
    scanf("%s",B);
    printf("the string length will be: ");
    A_length=strlen(A);
    printf("%d",A_length);
    printf("\nthe divisor length will be: ");
    B_length=strlen(B);
    printf("%d",B_length);
    for(i=0;i<B_length-1;i++)
    {
        A[A_length+i]='0';
    }
    A[A_length+i]='\0';
    printf("\n\n the generated string will be: %s",A);
    strcpy(C,A);
    for(i=0;i<A_length;i++)
    {
        if(C[i]=='1')
        {
            for(j=0;j<B_length;j++)
            {
                if(C[i+j]==B[j])
                    C[i+j]='0';
            else
                    C[i+j]='1';
            }
        }   
    }

    strcpy(A,C);
    printf("\nThe codeword is:");
    puts(A);
    send(sd,A,sizeof(A),0);
    close(sd);
    return 0;
}        