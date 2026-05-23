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
  const vector<Product*>& getProducts(){  //& for returning the exact array by its reference
    return products;
    //cout << products->name << " and " << products->price;
  }
  
};
  

class Calculate_Total {

private:
  ShoppingCart* cart;

public:

  Calculate_Total(ShoppingCart* cart){
    this->cart = cart;
  }

  double calc_total(){
    

    double total=0;
    for(auto c:cart->getProducts()){
      total+=c->price;
    }
    return total;
    
  }
  
};
  
  
class PrintInvoice {
private:
  ShoppingCart* cart;

public:

  PrintInvoice(ShoppingCart* cart){
    this->cart = cart;
  }

  void print_Invoice(){
    cout << "Shopping Cart Invoice:\n" ;
    for(auto p:cart->getProducts()){
      cout << p->name << "- $ " << p->price << endl;
    }
    
  }
};

class SaveDB {
private:
  ShoppingCart* cart;

public:

  SaveDB(ShoppingCart* cart){
    this->cart = cart;
  }
  void saveToDatabase(){
    
    cout << "Saving shopping cart to database..." << endl;
    for(auto db1:cart->getProducts()){
      cout << "Name is saving: " << db1->name <<endl;
      cout << "Price is saving: " << db1->price << endl;
    }
    Calculate_Total c(cart);
    cout << "Total is saving: $" << c.calc_total() << endl;
    //cout << "Total is saving: " << Calculate_Total::calc_total(p1);
  }
};


int main() 
{
    ShoppingCart* cart1 = new ShoppingCart();
    


    cart1->addProduct(new Product("Mango", 10));
    cart1->addProduct(new Product("Banana", 15));
    cart1->addProduct(new Product("Lichu", 13));
    
    PrintInvoice p1(cart1);
    p1.print_Invoice();
    Calculate_Total c1(cart1);
    cout << "Total: $" << c1.calc_total() << endl;
    SaveDB s1(cart1);
    s1.saveToDatabase();
    return 0;
}