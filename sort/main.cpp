#include"quicksort.h"
/*two part:
 the first of these is that you can input the length
 of the array and generating values randomly,and the program
 will print the information of the array before and after sorting.
 the second one is the function "test()"which is introduced in quicksort.h file
*/
int main()
{
    int N;
    
    //the first part of main
    std::cin>>N;
    std::vector<int> a(N);

    generate_array(N,a);
    
    for(int i=1;i<=N;i++)
    {
        std::cout<<a[i-1]<<" ";
        if(i%10==0)std::cout<<std::endl;
    }
        
    std::cout<<std::endl;
    quicksort(a,0,N-1);
    
    for(int i=1;i<=N;i++)
    {
        std::cout<<a[i-1]<<" ";
        if(i%10==0)std::cout<<std::endl;
    }
    
    //the second part of main
    test();
    
    return 0;
}
