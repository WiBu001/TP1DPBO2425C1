/* Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "Laptop.cpp"
#include <vector>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");   // for Windows
#else
    system("clear"); //for Linux/Mac
#endif
}

void Menu(){
    cout << endl << "Menu:" << endl;
    cout << "[1]. Insert New Laptop" << endl;
    cout << "[2]. Update Laptop Info" << endl;
    cout << "[3]. Delete Laptop" << endl;
    cout << "[4]. Find Laptop" << endl;
    cout << "[5]. Display All Laptops" << endl;
    cout << "[6]. Exit" << endl;
    cout << "Enter your choice: ";
}

int main(){
    int choice = 0;
    vector<Laptop> laptops;

    // Create Laptop objects using parameterized constructor
    Laptop laptop1(1, "XPS 13", "Dell", "Silver", 15000000, 2);
    Laptop laptop2(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1);
    Laptop laptop3(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3);

    // Add laptops to the vector
    laptops.push_back(laptop1);
    laptops.push_back(laptop2);
    laptops.push_back(laptop3);

    clearScreen();
    do{
        Menu();
        cin >> choice;

        if(choice == 1){
            clearScreen();
            int tempID;
            string tempName;
            string tempBrand;
            string tempColor;
            int tempPrice;
            int tempWarranty;
            bool validID = false;
            bool validPrice = false;
            bool validWarranty = false;

            cout << "Please input your proudct" << endl;

            while(!validID){
                cout << "Laptop ID: ";
                cin >> tempID;
                int checkID = 0;
                while(checkID < laptops.size() && !validID){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "ID must be a number" << endl;
                        break;
                    }
                    if(tempID == laptops[checkID].getID()){
                        cout << "ID already exists. Please enter a different ID" << endl;
                        break;
                    }
                    if(checkID == laptops.size() - 1){
                        validID = true;
                    }
                    checkID++;
                }
            }

            cout << "Laptop Name: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, tempName);
            
            cout << "Laptop Brand: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, tempBrand);
            
            cout << "Laptop Color: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, tempColor);

            while(!validPrice){
                cout << "Laptop Price: ";
                cin >> tempPrice;
                if(tempPrice < 0 || cin.fail()){
                    cin.clear(); // clear the fail state
                    cin.ignore(10000, '\n'); // discard invalid input
                    cout << "Please enter a valid price." << endl;
                }else{
                    validPrice = true;
                }
            }

            cin.ignore(); // Clear the newline character from the input buffer

            while(!validWarranty){
                cout << "Laptop Warranty: ";
                cin >> tempWarranty;
                if(tempWarranty < 0 || cin.fail()){
                    cin.clear(); // clear the fail state
                    cin.ignore(10000, '\n'); // discard invalid input
                    cout << "Please enter a valid warranty period." << endl;
                }else{
                    validWarranty = true;
                }
            }

            cin.ignore(); // Clear the newline character from the input buffer

            Laptop newLaptop(tempID, tempName, tempBrand, tempColor, tempPrice, tempWarranty);
            laptops.push_back(newLaptop);

        }else if(choice == 2){
            clearScreen();
            cout << "Update Your Laptop Info" << endl;

            int tempID;
            bool validID = false;
            int checkID = 0;
            string tempName;
            string tempBrand;
            string tempColor;
            int tempPrice;
            int tempWarranty;
            bool validPrice = false;
            bool validWarranty = false;
            
            while(!validID && checkID < laptops.size()){
                cout << "Enter Laptop ID: ";
                cin >> tempID;
                
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "ID must be a number" << endl;
                    continue;
                }

                checkID = 0;
                while(checkID < laptops.size() && !validID){
                    if(tempID == laptops[checkID].getID()){
                        validID = true;
                        break;
                    }
                    checkID++;
                }

            }

            if(validID){
                cout << "Update Your Laptop Info" << endl << endl;
                
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Old Name: " << laptops[checkID].getName() << endl;
                cout << "New Name: ";
                getline(cin, tempName);
                laptops[checkID].setName(tempName);

                cout << "Old Brand: " << laptops[checkID].getBrand() << endl;
                cout << "New Brand: ";
                getline(cin, tempBrand);
                laptops[checkID].setBrand(tempBrand);

                cout << "Old Color: " << laptops[checkID].getColor() << endl;
                cout << "New Color: ";
                getline(cin, tempColor);
                laptops[checkID].setColor(tempColor);

                while(!validPrice){
                    cout << "Old Price: Rp " << laptops[checkID].getPrice() << endl;
                    cout << "New Price: ";
                    cin >> tempPrice;
                    if(tempPrice < 0 || cin.fail()){
                        cin.clear(); // clear the fail state
                        cin.ignore(10000, '\n'); // discard invalid input
                        cout << "Please enter a valid price." << endl;
                    }else{
                        validPrice = true;
                        laptops[checkID].setPrice(tempPrice);
                    }
                }

                while(!validWarranty){
                    if(laptops[checkID].getWarranty() > 1) {
                        cout << "Old Warranty: " << laptops[checkID].getWarranty() << " years" << endl;
                    } else {
                        cout << "Old Warranty: " << laptops[checkID].getWarranty() << " year" << endl;
                    }
                    cout << "New Warranty: ";
                    cin >> tempWarranty;
                    if(tempWarranty < 0 || cin.fail()){
                        cin.clear(); // clear the fail state
                        cin.ignore(10000, '\n'); // discard invalid input
                        cout << "Please enter a valid warranty period." << endl;
                    }else{
                        laptops[checkID].setWarranty(tempWarranty);
                        validWarranty = true;
                    }
                }

                cout << "Laptop Info Updated" << endl;
                laptops[checkID].displayLaptop();
            }else{
                cout << "Laptop not found" << endl;
            }

        }else if(choice == 3){
            clearScreen();
            cout << "Delete Your Laptop" << endl;
            int tempID;
            bool validID = false;
            char validation;

            cout << "Enter Laptop ID: ";
            cin >> tempID;
            int checkID = 0;
            while(checkID < laptops.size() && !validID){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "ID must be a number" << endl;
                    break;
                }
                if(tempID == laptops[checkID].getID()){
                    validID = true;
                    break;
                }
                checkID++;
            }

            while(checkID < laptops.size() && validID){
                if(tempID == laptops[checkID].getID()){
                    laptops[checkID].displayLaptop();
                    cout << "Are you sure? (Y/N)" << endl;
                    cin >> validation;
                    if(validation == 'Y' || validation == 'y'){
                        laptops.erase(laptops.begin() + checkID);
                        cout << "Laptop deleted." << endl;
                    }else{
                        cout << "Laptop not deleted." << endl;
                    }
                    validID = true;
                }
                if(checkID == laptops.size() - 1 && !validID){
                    cout << "Laptop not found" << endl;
                }
                checkID++;
            }

        }else if(choice == 4){
            clearScreen();
            cout << "Find Your Laptop" << endl;
            int tempID;
            bool validID = false;
            int checkID = 0;

            cout << "Enter Laptop ID: ";
            cin >> tempID;
            while(checkID < laptops.size() && !validID){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "ID must be a number" << endl;
                    break;
                }
                if(tempID == laptops[checkID].getID()){
                    validID = true;
                    break;
                }
                checkID++;
            }

            while(checkID < laptops.size() && validID){
                if(tempID == laptops[checkID].getID()){
                    cout << "Here's Your Laptop Info" << endl;
                    laptops[checkID].displayLaptop();
                    validID = true;
                }
                if(checkID == laptops.size() - 1 && !validID){
                    cout << "Laptop not found" << endl;
                }
                checkID++;
            }

        }else if(choice == 5){
            clearScreen();
            cout << "All Laptops:" << endl << endl;
            for(int i = 0; i < laptops.size(); i++){
                laptops[i].displayLaptop();
            }

        }else if(choice == 6){
            clearScreen();
            cout << "Exiting program." << endl;
        }

    }while(choice != 6);

    return 0;
}