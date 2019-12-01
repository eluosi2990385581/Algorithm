#include<iostream>

using namespace std;
#define base 26
typedef unsigned long long _type;
_type str1[100000];
_type length=0;

_type _hash(_type x);
_type _gcd(_type x,_type y);
void next_str(_type value);
void _output();

int main()
{
    str1[0]=1;
    _type n,x,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        temp=_hash(x);
        
        if(!temp)
        {
            next_str(1);
            continue;
        }
        else
        {
            temp=x/_gcd(temp,x);
            next_str(temp);
            continue;
        }
    }
    _output();
    return 0;
}


_type _hash(_type x)
{
    _type hash=0;
    for(_type i=length;i>=0;i--)
    {
        hash=(hash*base+str1[i])%x;
    }
    return hash;
}

//_type _gcd(_type x,_type y)
//{
//    if(y==0)return x;
//    return _gcd(y,x%y);
//}
_type _gcd(_type x,_type y)
{
    while(y)
    {
        _type temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}

void next_str(_type value)
{
    for(int i=0;i<=length;i++)
        str1[i]*=value;
    for(int i=0;i<=length;i++){
        if (str1[i]>=base){
            str1[i+1]+=str1[i]/base;
            str1[i]%=base;
        }
    }
    while(str1[length+1]){
        length++;
        if (str1[length]>=base){
            str1[length+1]+=str1[length]/base;
            str1[length]%=base;
        }
    }
}

void _output()
{
    char str;
    for(int i=0;i<=length;i++)cout<<'a';
    cout<<endl;
    for(_type i=length;i>=0;i--)
    {
        str=str1[i]+'a';
        cout<<str;
    }
    cout<<endl;
}

