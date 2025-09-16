/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

public class Laptop {
    // Attributes
    private int id;
    private String name;
    private String brand;
    private String color;
    private int price;     // in Rupiah
    private int warranty;  // in year

    // Default Constructor
    public Laptop() {
        this.id = 0;
        this.name = "";
        this.brand = "";
        this.color = "";
        this.price = 0;
        this.warranty = 0;
    }

    // Constructor with parameters
    public Laptop(int id, String name, String brand, String color, int price, int warranty) {
        this.id = id;
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.price = price;
        this.warranty = warranty;
    }

    // Setter
    public void setName(String name) {
        this.name = name;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setWarranty(int warranty) {
        this.warranty = warranty;
    }

    // Getter
    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getBrand() {
        return this.brand;
    }

    public String getColor() {
        return this.color;
    }

    public int getPrice() {
        return this.price;
    }

    public int getWarranty() {
        return this.warranty;
    }

    // Method to display laptop info
    public void displayLaptop() {
        System.out.println("ID: " + this.id);
        System.out.println("Name: " + this.name);
        System.out.println("Brand: " + this.brand);
        System.out.println("Color: " + this.color);
        System.out.println("Price: Rp " + this.price);
        if (warranty > 1) {
            System.out.println("Warranty: " + this.warranty + " years\n");
        } else {
            System.out.println("Warranty: " + this.warranty + " year\n");
        }
    }
}
