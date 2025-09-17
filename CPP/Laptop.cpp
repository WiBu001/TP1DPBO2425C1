/* Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <iostream>
#include <string>
using namespace std;

//create Laptop class
class Laptop {
    //create private attribute
    private:
        int id; //declare id
        string name; //declare name
        string brand; //declare brand
        string color; //declare color
        int price; //in Rupiah
        int warranty; // in year

    public:

        //Default Constructor
        Laptop(){
            this->id = 0;
            this->name = "";
            this->brand = "";
            this->color = "";
            this->price = 0;
            this->warranty = 0;
        }

        //Constructor with parameter
        Laptop(int id, string name, string brand, string color, int price, int warranty) {
            this->id = id;
            this->name = name;
            this->brand = brand;
            this->color = color;
            this->price = price;
            this->warranty = warranty;
        }

        //Getter for id
         int getID() {
            return this->id;
        }

        //Setter and Getter for name
        void setName(string name) {
            this->name = name;
        }

        string getName() {
            return this->name;
        }

        //Setter and Getter for Brand
        void setBrand(string brand) {
            this->brand = brand;
        }

        string getBrand() {
            return this->brand;
        }

        //Setter and Getter for Color
        void setColor(string color) {
            this->color = color;
        }

        string getColor() {
            return this->color;
        }

        //Setter and Getter for Price
        void setPrice(int price) {
            this->price = price;
        }

        int getPrice() {
            return this->price;
        }

        //Setter and Getter for Warranty
        void setWarranty(int warranty) {
            this->warranty = warranty;
        }

        int getWarranty() {
            return this->warranty;
        }

        //Method
        void displayLaptop() {
            cout << "ID: " << this->id << endl;
            cout << "Name: " << this->name << endl;
            cout << "Brand: " << this->brand << endl;
            cout << "Color: " << this->color << endl;
            cout << "Price: Rp " << this->price << endl;
            if(warranty > 1) {
                cout << "Warranty: " << this->warranty << " years" << endl << endl;
            } else {
                cout << "Warranty: " << this->warranty << " year" << endl << endl;
            }
        }

        //Destructor
        ~Laptop() {
        }
};