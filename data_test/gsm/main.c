#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* Number of clock ticks per second. A clock tick is the unit by which
 * processor time is measured and is returned by 'clock'.
 */

#define CLK_TCK CLOCKS_PER_SEC
clock_t start, end;


int arr[10000000][2];//0:0,1:5
//可二次优化，左数第五位仅有两个，空间复杂度减半，时间复杂度减半，但是要处理之后0被消除的情况
long pointer;
struct info
{
    char number[11];
    char typ[2];
    char t[4];
};
int main()
{
    start = clock();
    long long number;
    int typ,t;
    char temp[10];
    struct info dat;
    FILE *in,*out;
    in=fopen("gsm.dat","r");
    while(!feof(in))
    {
        //read one line and process it
        fgets(dat.number,12,in);
        number=atol(dat.number);
        fgets(dat.typ,3,in);
        typ=atol(dat.typ);
        fgets(dat.t,5,in);
        t=atol(dat.t);
    
        fgets(temp,10,in);
        
        if(number<10000000)continue;//排除最后一行不完整数据
        //测试规律观察规律
        
        //arr[pointer++]=number;
        //if(number/100000000!=139)printf("false");//前三位为139
        //number-=13900000000;
        //if((number/10000000)!=5 && (number/10000000)!=0)printf("false");//第四位为0或5
        //number%=10000000;
        //if((number/1000000)!=5 && (number/1000000)!=6)printf("false");//第五位为6或5
        
        //测试完毕：前三位为139 第四位为0或5 第五位为6或5
        
        //数据存入数组，利用hash完成存储
        //n1为后七位，n2为右数第八位，n3为右数第七位
        long long n1,n2,n3;
        
        n1=number-13900000000;
        n2=n1/10000000;
        n3=(n1%10000000)/1000000;
        n1=n1%10000000;
        
        int i,money,mintues;
        if(n2==0)i=0;
        else i=1;
        
        
        if(t%60==0)mintues=t/60;
        else mintues=t/60+1;
        
        
        if(typ==0)money=40*mintues;
        else money=20*mintues;
        
        arr[n1][i]+=money;
            
        //printf("%lld %d %d %lld %lld %lld\n",number,typ,t,n1,n2,n3);
    
    }
    
    //导入数据
    out=fopen("data.dat","w+");
    char *str[2]={"1390","1395"};
    char tempstr[20];
    char *blank=" ";
    char *change="\n";
    for(int i=0;i<2;i++)
        for(int j=5000000;j<7000000;j++)
        {
            if(arr[j][i]!=0)
            {
                //itoa(j,tempstr,10);
                fputs(str[i],out);
                //fputs(tempstr,out);
                fprintf(out,"%d",j);
                fputs(blank,out);
                //itoa(arr[j][i],tempstr,10);
                fprintf(out,"%d",arr[j][i]);
                //fputs(tempstr,out);
                fputs(change,out);
            }
        }
    
//    fputs(str[1],out);
//    fputs("1",out);
//    fputs(blank,out);
//    fputs("111",out);
//    fputs(change,out);
    
    fclose(out);
    fclose(in);
    
    end = clock();
    printf("time: %f s\n", ((double)(end - start)) / CLOCKS_PER_SEC );
    return 0;
}
