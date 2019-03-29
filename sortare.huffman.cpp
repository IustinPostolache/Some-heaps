/*
HEAP
Heap este un arbore binar in care

Intr-un nodul are nume  si informatie astfel sunt verificate :
1) Nod i daca are descendenti acestia sunt 2*i si 2*i+1
2) Informatia unui nod i este mai mare decat a tuturor descendentilor

Exemplu :

Fie n=5 ; M={533,244,104,87,18}

           1[533]
           1/        \
         2[244]    3 [104]
        1/        \
     4[87]     5[18]

H: 533 244 104 87 18
       1     2     3    4   5

In heap daca caut inf 18 colectez codul 110

Obs : Un sir ordonat descrescator il putem considera heap !!

Metode de construire a unui heap :

1) prin sortare ( solicitanta ca numar de operatii )
2) prin insertie repetata a unui cat nou nod intr-un heap existent

pornesc cu heap singleton
la un pas i=2..n inserez un al i-lea nod in heap
obs ca
          nou nod =i ===> tatal =|i/2|

daca inf nod tata >= inf nod fiu ===> consider nodul deja adaugat
                                           altfel  ===>
                                           atata timp cat inf nod tata < inf nod fiu
                                           {
                                           - interschimb inf tata fiu
                                           - fiu devine fostul tata
                                           - tata devine tatal noului fiu
                                           }


*/
#include<iostream>
using namespace std;
int n=5;
int M[100]={35565,533,244,104,87,18};

int read_data() {}
int compute_data(){}

int RSD_heap(int nume_nod,int heap_size)
{
    if (nume_nod<=heap_size)
    { cout<<M[nume_nod]<<" ";
       RSD_heap(nume_nod*2,heap_size);
       RSD_heap(nume_nod*2+1,heap_size);}
}

int find_heap(int nume_nod,int heap_size,int value)
{
    if (M[nume_nod]==value) return 1;
    else {
            if (nume_nod<=heap_size) { cout<<"1 ";
                                                       find_heap(nume_nod*2,heap_size,value);
                                                       cout<<"0 ";
                                                       find_heap(nume_nod*2+1,heap_size,value);}
           }
return 0;
}

int main()
{ read_data();
   compute_data();
   RSD_heap(1,n);
   cout<<endl;
   cout<<"Some huffman code : "<<endl;
   find_heap(1,n,87);
}
