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



//making the SaveDB an abstract for Open for extension and closed for modifications
class SaveDB {

public:

  virtual void saveToDatabase() = 0;

  
};

//now we will inherit the abstract, we will not modify that, just will inherit/morph and extend
class SaveToSQL : public SaveDB {

private:
  ShoppingCart* cart;

public:

   SaveToSQL(ShoppingCart * carts){
    this->cart = carts;

   }

   void saveToDatabase(){
    cout << "Saving shopping to SQL Databases" << endl;
    for(auto i:cart->getProducts()){
        cout << "Saving Product " << i->name << " In SQL Databases" << endl;
        cout << "Saving Product Price " << i->price << " In SQL Databases" << endl;
    }cout << endl;


   }


};

//again OCP
class SaveToMongoDB : public SaveDB {

private:
  ShoppingCart* cart;

public:

   SaveToMongoDB(ShoppingCart * carts){
    this->cart = carts;

   }

   void saveToDatabase(){
    cout << "Saving shopping to MongoDB Databases" << endl;
    for(auto i:cart->getProducts()){
        cout << "Saving Product " << i->name << " In MongoDB Databases" << endl;
        cout << "Saving Product Price " << i->price << " In MongoDB Databases" << endl;
    }cout << endl;


   }


};

//Again OCP
class SaveToFiles : public SaveDB {

private:
  ShoppingCart* cart;

public:

   SaveToFiles(ShoppingCart * carts){
    this->cart = carts;

   }

   void saveToDatabase(){
    cout << "Saving shopping to Local Databases" << endl;
    for(auto i:cart->getProducts()){
        cout << "Saving Product " << i->name << " In Local" << endl;
        cout << "Saving Product Price " << i->price << " In Local" << endl;
    }cout << endl;


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
    // SaveToSQL s1(cart1);
    // s1.saveToDatabase();
    // cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    // SaveToMongoDB s2(cart1);
    // s2.saveToDatabase();

    // cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    // SaveToFiles s3(cart1);
    // s3.saveToDatabase();
    
    SaveDB* db = new SaveToSQL(cart1);
    SaveDB* mongo = new SaveToMongoDB(cart1);
    SaveDB* files = new SaveToFiles(cart1);
    db->saveToDatabase();    
    cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
    
    mongo->saveToDatabase();    
    cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;
  
    files->saveToDatabase();    
    cout << "-----------------------------------------------------------------------------------------------------------------------"<<endl;

    
    return 0;
}