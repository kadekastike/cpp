#include <iostream>

using namespace std;

struct node {
    char namaMhs[20];
    int Npm;
    float ip;
    node *next;
 };
 node *awal_ptr=NULL;
 node *posisi;
 int pilih;

void tambahData()
 {
  node *temp, *temp2; //node sementara
   //isi data
    temp=new node;
    cout<<"Nama Mahasiswa  : ";cin>>temp->namaMhs;
    cout<<"NPM Mahasiswa   : ";cin>>temp->Npm;
    cout<<"IP Mahasiswa : ";cin>>temp->ip;
    temp->next=NULL;
    //inisialisasi pointer ketika kosong
    if(awal_ptr==NULL)
    {
      awal_ptr=temp;
      posisi=awal_ptr;
    }
    else
    {
     temp2=awal_ptr;
     while(temp2->next != NULL)
       {
          temp2 = temp2->next;
       }
       temp2->next=temp;
    }
 }

void tampilkanData()
 {
    node *temp;
    temp = awal_ptr;
    if(temp == NULL)
       cout<<"List kosong"<<endl;
    else
    {
       cout<<endl<<endl;
       while(temp != NULL)
       {
          cout<<"Nama Mahasiswa : "<<temp->namaMhs<<"  ";
          cout<<"NPM Mahasiswa : "<<temp->Npm<<"  ";
          cout<<"IP Mahasiswa : "<<temp->ip;
          if (temp == posisi)
             cout<<"   << posisi simpul";
          cout<<endl;
          temp=temp->next;

      }
      cout<<"Akhir list"<<endl;
    }
}
void hapusDataAkhir()
 {
  node *temp1, *temp2;
  if (awal_ptr == NULL)
   cout << "List kosong!" << endl;
  else
  {
   temp1 = awal_ptr;
   if (temp1->next == NULL)
   {
    delete temp1;
    awal_ptr = NULL;
   }
   else
   {
   while (temp1->next != NULL)
    {
     temp2 = temp1;
     temp1 = temp1->next;
    }
    delete temp1;
    temp2->next = NULL;
   }
  }
 }
 void hapusDataAwal()
 {
  node *temp;
  temp = awal_ptr;
  awal_ptr = awal_ptr->next;
  delete temp;
 }

int main() {
    awal_ptr=NULL;
    do
    {
      tampilkanData();
      cout<<"Menu Pilihan"<<endl;
      cout<<"0. Keluar program"<<endl;
      cout<<"1. Tambah Data Mahasiswa"<<endl;
      cout<<"2. Hapus Data Mahasiswa (Data Terakhir)"<<endl;
      cout<<"3. Hapus Data Mahasiswa (Data Awal)"<<endl;
      cout<<"Pilihan >> ";cin>>pilih;
      switch(pilih)
       {
          case 1: tambahData();break;
          case 2: hapusDataAkhir();break;
          case 3: hapusDataAwal();break;
       }
    }
  while(pilih !=0);
}
