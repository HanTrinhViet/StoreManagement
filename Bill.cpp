/* HOA DON */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Bill { // Lớp hóa đơn mua bán hàng
private:
  friend ostream& operator << (ostream& out, const Bill& s);
  friend istream& operator >> (istream& in, Bill& s);
  string billId;    // Mã hóa đơn
  string productId; // Mã hàng
  string billType;  // Loại hóa đơn (Bán hoặc Mua) (Buy or Sell)
  string billAmount;   // Số lượng
  string billDate;  // Ngày mua và bán
  string billPrice;   // Giá mua và bán
public:
  Bill(string billId = "???", string productId = "PT???",
       string billType = "???", string billAmount = "0",
       string billDate = "??/??/??", string billPrice = "0")
  {
    setBillId(billId);
    setProductId(productId);
    setBillType(billType);
    setBillAmount(billAmount);
    setBillDate(billDate);
    setBillPrice(billPrice);
  }

  void setBillId(string billId) { this->billId = billId;}
  void setProductId(string productId) { this->productId = productId; }
  void setBillType(string billType) { this->billType = billType; }
  void setBillAmount(string billAmount) { this->billAmount = billAmount; }
  void setBillDate(string billDate) { this->billDate = billDate; }
  void setBillPrice(string billPrice) { this->billPrice = billPrice; }

  string getBillId() const  { return billId; }
  string getProductId() const  { return productId; }
  string getBillType() const  { return billType; }
  string getBillAmount() const  { return billAmount; }
  string getBillDate() const  { return billDate; }
  string getBillPrice() const  { return billPrice; }

};

ostream& operator << (ostream& out, const Bill& s) {
  out << left << setw(30) << s.billId
              << setw(30) << s.productId
              << setw(30) << s.billType
              << setw(30) << s.billAmount
              << setw(30) << s.billDate
              << setw(30) << s.billPrice
              << endl;
  return out;
}

istream& operator >> (istream& in, Bill& s) {
  cout << endl;
  cout << "Nhap ma hoa don (BILL???): ";
  getline(in, s.billId);
  cout << "Nhap ma san pham: ";
  getline(in, s.productId);
  cout << "Nhap loai hoa don (MUA hay BAN): ";
  getline(in, s.billType);
  cout << "Nhap so luong mua/ban: ";
  getline(in, s.billAmount);
  cout << "Nhap ngay mua/ban: ";
  getline(in, s.billDate);
  cout << "Nhap gia mua/ban: ";
  getline(in, s.billPrice);
  return in;
}

