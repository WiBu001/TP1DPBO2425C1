"""
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
"""

from Laptop import Laptop
import os

# Function to clear the terminal screen
def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

# Function to display menu options and return user choice
def menu():
    print("\nMenu:")
    print("[1]. Insert New Laptop")
    print("[2]. Update Laptop Info")
    print("[3]. Delete Laptop")
    print("[4]. Find Laptop")
    print("[5]. Display All Laptops")
    print("[6]. Exit")
    return input("Enter your choice: ")

# Function to ensure input is an integer
# If allow_empty=True, user can skip input by pressing Enter
def input_int(prompt, allow_empty=False):
    while True:
        value = input(prompt)
        if allow_empty and value.strip() == "":
            return None
        try:
            return int(value)
        except ValueError:
            print("Input must be a number.")

# Main program function
def main():
    # Initial list of laptops
    laptops = [
        Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2),
        Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1),
        Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3),
    ]

    # Loop to keep showing the menu until user exits
    while True:
        choice = menu()

        # Option 1: Insert new laptop
        if choice == "1":
            clear_screen()
            print("Insert New Laptop")

            temp_id = input_int("Laptop ID: ")
            # Prevent duplicate ID
            if any(l.get_id() == temp_id for l in laptops):
                print("ID already exists.")
                continue

            # Collect new laptop data
            temp_name = input("Laptop Name: ")
            temp_brand = input("Laptop Brand: ")
            temp_color = input("Laptop Color: ")
            temp_price = input_int("Laptop Price: ")
            temp_warranty = input_int("Laptop Warranty: ")

            # Add new laptop to the list
            laptops.append(Laptop(temp_id, temp_name, temp_brand, temp_color, temp_price, temp_warranty))

        # Option 2: Update existing laptop info
        elif choice == "2":
            clear_screen()
            print("Update Laptop Info")

            temp_id = input_int("Enter Laptop ID: ")
            laptop = next((l for l in laptops if l.get_id() == temp_id), None)
            if laptop is None:
                print("Laptop not found")
                continue

            print("\nLeave empty if you don’t want to change.")

            # Update each field if user provides new value
            new_name = input(f"Old Name: {laptop.get_name()} | New Name: ")
            if new_name:
                laptop.set_name(new_name)

            new_brand = input(f"Old Brand: {laptop.get_brand()} | New Brand: ")
            if new_brand:
                laptop.set_brand(new_brand)

            new_color = input(f"Old Color: {laptop.get_color()} | New Color: ")
            if new_color:
                laptop.set_color(new_color)

            new_price = input_int(f"Old Price: Rp {laptop.get_price()} | New Price: ", allow_empty=True)
            if new_price is not None:
                laptop.set_price(new_price)

            new_warranty = input_int(f"Old Warranty: {laptop.get_warranty()} | New Warranty: ", allow_empty=True)
            if new_warranty is not None:
                laptop.set_warranty(new_warranty)

            print("Laptop Info Updated:")
            laptop.display()

        # Option 3: Delete laptop
        elif choice == "3":
            clear_screen()
            print("Delete Laptop")

            temp_id = input_int("Enter Laptop ID: ")
            laptop = next((l for l in laptops if l.get_id() == temp_id), None)
            if laptop:
                laptop.display()
                confirm = input("Are you sure? (Y/N): ")
                if confirm.lower() == "y":
                    laptops.remove(laptop)
                    print("Laptop deleted.")
                else:
                    print("Cancelled.")
            else:
                print("Laptop not found")

        # Option 4: Find laptop by ID
        elif choice == "4":
            clear_screen()
            print("Find Laptop")

            temp_id = input_int("Enter Laptop ID: ")
            laptop = next((l for l in laptops if l.get_id() == temp_id), None)
            if laptop:
                print("Here’s your laptop info:")
                laptop.display()
            else:
                print("Laptop not found")

        # Option 5: Display all laptops
        elif choice == "5":
            clear_screen()
            print("All Laptops:\n")
            if not laptops:
                print("No laptops available.")
            for l in laptops:
                l.display()

        # Option 6: Exit program
        elif choice == "6":
            print("Exiting program.")
            break

        # Invalid choice handling
        else:
            print("Invalid choice. Please try again.")

# Run the program
if __name__ == "__main__":
    main()
