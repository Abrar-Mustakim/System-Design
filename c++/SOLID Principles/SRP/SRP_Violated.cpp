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
  
  // 1.Calculates total price in cart
  double calculateTotal(){
    double total=0;
    for(auto p: products){
      total+=p->price;
    }
    return total;
  }
  
  //2.Violating SRP-Prints invoice(SHould be in a sepearate class)
  void printInvoice(){
    cout << "Shopping Cart Invoice:\n" ;
    for(auto p:products){
      cout << p->name << "- $ " << p->price << endl;
    }
    cout << "Total: $" << calculateTotal() << endl;
  }
  
  //3. Violating SRP- Saves to DB(should be in a sepearate class)
  void saveToDatabase(){
    cout << "Saving shopping cart to database..." << endl;
  }
  
  
};

int main() 
{
    ShoppingCart* cart1 = new ShoppingCart();
    cart1->addProduct(new Product("Mango", 10));
    cart1->addProduct(new Product("Banana", 15));
    cart1->addProduct(new Product("Lichu", 13));
    
    cart1->printInvoice();
    cart1->saveToDatabase();
    return 0;
}