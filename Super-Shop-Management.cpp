#include <iostream>
#include <vector>
#include <string>

// Class for representing a product
class Product {
public:
    int id;
    std::string name;
    float price;
    int quantity;

    // Constructor to initialize product details (optional)
    Product(int id = 0, const std::string& name = "", float price = 0.0f, int quantity = 0)
        : id(id), name(name), price(price), quantity(quantity) {}

    // Add a new product (assuming a central inventory storage)
    void addProduct() {
        // Prompt user for product details (replace with actual data storage)
        std::cout << "Enter product ID: ";
        std::cin >> id;
        std::cout << "Enter product name: ";
        std::getline(std::cin >> std::ws, name); // Handle whitespace in name
        std::cout << "Enter product price: ";
        std::cin >> price;
        std::cout << "Enter product quantity: ";
        std::cin >> quantity;
    }

    // Remove a product (assuming a central inventory storage)
    void removeProduct() {
        // Prompt user for product ID and check if it exists (replace with actual data storage)
        std::cout << "Enter product ID to remove: ";
        int removeID;
        std::cin >> removeID;
        if (id == removeID) {
            quantity = 0; // Simulate removal by setting quantity to 0
            std::cout << "Product removed successfully." << std::endl;
        } else {
            std::cout << "Product with ID " << removeID << " not found." << std::endl;
        }
    }

    // Update product details
    void updateProduct() {
        // Prompt user for new details for the current product
        std::cout << "Update product details for ID " << id << std::endl;
        std::cout << "Enter new name (leave blank to keep current): ";
        std::string newName;
        std::getline(std::cin >> std::ws, newName);
        if (!newName.empty()) {
            name = newName;
        }
        std::cout << "Enter new price (leave blank to keep current): ";
        float newPrice;
        std::cin >> newPrice;
        if (newPrice > 0.0f) {
            price = newPrice;
        }
        std::cout << "Enter new quantity (leave blank to keep current): ";
        int newQuantity;
        std::cin >> newQuantity;
        if (newQuantity >= 0) {
            quantity = newQuantity;
        }
        std::cout << "Product updated successfully." << std::endl;
    }

    // Display product information
    void displayProductDetails() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
    }
};


class ShoppingCart {
public:
    std::vector<Product*> items; // Vector to store product pointers
    float totalCost;

    // Add a product to the cart
    void addItem(Product* product, int quantity) {
        if (quantity > 0) {
            items.push_back(product); // Add product pointer to the cart
            totalCost += product->price * quantity; // Update total cost
            std::cout << quantity << " of " << product->name << " added to cart." << std::endl;
        } else {
            std::cout << "Invalid quantity. Please enter a positive value." << std::endl;
        }
    }

    // Remove a product from the cart
    void removeItem(Product* product) {
        bool removed = false;
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == product) {
                items.erase(it); // Remove product pointer from the cart
                totalCost -= product->price; // Update total cost
                removed = true;
                std::cout << product->name << " removed from cart." << std::endl;
                break;
            }
        }
        if (!removed) {
            std::cout << product->name << " not found in cart." << std::endl;
        }
    }

    // Update the quantity of an existing product in the cart
    void updateItemQuantity(Product* product, int quantity) {
        if (quantity > 0) {
            bool found = false;
            for (auto it = items.begin(); it != items.end(); ++it) {
                if (*it == product) {
                    int oldQuantity = product->quantity; // Track old quantity for cost update
                    totalCost -= oldQuantity * product->price; // Remove old cost
                    product->quantity = quantity; // Update product quantity
                    totalCost += quantity * product->price; // Update total cost with new quantity
                    found = true;
                    std::cout << product->name << " quantity updated to " << quantity << "." << std::endl;
                    break;
                }
            }
            if (!found) {
                std::cout << product->name << " not found in cart." << std::endl;
            }
        } else {
            std::cout << "Invalid quantity. Please enter a positive value." << std::endl;
        }
    }

    // Calculate the total cost of all items in the cart based on price and quantity
    float calculateTotalCost() {
        return totalCost;
    }

    // Display the contents of the cart, including product details and total cost
    void displayCart() const {
        if (items.empty()) {
            std::cout << "Cart is empty." << std::endl;
        } else {
            std::cout << "Cart Items:" << std::endl;
            for (const Product* product : items) {
                product->displayProductDetails(); // Use product's display function
            }
            std::cout << "Total Cost: $" << totalCost << std::endl;
        }
    }
};




class Billing {
public:
    ShoppingCart* cart; // Pointer to a ShoppingCart object

    // Apply a discount to the total bill amount (placeholder for different discount types)
    void applyDiscount(float discount) {
        if (discount > 0.0f && discount <= 1.0f) { // Validate discount percentage
            float discountAmount = discount * cart->calculateTotalCost();
            cart->totalCost -= discountAmount;
            std::cout << "Discount applied: $" << discountAmount << std::endl;
        } else {
            std::cout << "Invalid discount value. Please enter a value between 0 and 1." << std::endl;
        }
    }

    // Calculate the final bill amount after applying discounts (if any)
    float calculateFinalBill() {
        return cart->calculateTotalCost(); // Placeholder for final bill calculation (can include tax, etc.)
    }

    // Simulate the payment process (placeholder)
    void simulatePayment() {
        std::cout << "** Simulating Payment **" << std::endl;
        std::cout << "Please enter payment method (e.g., cash, credit card): ";
        std::string paymentMethod;
        std::getline(std::cin >> std::ws, paymentMethod);
        std::cout << "Payment received using " << paymentMethod << std::endl;
        // ... (Optional) Add logic for payment confirmation or error handling
    }
};


// Main function to drive the program
int main() {
    return 0;
}
