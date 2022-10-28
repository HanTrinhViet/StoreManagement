/* DANH MUC MAT HANG */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item { // Lớp danh mục mặt hàng
private:
  friend ostream& operator << (ostream& out, const Item& s);
  friend istream& operator >> (istream& in, Item& s);
  string productId;   // Mã hàng
  string productName; // Tên hàng
  string productManu; // Nhà sản xuất
public:
  Item(string productId = "PT???", string productName = "???",
       string productManu = "???")
  {
    setProductId(productId);
    setProductName(productName);
    setProductManu(productManu);
  }

  void setProductId(string productId) { this->productId = productId; }
  void setProductName(string productName) { this->productName = productName; }
  void setProductManu(string productManu) { this->productManu = productManu; }

  string getProductId() const { return productId; }
  string getProductName() const { return productName; }
  string getProductManu() const { return productManu; }

  
};

ostream& operator << (ostream& out, const Item& s) {
  out << left << setw(30) << s.productId
               << setw(60) << s.productName
               << setw(30) << s.productManu 
               << endl; 
  return out;
}

istream& operator >> (istream& in, Item& s) {
  cout << endl;
  cout << "Nhap ma san pham (ITEM???): ";
  getline(in, s.productId);
  cout << "Nhap ten san pham: ";
  getline(in, s.productName);
  cout << "Nhap nha san xuat: ";
  getline(in, s.productManu);
  cout << endl;
  return in;
}
