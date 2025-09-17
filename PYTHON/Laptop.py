"""
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
"""

class Laptop:
    # Constructor with default values
    def __init__(self, id=0, name="", brand="", color="", price=0, warranty=0):
        # Private attributes (name-mangled with double underscore)
        self.__id = id
        self.__name = name
        self.__brand = brand
        self.__color = color
        self.__price = price #in Rupiah
        self.__warranty = warranty #in year

    # ===== Getter Methods =====
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

    # ===== Setter Methods =====
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

    # ===== Method to display laptop info =====
    def display(self):
        print(f"ID: {self.__id}")
        print(f"Name: {self.__name}")
        print(f"Brand: {self.__brand}")
        print(f"Color: {self.__color}")
        print(f"Price: Rp {self.__price}")
        # Conditional text for warranty (singular/plural)
        if self.__warranty > 1:
            print(f"Warranty: {self.__warranty} years\n")
        else:
            print(f"Warranty: {self.__warranty} year\n")
