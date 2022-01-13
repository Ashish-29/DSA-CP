#include<iostream>
#include<conio.h>
using namespace std;

int main(void) {
   float a[10][10], b[10], m[10], n[10];
   
   int p , q ;
   cout << "Enter size of 2D array : "; cin >> p;
   cout << "\nEnter the no. of iteration : "; cin >> q;

   for (int i = 0; i < p; i++) {
      for (j = 0; j < p; j++) {
         cout << "a[" << i << ", " << j << " ]=";
         cin >> a[i][j];
      }
   }

   cout << "\nEnter values to the right side of equation\n";
   for (int i = 0; i < p; i++) {
      cout << "b[" << i << ", " << j << " ]=";
      cin >> b[i];
   }

   cout << "Enter initial values of x\n";
   for (int i = 0; i < p; i++) {
      cout << "x:[" << i<<"]=";
      cin >> m[i];
   }

   while (q--) {
      for (int i = 0; i < p; i++) {
         m[i] = b[i];
         for (int j = 0; j < p; j++)
            if (j != i) m[i] = m[i] - (a[i][j] * m[j]);
         m[i]/=a[i][i];

         cout<<"x"<<i + 1 << "="<<m[i]<<" ";
      }
      cout << "\n";
   }

   return 0;
}