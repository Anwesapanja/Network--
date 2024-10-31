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
    char A[40]={0},D[100]={0};
    //int length_A,length_D,segment,x,sum[100],carry,k,t,i;
    int length_A, length_D, segment = 0, x = 0, sum[100] = {0}, carry = 0, k = 0, t = 0, i = 0;
    printf("enter the string: ");
    scanf("%s",A);
    printf("\nenter the segment: ");
    scanf("%d",&segment);
    length_A=strlen(A);
    printf("\nthe length of the string_A %d",length_A);
    if(length_A %segment!=0)
    {
        x=segment-(length_A%segment);
        for(int i=0;i<x;i++)
        {
            D[i]='0';
        }
        D[x]='\0';
        strcat(D,A);
        printf("\nthe new string will be: ");
        puts(D);
    }
    else{
    strcpy(D,A);
    }
    length_D=strlen(D);
    printf("\n the new length will be: %d",length_D);
    //********************************************* ******************/
    //********************************************* ******************/

    /*for(int i=0;i<segment;i++)
    {
        sum[i]=0;
    } */   
    for(int i=length_D;i>0;i=i-segment)
    {
         carry=0;
        k=segment-1;
        for(int j=i-1;j>=i-segment;j--)
        {
            t=(sum[k]+(D[j]-48)+carry);
            sum[k]=t%2;
            carry=t/2;
            k--;
        }
        if(carry==1)
        {
            for(int j=segment-1;j>=0;j--)
            {
                t=sum[j]+carry;
                sum[j]=t%2;
                carry=t/2;
            }
        }
    } 

    /*********for doing complement*** */
    printf("\n Checksum = ");
    for(int i=0;i<segment;i++)
    {    
        if(sum[i]==0)
            sum[i]=1;
        else
           sum[i]=0;
            printf("%d",sum[i]);
        // i=0;    
        D[length_D+i]=sum[i]+48;
    }
    D[length_D+segment]='\0';
    printf("\ncode word is:");
    puts(D);
    send(sd,D,sizeof(D),0);

    close(sd);
    return 0;
}    