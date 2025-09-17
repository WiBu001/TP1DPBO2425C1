# laptop.py
# Class Laptop

class Laptop:
    def __init__(self, id=0, name="", brand="", color="", price=0, warranty=0):
        self.__id = id
        self.__name = name
        self.__brand = brand
        self.__color = color
        self.__price = price
        self.__warranty = warranty

    # Getter
    def get_id(self):
        return self.__id

    def get_name(self):
        return self.__name

    def get_brand(self):
        return self.__brand

    def get_color(self):
        return self.__color

    def get_price(self):
        return self.__price

    def get_warranty(self):
        return self.__warranty

    # Setter
    def set_name(self, name):
        self.__name = name

    def set_brand(self, brand):
        self.__brand = brand

    def set_color(self, color):
        self.__color = color

    def set_price(self, price):
        self.__price = price

    def set_warranty(self, warranty):
        self.__warranty = warranty

    # Display method
    def display(self):
        print(f"ID: {self.__id}")
        print(f"Name: {self.__name}")
        print(f"Brand: {self.__brand}")
        print(f"Color: {self.__color}")
        print(f"Price: Rp {self.__price}")
        if self.__warranty > 1:
            print(f"Warranty: {self.__warranty} years\n")
        else:
            print(f"Warranty: {self.__warranty} year\n")
