#include<bits/stdc++.h>
using namespace std;


// Product class representing any item of any Ecommerce
class Product {
public:
  string name;
  double price;
  Product(string name, double salary){
    this->name=name;
    this->price=salary;
  }
};

//Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
  vector<Product*> products;
  
  
public:
  void addProduct(Product* p){
    products.push_back(p);    
  }
  
  //get products
  const vector<Product*>& getProducts(){  //& for deep copy of products
    return products;
    //cout << products->name << " and " << products->price;
  }
  
};
  

class Calculate_Total {
public:

  static double calc_total(const vector<Product*>& p1){
    
    double total=0;
    for(auto c:p1){
      total+=c->price;
    }
    return total;
    
  }
  
};
  
  
class PrintInvoice {
public:
  static void print_Invoice(const vector<Product*>& p1){
    cout << "Shopping Cart Invoice:\n" ;
    for(auto p:p1){
      cout << p->name << "- $ " << p->price << endl;
    }
    
  }
};

class SaveDB {
public:
  static void saveToDatabase(const vector<Product*>& p1){
    
    cout << "Saving shopping cart to database..." << endl;
    for(auto db1:p1){
      cout << "Name is saving: " << db1->name <<endl;
      cout << "Price is saving: " << db1->price << endl;
    }
    cout << "Total is saving: " << Calculate_Total::calc_total(p1);
  }
};


int main() 
{
    ShoppingCart* cart1 = new ShoppingCart();
    //Calculate_Total c1;


    cart1->addProduct(new Product("Mango", 10));
    cart1->addProduct(new Product("Banana", 15));
    cart1->addProduct(new Product("Lichu", 13));
    
    PrintInvoice::print_Invoice(cart1->getProducts());
    cout << "Total: $" << Calculate_Total::calc_total(cart1->getProducts()) << endl;
    SaveDB::saveToDatabase(cart1->getProducts());
    return 0;
}