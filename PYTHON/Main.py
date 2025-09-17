# main.py
from Laptop import Laptop
import os


def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")


def menu():
    print("\nMenu:")
    print("[1]. Insert New Laptop")
    print("[2]. Update Laptop Info")
    print("[3]. Delete Laptop")
    print("[4]. Find Laptop")
    print("[5]. Display All Laptops")
    print("[6]. Exit")
    return input("Enter your choice: ")


def input_int(prompt, allow_empty=False):
    while True:
        value = input(prompt)
        if allow_empty and value.strip() == "":
            return None
        try:
            return int(value)
        except ValueError:
            print("Input must be a number.")


def main():
    laptops = [
        Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2),
        Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1),
        Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3),
    ]

    while True:
        choice = menu()

        if choice == "1":
            clear_screen()
            print("Insert New Laptop")

            temp_id = input_int("Laptop ID: ")
            if any(l.get_id() == temp_id for l in laptops):
                print("ID already exists.")
                continue

            temp_name = input("Laptop Name: ")
            temp_brand = input("Laptop Brand: ")
            temp_color = input("Laptop Color: ")
            temp_price = input_int("Laptop Price: ")
            temp_warranty = input_int("Laptop Warranty: ")

            laptops.append(Laptop(temp_id, temp_name, temp_brand, temp_color, temp_price, temp_warranty))

        elif choice == "2":
            clear_screen()
            print("Update Laptop Info")

            temp_id = input_int("Enter Laptop ID: ")
            laptop = next((l for l in laptops if l.get_id() == temp_id), None)
            if laptop is None:
                print("Laptop not found")
                continue

            print("\nLeave empty if you don’t want to change.")
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

        elif choice == "5":
            clear_screen()
            print("All Laptops:\n")
            if not laptops:
                print("No laptops available.")
            for l in laptops:
                l.display()

        elif choice == "6":
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
