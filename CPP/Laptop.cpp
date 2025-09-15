/* Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <iostream>
#include <string>
using namespace std;

class Laptop {
    private:
        int id;
        string name;
        string brand;
        string color;
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

        //Setter
        void setName(string name) {
            this->name = name;
        }

        void setBrand(string brand) {
            this->brand = brand;
        }

        void setColor(string color) {
            this->color = color;
        }

        void setPrice(int price) {
            this->price = price;
        }

        void setWarranty(int warranty) {
            this->warranty = warranty;
        }

        int getID() {
            return this->id;
        }

        string getName() {
            return this->name;
        }

        string getBrand() {
            return this->brand;
        }

        string getColor() {
            return this->color;
        }

        int getPrice() {
            return this->price;
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