#include<bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
/*
name: ten
age: tuoi
month: thang cua ve dang ki
sex: gioi tinh
hk: hanh khach
cccd: ma so ca nhan
*/
typedef struct hanhkhach
{
    string cccd;
    string name;
    char sex;
    int month;
    int age;
    int type;
};
int search(struct hanhkhach hk[], string id,int biendem)//ham phu de ham trong ham
{

    int found =-1;
    for (int i = 0; i < biendem && found==-1; i++)
    {

        if (hk[i].cccd == id) found=i;

        else found=-1 ;
    }

    return found;
}
void clean(struct hanhkhach hk[],int index)//clear du lieu
{
    hk[index].cccd ="";
    hk[index].name ="";
    hk[index].sex =NULL;
    hk[index].age = 0;
    hk[index].month = 0;
    hk[index].type = 0;
}
void displaymenu()
{
    cout<<"==========================================="<<"\n";
    cout<<"            Cong ty xe bus HUST"<<"\n";
    cout<<"                   MENU "<<"\n";
    cout<<"==========================================="<<"\n";
    cout<<" 1. Dang khi hanh khach"<<"\n";
    cout<<" 2. Xoa hanh khach"<<"\n";
    cout<<" 3. Cap nhat thong tin hanh khach"<<"\n";
    cout<<" 4. Danh sach hanh khach"<<"\n";
    cout<<" 5. Tim kiem hanh khach"<<"\n";
    cout<<" 6. Gia han ve thang"<<"\n";
    cout<<" 0. Dung hoat dong"<<"\n";
}
void them(struct hanhkhach hk[], int& biendem)//ham nhap thong tin
{
again:
    cout<<"Nhap so cccd: ";
    cin>>hk[biendem].cccd;
//kiem tra trung thong tin
    if(search(hk,hk[biendem].cccd,biendem)!=-1)
    {
        cout<<"So cccd nay da duoc dang ky!\n";
        goto again;
    }
//nhap thong tin
    cout<<"Nhap ten hanh khach: ";
    cin.ignore();//code de nhap ten co cach
    getline(cin, hk[biendem].name);
    cout<<"Nhap gioi tinh cua hanh khach (F hoac M): ";
    cin>>hk[biendem].sex;
    cout<<"Nhap tuoi cua hanh khach: ";
     cin>>hk[biendem].age;
    cout<<"Nhap thang muon dang ky ve: ";
    cin>>hk[biendem].month;
    cout<<"Nhap hang ve muon dang ky(1: lien tuyen, 0: co dinh): ";
    cin>>hk[biendem].type;
    switch(hk[biendem].type)
    {
    case 1:
        cout<<"Cua ban het 140.000! \n";
        break;
    case 0:
        cout<<"Cua ban het 80.000! \n";
        break;
    default:
        cout<<"Sai gia tri! \n";
    }
    ++biendem;
}

void danhsach(struct hanhkhach hk[], int biendem) //Hien thi bang thong tin khach hang
{
    int i=0;
    cout<<left<<setw(14)<<"ID"<<setw(30)<<"Ho va Ten"<<setw(12)<<"Gioi tinh"<<setw(7)<<"Tuoi"<<setw(9)<<"Hang ve"<<setw(7)<<"Thang"<<"\n";
    cout<<"=============================================================================\n";
    while(i<=biendem)
    {
        if(hk[i].cccd!="")
        {
            cout<<left<<setw(14)<<hk[i].cccd<<setw(30)<<hk[i].name<<setw(12)
                <<hk[i].sex;
            cout<<setw(7)<<hk[i].age<<setw(9)<<hk[i].type<<setw(7)<<hk[i].month;
            cout<<"\n";
        }
        i=i+1;
    }
}
void xoa(struct hanhkhach hk[], int& biendem)//xoa khach hang
{
    string id;
    int index;
    if (biendem > 0)
    {
        cout<<"Nhap ID cua khach hang:";
        cin>>id;
        index = search(hk, id,biendem);

        if (index!=-1)
        {
            if (index == (biendem-1)) //xoa ban ghi cuoi cung
            {

                clean(hk, index);
                --biendem;
                cout<<"Khach hang da duoc xoa.\n";
            }

            else //xoa ban ghi dau tien hoac o giua
            {
                for (int i = index; i < biendem-1; i++)
                {
                    hk[i] = hk[i + 1];
                    clean(hk, biendem);
                    --biendem ;
                }

            }

        }
        else cout<<"Khach hang khong ton tai. Kiem tra ID va thu lai.\n";

    }
    else cout<<"Khong co khach hang nao bi xoa\n";
}
void capnhat(struct hanhkhach hk[],int biendem) //Chinh sua thong tin khach hang
{
    string id;
    int column_index;
    cout<<"Nhap ID cua hanh khach: ";
    cin>>id;
    cout<<"1. Ho va ten\n";
    cout<<"2. Gioi tinh\n";
    cout<<"3. Tuoi\n";
    cout<<"4. Hang ve\n";
    cout<<"Muc muon cap nhat : ";
    cin>>column_index;

    int index = search(hk, id,biendem);

    if (index != -1)
    {
        if (column_index == 1)
        {
            cout<<"Nhap ten hanh khach: ";

            cin>>hk[index].name;
        }

        else if (column_index == 2)
        {
            cout<<"Nhap gioi tinh (F hoac M): ";
            cin>>hk[index].sex;
        }
        else if (column_index == 3)
        {
            cout<<"Nhap tuoi: ";
            cin>>hk[index].age;
        }
        else if (column_index == 4)
        {
            cout<<"Nhap hang ve: ";
            cin>>hk[index].type;
        }

        /*else if (column_index == 7)
         {
          cout<<"Nhap thang muon gia han: ";
          cin>>hk[index].month;
         }*/
        else cout<<"Chuc nang khong ton tai!";
    }
    else cout<<"Khach hang khong ton tai! Kiem tra ID va thu lai.";


}
void find(struct hanhkhach hk[], int biendem)
{
  string id;
  cout<<"Nhap ID cua khach hang: ";
  cin>>id;

  int index=search(hk,id,biendem);
  if (index != -1)
  { //Hien thi thong tin khach hang
    cout<<left<<setw(14)<<hk[index].cccd<<setw(30)<<hk[index].name<<setw(12)
                <<hk[index].sex;
            cout<<setw(7)<<hk[index].age<<setw(9)<<hk[index].type<<setw(7)<<hk[index].month;
            cout<<"\n";
}
  else cout<<"Hanh khach khong ton tai.";

 }
int main()
{
    hanhkhach hk[80];
    int biendem=0;
    displaymenu();//hien thi menu
    int luachon;
    char confirm;
    do
    {
        cout<<"\nNhap lua chon cua ban (0-6): ";
        cin>>luachon;

        switch(luachon)
        {
        case 1:
            them(hk, biendem);
            break;
        case 2:
            xoa(hk, biendem);
            break;
        case 3:
            capnhat(hk, biendem);
            break;
        case 4:
            danhsach(hk, biendem);
            break;
        case 5:
            find(hk, biendem);
            break;
        case 6:
           // giahan(hk,biendem);
            break;
        case 0:
            return 0;
        default:
            cout<<"Khong hop le";

        }

        cout<<"Nhan y hoac Y de tiep tuc: ";
        cin>>confirm;
    }
    while(confirm=='y'||confirm=='Y');

    return 0;
}

