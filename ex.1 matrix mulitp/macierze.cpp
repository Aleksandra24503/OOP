#include <iostream>
#include <vector>

using namespace std;

int main()
{

     int p,q,r;

    cout<<"Enter number of columns in first matrix"<<endl;
    cin>>q;
    cout<<"Enter number of rows in first matrix"<<endl;
    cin>>p;

   int**A=new int*[p];
   for(int i =0;i<p;i++)
   {
       A[i]=new int[q];
   }



    cout<<"Enter number of columns in second matrix"<<endl;
    cin>>r;
    int**B=new int*[q];
   for(int i =0;i<q;i++)
   {
       B[i]=new int[r];
   }




    cout<<"Enter values of first matrix"<<endl;

    for(int i=0;i<p;i++)
    {

        for(int j=0;j<q;j++)
        {
            cin>>A[i][j];
        }
        cout<<endl;

    }

    cout<<"Enter values for second matrix"<<endl;
    for(int i=0;i<q;i++)
    {

        for(int j=0;j<r;j++)
        {
            cin>>B[i][j];
        }
        cout<<endl;
    }




     int**D=new int*[p];
   for(int i =0;i<p;i++)
   {
       D[i]=new int[q];

   }

   for(int i =0;i<p;i++)
{
      for(int j=0;j<r;j++)

      {
          D[i][j]=0;
      }
}
cout<<"Result Matrix"<<endl;

 for (int i = 0; i < p; i++)
 {
        for (int j = 0; j < q; j++)
        {

            for (int k = 0; k < r; k++)
                D[i][k] += A[i][j] * B[j][k];
        }

 }











   for(int i =0;i<p;i++)
   {
       for(int j =0;j<r;j++)
       {
           cout<<" "<<D[i][j];

       }
       cout<<endl;

   }


for(int i =0;i<p;i++)
{
    delete[]A[i];
}

for(int i =0;i<q;i++)
{
    delete[]B[i];
}
for(int i =0;i<r;i++)
{
    delete[]D[i];
}



    return 0;
}
