#include"quicksort.h"


clock_t start, stop;
double duration, ticks, total_time;
int N[] = { 10,20,30,50,80,100,200,300,400,500,600,700,800,900,1000};

/*
 By recursively calling quick sort, for array a[P ,Q-1] and
 a[Q + 1 ,R] sort
 */
void quicksort(std::vector<int> &A,int p,int q)
{
    if(q-p>=2)
    {
        int i=partition(A,p,q);
        quicksort(A,p,i-1);
        quicksort(A,i+1,q);
    }
    else
    {
        if(A[p]>A[q] && p<q)
        {
            int temp=A[p];
            A[p]=A[q];
            A[q]=temp;
        }
    }
}
/*
Different from the method of always using a [R] as the
 principal component, a random sampling randomization
 technique is adopted to make the subordinate array a
 [P R] randomly selects an element as the principal
 element. In order to achieve this goal, a [R] is first
 transformed from a [P Exchange of a randomly selected
 element in R]. Through the sequence P In the random
 sampling of R, we can ensure that the principal element
 x = a [R] is selected from the R-P + 1 elements of the
 subarray equitably. Because the principal element is
 selected randomly, the partition of the input array
 is relatively balanced, so as to obtain better expected performance.
 */
int partition(std::vector<int> &A,int p,int q)
{
    int temp,i,j,value,rand_value;
    
    rand_value=rand()%(q-p+1)+p;
    temp=A[rand_value];
    A[rand_value]=A[p];
    A[p]=temp;
    
    value=A[p];
    i=p;
    for(j=p+1;j<=q;j++)
    {
        if(A[j]<=value)
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i];
    A[i]=A[p];
    A[p]=temp;
    return i;
}

//used to generate the values of array
void generate_array(int N,std::vector<int> &A)
{
    int i=0,j,flag=1;
    while(i<N)
    {
        flag=1;
        A[i]=rand();
        for(j=0;j<i;j++)
        {
            if(A[j]==A[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)continue;
        i++;
    }
}

/*
 assign value for N from
 { 10,20,30,50,80,100,200,300,400,500,600,700,800,900,1000}
 and test the run time of quicksort
 */
void test()
{
    for (int i = 0;i < 15;i++)
    {
        printf("When N is %d,we can get the information:\n", N[i]);
        std::vector<int> a(N[i]);
        generate_array(N[i],a);
        
        start = clock();  //we use "start" to record the begining of the function.

        quicksort(a,0,N[i]-1);
        
        stop = clock();  //we use "stop" to record the end of the function
        
        ticks = (double)(stop - start);
        total_time = ((double)(stop - start)) / CLK_TCK;
        duration = total_time ;
        printf("ticks:%lf \t total_time:%lf \t duration:%lf \t \n\n", ticks, total_time, duration);
    }
}
