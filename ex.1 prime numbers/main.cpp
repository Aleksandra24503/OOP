#include <iostream>

using namespace std;

int main()
{  int a,N;
    do{

    cout << "enter interval"<<endl;
    cin>>a;
    if(a<0)a=0;
    cin>>N;
    }while(N<0);




    int*T=new int[N];
T[0]=0;
T[1]=0;



for(int i=2;i<N;i++)
{
    T[i]=0;


}
for(int i=2;i<N;i++)
{

    T[i]=i;

}

for(int i=2;i<N;i++)
{

    for(int j=i;j<N;j++)
    {
    if(T[j]%i==0)

    {
        if(T[j]==i)
            T[j]=1;
        else T[j]=0;
    }

    else if(T[j]%i!=0)
        continue;

    }


}

int index;

for(int i=2;i<N;i++)
{
    if(T[i]==1)
    {

        index=i;
        cout<<index<<", ";


    }
    else continue;
}



    return 0;
}




