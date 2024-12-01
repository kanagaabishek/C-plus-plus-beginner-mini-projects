#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <limits> // Required for std::numeric_limits

using namespace std;

// Product Class
class Product {
public:
    Product(const string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

private:
    string name;
    double price;
    int quantity;
};

// Store Class
class Store {
public:
    void addProduct(const string& name, double price, int quantity) {
        products.push_back(make_unique<Product>(name, price, quantity));
        cout << "Added product: " << name << " at price: " << price << " with quantity: " << quantity << endl;
    }

    void displayProducts() const {
        cout << "Products:" << endl;
        for (const auto& product : products) {
            cout << "Product: " << product->getName() << ", Price: " << product->getPrice() 
                 << ", Quantity: " << product->getQuantity() << endl;
        }
    }

    void buyProduct(const string& name, int quantity) {
        auto it = find_if(products.begin(), products.end(),
            [&name](const unique_ptr<Product>& product) {
                return product->getName() == name;
            });
        if (it != products.end()) {
            if ((*it)->getQuantity() >= quantity) {
                (*it)->setQuantity((*it)->getQuantity() - quantity);
                cout << "Bought " << quantity << " of " << name 
                     << " for price: " << (*it)->getPrice() * quantity << endl;
            } else {
                cout << "Insufficient quantity for product: " << name << endl;
            }
        } else {
            cout << "Product not found: " << name << endl;
        }
    }

    void sellProduct(const string& name, int quantity) {
        auto it = find_if(products.begin(), products.end(),
            [&name](const unique_ptr<Product>& product) {
                return product->getName() == name;
            });
        if (it != products.end()) {
            (*it)->setQuantity((*it)->getQuantity() + quantity);
            cout << "Sold " << quantity << " of " << name 
                 << " for price: " << (*it)->getPrice() * quantity << endl;
        } else {
            cout << "Product not found: " << name << endl;
        }
    }

private:
    vector<unique_ptr<Product>> products;
};

// Main Function
int main() {
    Store store;
    int choice;
    string name;
    double price;
    int quantity;

    while (true) {
        cout << "\n1. Add Product\n2. Display Products\n3. Buy Product\n4. Sell Product\n5. Exit\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter product price: ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            store.addProduct(name, price, quantity);
            break;
        case 2:
            store.displayProducts();
            break;
        case 3:
            cout << "Enter product name to buy: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter quantity to buy: ";
            cin >> quantity;
            store.buyProduct(name, quantity);
            break;
        case 4:
            cout << "Enter product name to sell: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter quantity to sell: ";
            cin >> quantity;
            store.sellProduct(name, quantity);
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please choose between 1 and 5." << endl;
        }
    }
}


