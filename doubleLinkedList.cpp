#include <iostream>
#include <stdio.h>

using namespace std;

int pil;

struct node
{
     char namaMhs [20];
     int npm;
     float ip;
     node *prev, *next;
};

node *baru, *head=NULL, *tail=NULL,*hapus,*bantu;


void dataBaru()
{
     baru = new(node);
     cout<<"Nama Mahasiswa      : ";cin>>baru->namaMhs;
     cout<<"NPM Mahasiswa       : ";cin>>baru->npm;
     cout<<"IP Mahasiswa        : ";cin>>baru->ip;
     baru->prev=NULL;
     baru->next=NULL;
}

void tampilkanData()
 {
      if (head==NULL)
           cout<<"Kosong";
      else
      {
          bantu=head;
          while(bantu!=NULL)
          {
             cout<<"Nama Mahasiswa   : "<<bantu->namaMhs<<endl;
             cout<<"NPM Mahasiswa    : "<<bantu->npm<<endl;
             cout<<"IP Mahasiswa     : "<<bantu->ip<<endl<<endl;
             bantu=bantu->next;
          }
      }

}

void tambahDataBelakang()
{
     dataBaru();
     if(head==NULL)
      {
         head=baru;
         tail=baru;
      }
     else
     {
         tail->next=baru;
         baru->prev=tail;
         tail=baru;
     }
     cout<<endl<<endl;
     tampilkanData();
}

void tambahDataDepan()
 {
     dataBaru();
     if(head==NULL)
     {
         head=baru;
         tail=baru;
     }
     else
     {
         baru->next=head;
         head->prev=baru;
         head=baru;
     }
     cout<<endl<<endl;
     tampilkanData();
 }

void hapusDataDepan()
 {
     if (head==NULL)
         cout<<"Kosong";
     else if (head->next==NULL)
     {
       hapus=head;
       head=NULL;
       tail=NULL;
       delete hapus;
     }
     else
     {
         hapus=head;
         head=hapus->next;
         head->prev=NULL;
         delete hapus;
     }
     cout<<endl<<endl;
     tampilkanData();
 }

void hapusDataBelakang()
 {
     if (head==NULL)
         cout<<"Kosong";
     else if (head->next==NULL)
     {
       hapus=head;
       head=NULL;
       tail=NULL;
       delete hapus;
     }
     else
     {
      hapus=tail;
      tail=hapus->prev;
      tail->next=NULL;
      delete hapus;
     }
     cout<<endl<<endl;
     tampilkanData();
}

int main()
 {
     do
     {
         cout<<"MENU PILIHAN"<<endl;
         cout<<"0. Keluar Program" <<endl;
         cout<<"1. Tambah Data Mahasiswa (Data Depan)"<<endl;
         cout<<"2. Tambah Data Mahasiswa (Data Akhir)"<<endl;
         cout<<"3. Hapus Data Depan"<<endl;
         cout<<"4. Hapus Data Belakang"<<endl;
         cout<<"5. Tampilkan Data"<<endl;
         cout<<"Pilihan : ";
         cin>>pil;
         switch (pil) {
            case 1 : tambahDataDepan(); break;
            case 2 : tambahDataBelakang();break;
            case 3 : hapusDataDepan();break;
            case 4 : hapusDataBelakang();break;
            case 5 : tampilkanData();break;
         }
     }
 while(pil!=0);
 }
