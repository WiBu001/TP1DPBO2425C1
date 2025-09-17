/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

//Create Laptop Class
public class Laptop {
    // Attributes of Laptop
    private int id; //declare ID
    private String name; //declare Name
    private String brand; //declare brand
    private String color; //declare color
    private int price;     // Price in Rupiah
    private int warranty;  // Warranty in years

    // Default Constructor (no parameters)
    public Laptop() {
        this.id = 0;
        this.name = "";
        this.brand = "";
        this.color = "";
        this.price = 0;
        this.warranty = 0;
    }

    // Constructor with parameters (initialize attributes directly)
    public Laptop(int id, String name, String brand, String color, int price, int warranty) {
        this.id = id;
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.price = price;
        this.warranty = warranty;
    }

    // Setter name
    public void setName(String name) {
        this.name = name;
    }

    //Setter brand
    public void setBrand(String brand) {
        this.brand = brand;
    }

    //Setter color
    public void setColor(String color) {
        this.color = color;
    }

    //Setter price
    public void setPrice(int price) {
        this.price = price;
    }

    //Setter warranty
    public void setWarranty(int warranty) {
        this.warranty = warranty;
    }

    // Getter ID
    public int getId() {
        return this.id;
    }

    //Getter name
    public String getName() {
        return this.name;
    }

    //Getter brand
    public String getBrand() {
        return this.brand;
    }

    //Getter color
    public String getColor() {
        return this.color;
    }

    //Getter price
    public int getPrice() {
        return this.price;
    }

    //Getter Warranty
    public int getWarranty() {
        return this.warranty;
    }

    // Method to display laptop information
    public void displayLaptop() {
        System.out.println("ID: " + this.id);
        System.out.println("Name: " + this.name);
        System.out.println("Brand: " + this.brand);
        System.out.println("Color: " + this.color);
        System.out.println("Price: Rp " + this.price);
        // Display warranty in singular or plural form
        if (warranty > 1) {
            System.out.println("Warranty: " + this.warranty + " years\n");
        } else {
            System.out.println("Warranty: " + this.warranty + " year\n");
        }
    }
}