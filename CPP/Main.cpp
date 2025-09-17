/* Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "Laptop.cpp"
#include <vector>
using namespace std;

//create procedure for clearScreen
void clearScreen() {
#ifdef _WIN32
    system("cls");   // for Windows
#else
    system("clear"); //for Linux/Mac
#endif
}

//create Menu
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
    int choice = 0; //declare variable
    vector<Laptop> laptops;

    //Create Laptop objects using parameterized constructor
    Laptop laptop1(1, "XPS 13", "Dell", "Silver", 15000000, 2);
    Laptop laptop2(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1);
    Laptop laptop3(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3);

    //Add laptops to the vector
    laptops.push_back(laptop1);
    laptops.push_back(laptop2);
    laptops.push_back(laptop3);

    //cleas screen
    clearScreen();

    //Main program
    do{
        //Show Menu
        Menu();
        //Input choice
        cin >> choice;

        //if user want to input new laptop
        if(choice == 1){
            //declare temp variable for constructing
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

            //loop while ID is not valid
            while(!validID){
                //input ID
                cout << "Laptop ID: ";
                cin >> tempID;

                //check if ID is valid
                int checkID = 0;
                //loop until last element
                while(checkID < laptops.size() && !validID){
                    //if ID is not number
                    if(cin.fail()){
                        cin.clear(); //clear error
                        cin.ignore(10000, '\n'); //discard invalid input
                        cout << "ID must be a number" << endl;
                        break;
                    }
                    //if ID is already used
                    if(tempID == laptops[checkID].getID()){
                        cout << "ID already exists. Please enter a different ID" << endl;
                        break;
                    }
                    //if there is no same ID
                    if(checkID == laptops.size() - 1){
                        validID = true;
                    }
                    checkID++;
                }
            }

            //Input name
            cout << "Laptop Name: ";
            cin.ignore(); //Clear the newline character from the input buffer
            getline(cin, tempName);
            
            //Input brand
            cout << "Laptop Brand: ";
            cin.ignore(); //Clear the newline character from the input buffer
            getline(cin, tempBrand);
            
            //Input color
            cout << "Laptop Color: ";
            cin.ignore(); //Clear the newline character from the input buffer
            getline(cin, tempColor);

            //check valid Price
            while(!validPrice){
                //input Price
                cout << "Laptop Price: ";
                cin >> tempPrice;

                //if Price is negative or not a number
                if(tempPrice < 0 || cin.fail()){
                    cin.clear(); //Clear the fail state
                    cin.ignore(10000, '\n'); //Discard invalid input
                    cout << "Please enter a valid price." << endl;
                }else{
                    validPrice = true;
                }
            }

            cin.ignore(); //Clear the newline character from the input buffer

            //Check valid Warranty
            while(!validWarranty){
                //Input Warranty
                cout << "Laptop Warranty: ";
                cin >> tempWarranty;

                //if Warranty is negative or not a number
                if(tempWarranty < 0 || cin.fail()){
                    cin.clear(); //Clear the fail state
                    cin.ignore(10000, '\n'); //Discard invalid input
                    cout << "Please enter a valid warranty period." << endl;
                }else{
                    validWarranty = true;
                }
            }

            cin.ignore(); //Clear the newline character from the input buffer

            //Construct new object
            Laptop newLaptop(tempID, tempName, tempBrand, tempColor, tempPrice, tempWarranty);
            //Add new laptop to vector
            laptops.push_back(newLaptop);

        //If user want to update laptop info
        }else if(choice == 2){
            //clear screen
            clearScreen();
            cout << "Update Your Laptop Info" << endl;

            //declare temp variable for updating
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
            
            //Check valid ID
            while(!validID && checkID < laptops.size()){
                //Input ID
                cout << "Enter Laptop ID: ";
                cin >> tempID;
                
                //if not a number
                if(cin.fail()){
                    cin.clear(); //Clear the fail state
                    cin.ignore(10000, '\n'); //Discard invalid input
                    cout << "ID must be a number" << endl;
                    continue;
                }

                checkID = 0;
                //Check ID 
                while(checkID < laptops.size() && !validID){
                    //if exist
                    if(tempID == laptops[checkID].getID()){
                        validID = true;
                        break;
                    }
                    checkID++;
                }

            }

            //if ID is valid
            if(validID){
                cout << "Update Your Laptop Info" << endl << endl;
                
                //Input new name
                cin.ignore(); //Clear the newline character from the input buffer
                cout << "Old Name: " << laptops[checkID].getName() << endl;
                cout << "New Name: ";
                getline(cin, tempName);
                laptops[checkID].setName(tempName);

                //Input new Brand
                cout << "Old Brand: " << laptops[checkID].getBrand() << endl;
                cout << "New Brand: ";
                getline(cin, tempBrand);
                laptops[checkID].setBrand(tempBrand);

                //Input new Color
                cout << "Old Color: " << laptops[checkID].getColor() << endl;
                cout << "New Color: ";
                getline(cin, tempColor);
                laptops[checkID].setColor(tempColor);

                //Check valid Price
                while(!validPrice){
                    //input New Price
                    cout << "Old Price: Rp " << laptops[checkID].getPrice() << endl;
                    cout << "New Price: ";
                    cin >> tempPrice;
                    //if Price is negative or not a number
                    if(tempPrice < 0 || cin.fail()){
                        cin.clear(); //Clear the fail state
                        cin.ignore(10000, '\n'); //Discard invalid input
                        cout << "Please enter a valid price." << endl;

                    //if Price is Valid
                    }else{
                        validPrice = true;
                        laptops[checkID].setPrice(tempPrice);
                    }
                }

                //Check valid Warranty
                while(!validWarranty){
                    //Input new Warranty
                    if(laptops[checkID].getWarranty() > 1) {
                        cout << "Old Warranty: " << laptops[checkID].getWarranty() << " years" << endl;
                    } else {
                        cout << "Old Warranty: " << laptops[checkID].getWarranty() << " year" << endl;
                    }
                    cout << "New Warranty: ";
                    cin >> tempWarranty;

                    //if Warranty negative or not a number
                    if(tempWarranty < 0 || cin.fail()){
                        cin.clear(); //Clear the fail state
                        cin.ignore(10000, '\n'); //Discard invalid input
                        cout << "Please enter a valid warranty period." << endl;

                    //if Warranty valid
                    }else{
                        laptops[checkID].setWarranty(tempWarranty);
                        validWarranty = true;
                    }
                }

                //Display new Laptop info
                cout << "Laptop Info Updated" << endl;
                laptops[checkID].displayLaptop();

            //if ID not found
            }else{
                cout << "Laptop not found" << endl;
            }

        //if user want to delete
        }else if(choice == 3){
            //Declare ID temporary
            clearScreen();
            cout << "Delete Your Laptop" << endl;
            int tempID;
            bool validID = false;
            char validation;

            //input ID
            cout << "Enter Laptop ID: ";
            cin >> tempID;
            int checkID = 0;

            //Check valid ID
            while(checkID < laptops.size() && !validID){
                //if ID is not a number
                if(cin.fail()){
                    cin.clear(); //Clear the fail state
                    cin.ignore(10000, '\n'); //Discard invalid input
                    cout << "ID must be a number" << endl;
                    break;
                }

                //if ID exist
                if(tempID == laptops[checkID].getID()){
                    validID = true;
                    break;
                }
                checkID++;
            }

            if(validID){
                //Display laptop info
                laptops[checkID].displayLaptop();

                //Confirm if want to delete
                cout << "Are you sure? (Y/N)" << endl;
                cin >> validation;
    
                //if yes
                if(validation == 'Y' || validation == 'y'){
                    //delete laptop
                    laptops.erase(laptops.begin() + checkID);
                    cout << "Laptop deleted." << endl;
    
                //if not
                }else{
                    cout << "Laptop not deleted." << endl;
                }
            }else{
                cout << "Laptop not found." << endl;
            }

            validID = true;

            //if user want to find laptop info
        }else if(choice == 4){
            //Declare temp ID
            clearScreen();
            cout << "Find Your Laptop" << endl;
            int tempID;
            bool validID = false;
            int checkID = 0;

            //input ID
            cout << "Enter Laptop ID: ";
            cin >> tempID;

            //Check valid ID
            while(checkID < laptops.size() && !validID){
                //if ID is not a number
                if(cin.fail()){
                    cin.clear(); //Clear the fail state
                    cin.ignore(10000, '\n'); //Discard invalid input
                    cout << "ID must be a number" << endl;
                    break;
                }
                //if ID is valid
                if(tempID == laptops[checkID].getID()){
                    validID = true;
                    break;
                }
                checkID++;
            }

            if(validID){
                cout << "Here's Your Laptop Info" << endl;
                laptops[checkID].displayLaptop();
                validID = true;
            }else{
                cout << "Laptop not found" << endl;
            }

            //if user want to display all Laptop
        }else if(choice == 5){
            clearScreen();
            //Display All Laptop
            cout << "All Laptops:" << endl << endl;
            for(int i = 0; i < laptops.size(); i++){
                laptops[i].displayLaptop();
            }

        //if user want to exit progrtam
        }else if(choice == 6){
            clearScreen();
            cout << "Exiting program." << endl;
        }

    }while(choice != 6);

    return 0;
}