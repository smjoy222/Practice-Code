def calculate_discounted_price(original_price, discount_percentage):
    if discount_percentage < 0 or discount_percentage > 100:
        return "Invalid discount percentage"
    
    discounted_price = original_price - (original_price * discount_percentage / 100)
    return discounted_price

# Test cases
test_input = [
    {"original_price": 100, "discount_percentage": 10},
    {"original_price": 50, "discount_percentage": 25},
    {"original_price": 200, "discount_percentage": 50},
]

for input_data in test_input:
    original_price = input_data["original_price"]
    discount_percentage = input_data["discount_percentage"]
    discounted_price = calculate_discounted_price(original_price, discount_percentage)
    print(f"Original Price: {original_price}, Discount Percentage: {discount_percentage}%, Discounted Price: {discounted_price}")
