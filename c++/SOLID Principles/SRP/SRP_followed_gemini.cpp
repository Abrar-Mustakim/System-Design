#include <iostream>
#include <vector>
#include <string>
#include <memory> // The holy grail for Modern C++ memory management

using namespace std;

// 1. Core Data Structure
class Product {
public:
    string name;
    double price;

    // Use member initializer list for better performance
    Product(string name, double price) : name(name), price(price) {}
};

// 2. The Domain Model (High Cohesion)
// Responsible ONLY for managing its own items and calculating its own state.
class ShoppingCart {
private:
    // Modern C++: unique_ptr guarantees memory is freed when the cart is destroyed.
    vector<unique_ptr<Product>> products;

public:
    // Use std::move to transfer ownership of the pointer into the cart
    void addProduct(unique_ptr<Product> p) {
        products.push_back(std::move(p));
    }

    // Return by const reference. The outside world can look at the products, but cannot modify the array.
    const vector<unique_ptr<Product>>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        // Iterate by const reference so we don't accidentally copy or modify pointers
        for (const auto& p : products) {
            total += p->price;
        }
        return total;
    }
};

// 3. The Interfaces (Abstract Classes) - The Secret Weapon for Decoupling
// We define WHAT a printer or database should do, but not HOW it does it.
class IInvoicePrinter {
public:
    virtual ~IInvoicePrinter() = default; // Always need a virtual destructor in abstract classes
    
    // Notice: It asks for raw data, NOT a ShoppingCart object!
    virtual void print(const vector<unique_ptr<Product>>& products, double total) const = 0;
};

class IStorage {
public:
    virtual ~IStorage() = default;
    virtual void save(const vector<unique_ptr<Product>>& products, double total) const = 0;
};

// 4. Concrete Implementations
// Now we write the actual logic, inheriting from the interfaces.
class ConsolePrinter : public IInvoicePrinter {
public:
    // override keyword tells the compiler we are strictly implementing the interface
    void print(const vector<unique_ptr<Product>>& products, double total) const override {
        cout << "\n=== Shopping Cart Invoice ===\n";
        for (const auto& p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << total << "\n=============================\n";
    }
};

class DatabaseStorage : public IStorage {
public:
    void save(const vector<unique_ptr<Product>>& products, double total) const override {
        cout << "Saving " << products.size() << " items to database. Total value: Rs " << total << endl;
    }
};

// 5. Execution
int main() {
    // Look at this. No 'new' keyword. No raw pointers. 
    // This is automatically allocated and destroyed. Zero leaks.
    ShoppingCart cart;

    // std::make_unique creates the object and wraps it in a smart pointer safely.
    cart.addProduct(make_unique<Product>("Laptop", 50000));
    cart.addProduct(make_unique<Product>("Mouse", 2000));

    // Decoupled Execution: We pass exactly what the services need to do their job, nothing more.
    ConsolePrinter printer;
    printer.print(cart.getProducts(), cart.calculateTotal());

    DatabaseStorage db;
    db.save(cart.getProducts(), cart.calculateTotal());

    return 0; // Program ends, unique_ptrs automatically clean up all memory. No delete needed.
}