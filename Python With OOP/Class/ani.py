class Product:
    def __init__(self, title, price):
        self.title = title
        self.price = price

    def display_info(self):
        print(f"Title: {self.title}")
        print(f"Price: ${self.price:.2f}")


class Book(Product):
    def __init__(self, title, author, price):
        super().__init__(title, price)  # Inheritance: Book class inherits from Product class
        self.author = author

    def display_info(self):
        print(f"Title: {self.title}")
        print(f"Author: {self.author}")
        print(f"Price: ${self.price:.2f}")


class Customer:
    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
        self.orders = []

    def display_info(self):
        print(f"Name: {self.name}")
        print(f"Email: {self.email}")
        print(f"Address: {self.address}")

    def place_order(self, order):
        self.orders.append(order)
        print("Order placed successfully.")


class Order:
    def __init__(self, order_id, items):
        self.order_id = order_id
        self.items = items

    def display_info(self):
        print(f"Order ID: {self.order_id}")
        print("Items:")
        for item in self.items:
            item.display_info()


class OnlineBookstore:
    def __init__(self):
        self.catalog = []

    def add_product_to_catalog(self, product):
        self.catalog.append(product)

    def remove_product_from_catalog(self, product_title):
        for product in self.catalog:
            if product.title.lower() == product_title.lower():
                self.catalog.remove(product)
                print(f"Product '{product.title}' removed from catalog.")
                return
        print("Product not found in catalog.")

    def display_catalog(self):
        print("Catalog:")
        for index, product in enumerate(self.catalog, start=1):
            print(f"{index}.")
            product.display_info()


class ShoppingCart:
    def __init__(self):
        self.items = []

    def add_to_cart(self, product):
        self.items.append(product)

    def remove_from_cart(self, product):
        if product in self.items:
            self.items.remove(product)
        else:
            print("Product not found in cart.")

    def checkout(self):
        total_price = sum(item.price for item in self.items)
        print(f"Total Price: ${total_price:.2f}")


# Function to get user input for a product
def get_product_input():
    title = input("Enter the title of the product: ")
    price = float(input("Enter the price of the product: "))
    return Product(title, price)


# Function to get user input for a book
def get_book_input():
    title = input("Enter the title of the book: ")
    author = input("Enter the author of the book: ")
    price = float(input("Enter the price of the book: "))
    return Book(title, author, price)


# Function to get user input for a customer
def get_customer_input():
    name = input("Enter customer name: ")
    email = input("Enter customer email: ")
    address = input("Enter customer address: ")
    return Customer(name, email, address)


# Example usage:
store = OnlineBookstore()

# Adding initial products to the catalog
initial_products = [
    Book("The Great Gatsby", "F. Scott Fitzgerald", 12.99),
    Book("To Kill a Mockingbird", "Harper Lee", 10.99),
    Product("1984", 8.99)
]

for product in initial_products:
    store.add_product_to_catalog(product)

cart = ShoppingCart()

while True:
    print("\n1. Add a product to catalog")
    print("2. Remove a product from catalog")
    print("3. Display catalog")
    print("4. Add a product to cart")
    print("5. Remove a product from cart")
    print("6. Checkout")
    print("7. Place Order")
    print("8. Display Customer Info")
    print("9. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        product = get_product_input()
        store.add_product_to_catalog(product)
        print("Product added to catalog.")

    elif choice == "2":
        title = input("Enter the title of the product to remove: ")
        store.remove_product_from_catalog(title)

    elif choice == "3":
        store.display_catalog()

    elif choice == "4":
        store.display_catalog()
        product_title = input("Enter the title of the product to add to cart: ")
        product = next((p for p in store.catalog if p.title.lower() == product_title.lower()), None)
        if product:
            cart.add_to_cart(product)
            print("Product added to cart.")
        else:
            print("Product not found in catalog.")

    elif choice == "5":
        if cart.items:
            print("Cart items:")
            for i, item in enumerate(cart.items):
                print(f"{i + 1}. {item.title} - ${item.price:.2f}")
            idx = int(input("Enter the index of the product to remove: ")) - 1
            if 0 <= idx < len(cart.items):
                cart.remove_from_cart(cart.items[idx])
            else:
                print("Invalid index.")
        else:
            print("Cart is empty.")

    elif choice == "6":
        cart.checkout()

    elif choice == "7":
        if cart.items:
            customer = get_customer_input()
            order = Order(len(customer.orders) + 1, cart.items)
            customer.place_order(order)
        else:
            print("Cart is empty.")

    elif choice == "8":
        customer.display_info()

    elif choice == "9":
        break

    else:
        print("Invalid choice. Please enter a number from 1 to 9.")