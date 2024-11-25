#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
    int sd,cd,cadl;
    char A[500];
    struct sockaddr_in sad,cad;
    //char str[50];
    sd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sad.sin_family=AF_INET;
    sad.sin_port=htons(9995);
    sad.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(sd, (struct sockaddr *)&sad, sizeof(sad));
    listen(sd,10);
    cadl=sizeof(cad);
    cd=accept(sd, (struct sockaddr *)&cad, &cadl);
    recv(cd,A,sizeof(A),0);
    /****************************** */
    /******************************* */
    /****************************** */
    int A_length,B_length,i,j;
    char B[100],C[100],K[100];
    //printf("enter the string: ");
    printf("\n\nenter the divisor: ");
    scanf("%s",B);
    printf("the string length will be: ");
    A_length=strlen(A);
    printf("%d",A_length);
    printf("\nthe divisor length will be: ");
    B_length=strlen(B);
    printf("%d",B_length);
    for(i=0;i<A_length-(B_length-1);i++)
     {
        if(A[i]=='1')
        {
            for(j=0;j<B_length;j++)
            {
                if(A[i+j]==B[j])
                {
                    A[i+j]='0';
                }
                else
                A[i+j]='1';
            }
        }
     }
     for(i=A_length-(B_length-1),j=0;i<A_length,j<A_length-(B_length-1);i++,j++)
     {
        K[j]=A[i];
     }
    int h;
    int K_length=strlen(K);
    printf("\nthe length of k will be: %d",K_length);
    for(i=0;i<K_length;i++)
    {
        if(K[i]==0)
        {
           h=1;
        }
        else
        h=0;
    }  
    if(h==1)
        printf("wrong data");
    else
        printf("\nright data");     
    close(cd);
    close(sd);
    return 0;
}     