/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    // Procedure to clear the screen (works in terminals that support ANSI escape codes)
    private static void clearScreen() {
        System.out.print("\033[H\033[2J");
    }

    // Procedure to display the main menu
    private static void menu() {
        System.out.println("\nMenu:");
        System.out.println("[1]. Insert New Laptop");
        System.out.println("[2]. Update Laptop Info");
        System.out.println("[3]. Delete Laptop");
        System.out.println("[4]. Find Laptop");
        System.out.println("[5]. Display All Laptops");
        System.out.println("[6]. Exit");
        System.out.print("Enter your choice: ");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);             // Scanner for input
        ArrayList<Laptop> laptops = new ArrayList<>();   // List to store laptop objects

        // Default initial data
        laptops.add(new Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2));
        laptops.add(new Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1));
        laptops.add(new Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3));

        int choice;
        // Main program loop
        do {
            clearScreen();   // Clear the screen before showing menu
            menu();          // Show the menu

            // Validate menu input
            while (!sc.hasNextInt()) {
                System.out.println("Choice must be a number");
                sc.next();
            }
            choice = sc.nextInt();
            sc.nextLine(); // Clear newline

            // Option 1: Insert new laptop
            if (choice == 1) {
                clearScreen();
                System.out.println("Insert New Laptop");

                int id;
                String name, brand, color;
                int price, warranty;

                // Validate unique ID
                while (true) {
                    System.out.print("Laptop ID: ");
                    //if ID is not a number
                    while (!sc.hasNextInt()) {
                        System.out.println("ID must be a number");
                        sc.next();
                    }
                    id = sc.nextInt();
                    sc.nextLine();

                    //Check ID
                    boolean exists = false;
                    for (Laptop l : laptops) {
                        //if exist
                        if (l.getId() == id) {
                            exists = true;
                            break;
                        }
                    }

                    //if Exist
                    if (exists) {
                        System.out.println("ID already exists. Enter another.");
                    } else {
                        break;
                    }
                }

                // Input name
                System.out.print("Laptop Name: ");
                name = sc.nextLine();

                // Input brand
                System.out.print("Laptop Brand: ");
                brand = sc.nextLine();

                // Input color
                System.out.print("Laptop Color: ");
                color = sc.nextLine();

                // Validate price
                while (true) {
                    System.out.print("Laptop Price: ");
                    //check Price
                    if (sc.hasNextInt()) {
                        price = sc.nextInt();
                        sc.nextLine();
                        //if valid price
                        if (price >= 0) break;
                    } else {
                        sc.next();
                    }
                    System.out.println("Please enter a valid price.");
                }

                // Validate warranty
                while (true) {
                    System.out.print("Laptop Warranty: ");
                    //check Warranty
                    if (sc.hasNextInt()) {
                        warranty = sc.nextInt();
                        sc.nextLine();
                        //if valid warranty
                        if (warranty >= 0) break;
                    } else {
                        sc.next();
                    }
                    System.out.println("Please enter a valid warranty.");
                }

                // Add laptop to the list
                laptops.add(new Laptop(id, name, brand, color, price, warranty));

            // Option 2: Update laptop info
            } else if (choice == 2) {
                clearScreen();
                System.out.println("Update Laptop Info");

                // Input ID to search
                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                // Search for laptop by ID
                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                // If found, perform update
                if (target != null) {
                    //update name
                    System.out.println("Old Name: " + target.getName());
                    System.out.print("New Name: ");
                    target.setName(sc.nextLine());

                    //update brand
                    System.out.println("Old Brand: " + target.getBrand());
                    System.out.print("New Brand: ");
                    target.setBrand(sc.nextLine());

                    //update color
                    System.out.println("Old Color: " + target.getColor());
                    System.out.print("New Color: ");
                    target.setColor(sc.nextLine());

                    // Validate new price
                    int price;
                    while (true) {
                        System.out.println("Old Price: Rp " + target.getPrice());
                        System.out.print("New Price: ");
                        //check price
                        if (sc.hasNextInt()) {
                            price = sc.nextInt();
                            sc.nextLine();
                            //if valid price
                            if (price >= 0) {
                                target.setPrice(price);
                                break;
                            }
                        } else {
                            sc.next();
                        }
                        System.out.println("Please enter a valid price.");
                    }

                    // Validate new warranty
                    int warranty;
                    while (true) {
                        System.out.println("Old Warranty: " + target.getWarranty());
                        System.out.print("New Warranty: ");

                        //check warranty
                        if (sc.hasNextInt()) {
                            warranty = sc.nextInt();
                            sc.nextLine();

                            //if valid warranty
                            if (warranty >= 0) {
                                target.setWarranty(warranty);
                                break;
                            }
                        } else {
                            sc.next();
                        }
                        System.out.println("Please enter a valid warranty.");
                    }

                    // Show updated info
                    System.out.println("Laptop Info Updated");
                    target.displayLaptop();

                } else {
                    System.out.println("Laptop not found");
                }

            // Option 3: Delete laptop
            } else if (choice == 3) {
                clearScreen();
                System.out.println("Delete Laptop");

                // Input ID
                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                // Search for laptop by ID
                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                // If found, ask for confirmation
                if (target != null) {
                    //Display Laptop info
                    target.displayLaptop();

                    //input confirmation
                    System.out.print("Are you sure? (Y/N): ");
                    char confirm = sc.next().charAt(0);

                    //if yes
                    if (confirm == 'Y' || confirm == 'y') {
                        //remove laptop
                        laptops.remove(target);
                        System.out.println("Laptop deleted.");
                    } else {
                        System.out.println("Laptop not deleted.");
                    }
                } else {
                    System.out.println("Laptop not found.");
                }

            // Option 4: Find laptop
            } else if (choice == 4) {
                clearScreen();
                System.out.println("Find Laptop");

                // Input ID
                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                // Search for laptop
                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                //if exist
                if (target != null) {
                    //display laptop info
                    System.out.println("Here's Your Laptop Info");
                    target.displayLaptop();
                } else {
                    System.out.println("Laptop not found.");
                }

            // Option 5: Display all laptops
            } else if (choice == 5) {
                clearScreen();
                System.out.println("All Laptops:\n");
                for (Laptop l : laptops) {
                    l.displayLaptop();
                }

            // Option 6: Exit program
            } else if (choice == 6) {
                clearScreen();
                System.out.println("Exiting program.");
            }

            // Pause so user can read the output
            System.out.println("Press Enter to continue...");
            sc.nextLine();

        } while (choice != 6);  // Stop when user chooses 6

        sc.close(); // Close scanner
    }
}
