#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.cpp"
#include "Bill.cpp"
using namespace std;

void menu();
template <class T>
void deleteElement(vector<T> &list);                  // xóa các phần tử trước khi đọc file , vì nếu đọc file hai lần sẽ bị gấp đôi
void readItemFromFile(vector<Item> &itemList);        // option 1
void writeItemToFile(vector<Item> &itemList);         // option 2
void readBillFromFile(vector<Bill> &billList);        // option 3
void writeBillToFile(vector<Bill> &billList);         // option 4
void addItemAndAddToFile(vector<Item> &itemList);     // option 5
void addBillAndAddtoFIle(vector<Bill> &billList);     // option 6
void showItemOnConsole(const vector<Item> &itemList); // option 7
void showBillOnConsole(const vector<Bill> &billList); // option 8
void inventoryStatistic();                            // option 9

int main()
{
  menu();
  return 0;
}

template <class T>
void deleteElement(vector<T> &list)
{
  while (!list.empty())
  {
    list.pop_back();
  }
}

void menu()
{
  vector<Item> itemList;
  vector<Bill> billList;
  int choice = 0;
  do
  {
    cout << "\t\t============================MENU============================\n";
    cout << "1.  DOC THONG TIN CAC DANH SACH MAT HANG.\n";
    cout << "2.  GHI THONG TIN CAC DANH SACH MAT HANG RA FILE (DUOI DANG COT VA BANG).\n";
    cout << "3.  DOC THONG TIN CAC HOA DON.\n";
    cout << "4.  GHI THONG TIN CAC HOA DON RA FILE. (DUOI DANG COT VA BANG).\n";
    cout << "5.  THEM MOI MOT MAT HANG.\n";
    cout << "6.  THEM MOI MOT HOA DON.\n";
    cout << "7.  HIEN THI TOAN BO DANH SACH MAT HANG HIEN CO.\n";
    cout << "8.  HIEN THI TOAN BO DANH SACH HOA DON HIEN CO.\n";
    cout << "9.  THONG KE SO HANG TON TRONG KHO.\n";
    cout << "0.  THOAT CHUONG TRINH.\n";
    cout << "LUA CHON CUA BAN: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 0:
    {
      cout << "\nCam on ban da su dung. Xin chao va hen gap lai.\n";
      break;
    }

    case 1:
    {
      deleteElement(itemList);
      readItemFromFile(itemList);
      cout << "\nDOC THANH CONG\n";
      break;
    }

    case 2:
    {
      writeItemToFile(itemList);
      cout << "\nGHI VAO FILE THANH CONG\n";
      break;
    }

    case 3:
    {
      deleteElement(billList);
      readBillFromFile(billList);
      cout << "\nDOC THANH CONG\n";
      break;
    }

    case 4:
    {
      writeBillToFile(billList);
      cout << "\nGHI VAO FILE THANH CONG\n";
      break;
    }

    case 5:
    {
      addItemAndAddToFile(itemList);
      cout << "\n NHAP THANH CONG \n";
      break;
    }

    case 6:
    {
      addBillAndAddtoFIle(billList);
      cout << "\n NHAP THANH CONG \n";
      break;
    }

    case 7:
    {
      showItemOnConsole(itemList);
      break;
    }

    case 8:
    {
      showBillOnConsole(billList);
      break;
    }

    case 9:
    {
      inventoryStatistic();
      break;
    }

    default:
    {
      cout << "\nVui long nhap tu 0 -> 10\n"; // fix after
      break;
    }
    }
  } while (choice != 0);
}

void readItemFromFile(vector<Item> &itemList)
{
  ifstream ifs("ITEM_IN.txt");
  if (!ifs.is_open())
  {
    cout << "Khong mo duoc file ITEM_IN.txt. Xin vui long thu lai.\n";
  }
  else
  {
    while (true)
    {
      if (ifs.eof())
      {
        break;
      }
      string productId;
      string productName;
      string productManu;
      getline(ifs, productId);
      getline(ifs, productName);
      getline(ifs, productManu);
      Item item(productId, productName, productManu);
      itemList.push_back(item);
    }
    ifs.close();
  }
}

void writeItemToFile(vector<Item> &itemList)
{
  ofstream ofs("ITEM_OUT.txt");
  ofs << left << setw(30) << "MA SAN PHAM"
      << setw(60) << "TEN SAN PHAM"
      << setw(30) << "NHA SAN XUAT"
      << endl;
  ofs << "========================================================================================================================\n";
  for (int i = 0; i < (int)itemList.size(); i++)
  {
    ofs << itemList[i];
  }
  ofs.close();
}

void readBillFromFile(vector<Bill> &billList)
{
  ifstream ifs("BILL_IN.txt");
  if (!ifs.is_open())
  {
    cout << "Khong mo duoc file BILL_IN.txt. Xin vui long thu lai.\n";
  }
  else
  {
    while (true)
    {
      if (ifs.eof())
      {
        break;
      }
      string billId;
      string productId;
      string billType;
      string billAmount;
      string billDate;
      string billPrice;
      getline(ifs, billId);
      getline(ifs, productId);
      getline(ifs, billType);
      getline(ifs, billAmount);
      getline(ifs, billDate);
      getline(ifs, billPrice);
      Bill bill(billId, productId, billType, billAmount, billDate, billPrice);
      billList.push_back(bill);
    }
    ifs.close();
  }
}

void writeBillToFile(vector<Bill> &billList)
{
  ofstream ofs("BILL_OUT.txt");
  ofs << left << setw(30) << "MA HOA DON"
      << setw(30) << "MA SAN PHAM"
      << setw(30) << "LOAI HOA DON"
      << setw(30) << "SO LUONG MUA/BAN"
      << setw(30) << "NGAY MUA/BAN"
      << setw(30) << "GIA MUA/BAN"
      << endl;
  ofs << "=======================================================================================================================================================================\n";
  for (int i = 0; i < (int)billList.size(); i++)
  {
    ofs << billList[i];
  }
  ofs.close();
}

void addItemAndAddToFile(vector<Item> &itemList)
{
  Item s;
  cin >> s;
  itemList.push_back(s);
  ofstream ofs("ITEM_IN.txt", ios::app);
  ofs << s.getProductId() << endl;
  ofs << s.getProductName() << endl;
  ofs << s.getProductManu() << endl;
  ofs.close();
}

void addBillAndAddtoFIle(vector<Bill> &billList)
{
  Bill s;
  cin >> s;
  billList.push_back(s);
  ofstream ofs("BILL_IN.txt", ios::app);
  ofs << s.getBillId() << endl;
  ofs << s.getProductId() << endl;
  ofs << s.getBillType() << endl;
  ofs << s.getBillAmount() << endl;
  ofs << s.getBillDate() << endl;
  ofs << s.getBillPrice() << endl;
  ofs.close();
}

void showItemOnConsole(const vector<Item> &itemList)
{
  cout << "\n\n";
  cout << "\t\t===============================DANH SACH MAT HANG===============================\n\n";
  cout << left << setw(30) << "MA SAN PHAM"
       << setw(60) << "TEN SAN PHAM"
       << setw(30) << "NHA SAN XUAT"
       << endl;
  cout << "========================================================================================================================\n";
  for (int i = 0; i < (int)itemList.size(); i++)
  {
    cout << itemList[i];
  }
}

void showBillOnConsole(const vector<Bill> &billList)
{
  cout << "\n\n";
  cout << "\t\t===============================DANH SACH HOA DON===============================\n\n";
  cout << left << setw(30) << "MA HOA DON"
       << setw(30) << "MA SAN PHAM"
       << setw(30) << "LOAI HOA DON"
       << setw(30) << "SO LUONG MUA/BAN"
       << setw(30) << "NGAY MUA/BAN"
       << setw(30) << "GIA MUA/BAN"
       << endl;
  cout << "=======================================================================================================================================================================\n";
  for (int i = 0; i < (int)billList.size(); i++)
  {
    cout << billList[i];
  }
}

void inventoryStatistic() {
  ifstream ifs("INVENTORY_IN.txt");
  int inventorySize = 0;
  Item* inventoryList = new Item[100]; // vì dữ liệu giống thuộc tính của item nên em tận dụng lớp item luôn
  if (ifs) {
    while (!ifs.eof()) {
      string productId;
      string productName;
      string productManu;
      getline(ifs, productId);
      getline(ifs, productName);
      getline(ifs, productManu);
      Item s(productId, productName, productManu);
      inventoryList[inventorySize++] = s;
    }
    ifs.close();
  } else {
    cout << "KHONG MO DUOC FILE HANG TON. VUI LONG THU LAI!\n";
  }

  cout << "\n\t\t================================DANH SACH SO HANG TON================================\n\n";
  cout << left << setw(30) << "MA SAN PHAM"
               << setw(60) << "TEN SAN PHAM"
               << setw(30) << "NHA SAN XUAT"
               << endl;
  cout << "========================================================================================================================\n"; 
  for (int i = 0; i < inventorySize; i++) {
    cout << inventoryList[i];
  }
  delete[] inventoryList;
}