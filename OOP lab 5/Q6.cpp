#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MenuItem {
    string name;
    string type;//drink or food
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(const string& shopName, const vector<MenuItem>& menuItems) 
        : name(shopName), menu(menuItems) {}

    string addOrder(const string& itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0.0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menu.empty()) return "Menu is empty!";
        
        const MenuItem* cheapest = &menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"soda", "drink", 3.5},
        {"limca", "drink", 2.0},
        {"lasee", "drink", 4.0},
        {"biryani", "food", 2.5},
        {"karahi", "food", 1.5},
        {"korma", "food", 2.0}
    };

    CoffeeShop myShop("HYD Haven", menu);

    cout << myShop.addOrder("soda") << endl;
    cout << myShop.addOrder("korma") << endl;
    cout << myShop.addOrder("Tea") << endl; 

    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;

    cout << "\nCurrent orders:\n";
    vector<string> currentOrders = myShop.listOrders();
    for (const auto& order : currentOrders) {
        cout << order << endl;
    }

    cout << "\nTotal amount due: $" << myShop.dueAmount() << endl;

    cout << "\nCheapest item: " << myShop.cheapestItem() << endl;

    cout << "\nDrinks available:\n";
    vector<string> drinks = myShop.drinksOnly();
    for (const auto& drink : drinks) {
        cout << drink << endl;
    }

    cout << "\nFood available:\n";
    vector<string> foods = myShop.foodOnly();
    for (const auto& food : foods) {
        cout << food << endl;
    }

    return 0;
}
