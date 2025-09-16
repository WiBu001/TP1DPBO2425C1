import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static void clearScreen() {
        // di Java tidak ada system("cls"), jadi cukup kasih banyak newline
        for (int i = 0; i < 30; i++) {
            System.out.println();
        }
    }

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
        Scanner sc = new Scanner(System.in);
        ArrayList<Laptop> laptops = new ArrayList<>();

        // Default data
        laptops.add(new Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2));
        laptops.add(new Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1));
        laptops.add(new Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3));

        int choice;
        do {
            clearScreen();
            menu();
            while (!sc.hasNextInt()) {
                System.out.println("Choice must be a number");
                sc.next();
            }
            choice = sc.nextInt();
            sc.nextLine(); // clear newline

            if (choice == 1) {
                clearScreen();
                System.out.println("Insert New Laptop");

                int id;
                String name, brand, color;
                int price, warranty;

                // Validasi ID unik
                while (true) {
                    System.out.print("Laptop ID: ");
                    while (!sc.hasNextInt()) {
                        System.out.println("ID must be a number");
                        sc.next();
                    }
                    id = sc.nextInt();
                    sc.nextLine();

                    boolean exists = false;
                    for (Laptop l : laptops) {
                        if (l.getId() == id) {
                            exists = true;
                            break;
                        }
                    }
                    if (exists) {
                        System.out.println("ID already exists. Enter another.");
                    } else {
                        break;
                    }
                }

                System.out.print("Laptop Name: ");
                name = sc.nextLine();

                System.out.print("Laptop Brand: ");
                brand = sc.nextLine();

                System.out.print("Laptop Color: ");
                color = sc.nextLine();

                // Validasi price
                while (true) {
                    System.out.print("Laptop Price: ");
                    if (sc.hasNextInt()) {
                        price = sc.nextInt();
                        sc.nextLine();
                        if (price >= 0) break;
                    } else {
                        sc.next();
                    }
                    System.out.println("Please enter a valid price.");
                }

                // Validasi warranty
                while (true) {
                    System.out.print("Laptop Warranty: ");
                    if (sc.hasNextInt()) {
                        warranty = sc.nextInt();
                        sc.nextLine();
                        if (warranty >= 0) break;
                    } else {
                        sc.next();
                    }
                    System.out.println("Please enter a valid warranty.");
                }

                laptops.add(new Laptop(id, name, brand, color, price, warranty));

            } else if (choice == 2) {
                clearScreen();
                System.out.println("Update Laptop Info");

                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                if (target != null) {
                    System.out.println("Old Name: " + target.getName());
                    System.out.print("New Name: ");
                    target.setName(sc.nextLine());

                    System.out.println("Old Brand: " + target.getBrand());
                    System.out.print("New Brand: ");
                    target.setBrand(sc.nextLine());

                    System.out.println("Old Color: " + target.getColor());
                    System.out.print("New Color: ");
                    target.setColor(sc.nextLine());

                    int price;
                    while (true) {
                        System.out.println("Old Price: Rp " + target.getPrice());
                        System.out.print("New Price: ");
                        if (sc.hasNextInt()) {
                            price = sc.nextInt();
                            sc.nextLine();
                            if (price >= 0) {
                                target.setPrice(price);
                                break;
                            }
                        } else {
                            sc.next();
                        }
                        System.out.println("Please enter a valid price.");
                    }

                    int warranty;
                    while (true) {
                        System.out.println("Old Warranty: " + target.getWarranty());
                        System.out.print("New Warranty: ");
                        if (sc.hasNextInt()) {
                            warranty = sc.nextInt();
                            sc.nextLine();
                            if (warranty >= 0) {
                                target.setWarranty(warranty);
                                break;
                            }
                        } else {
                            sc.next();
                        }
                        System.out.println("Please enter a valid warranty.");
                    }

                    System.out.println("Laptop Info Updated");
                    target.displayLaptop();

                } else {
                    System.out.println("Laptop not found");
                }

            } else if (choice == 3) {
                clearScreen();
                System.out.println("Delete Laptop");

                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                if (target != null) {
                    target.displayLaptop();
                    System.out.print("Are you sure? (Y/N): ");
                    char confirm = sc.next().charAt(0);
                    if (confirm == 'Y' || confirm == 'y') {
                        laptops.remove(target);
                        System.out.println("Laptop deleted.");
                    } else {
                        System.out.println("Laptop not deleted.");
                    }
                } else {
                    System.out.println("Laptop not found.");
                }

            } else if (choice == 4) {
                clearScreen();
                System.out.println("Find Laptop");

                System.out.print("Enter Laptop ID: ");
                while (!sc.hasNextInt()) {
                    System.out.println("ID must be a number");
                    sc.next();
                }
                int id = sc.nextInt();
                sc.nextLine();

                Laptop target = null;
                for (Laptop l : laptops) {
                    if (l.getId() == id) {
                        target = l;
                        break;
                    }
                }

                if (target != null) {
                    System.out.println("Here's Your Laptop Info");
                    target.displayLaptop();
                } else {
                    System.out.println("Laptop not found.");
                }

            } else if (choice == 5) {
                clearScreen();
                System.out.println("All Laptops:\n");
                for (Laptop l : laptops) {
                    l.displayLaptop();
                }

            } else if (choice == 6) {
                clearScreen();
                System.out.println("Exiting program.");
            }

            System.out.println("Press Enter to continue...");
            sc.nextLine();

        } while (choice != 6);

        sc.close();
    }
}