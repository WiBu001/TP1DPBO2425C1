<?php
/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

class Laptop {
    // --- Attributes (private) ---
    private $id;
    private $name;
    private $brand;
    private $color;
    private $price;
    private $warranty;
    private $image;

    // --- Constructor ---
    public function __construct($id, $name, $brand, $color, $price, $warranty, $image) {
        $this->id = $id;
        $this->name = $name;
        $this->brand = $brand;
        $this->color = $color;
        $this->price = $price;
        $this->warranty = $warranty;
        $this->image = $image;
    }

    // --- Getter ---
    public function getId() { return $this->id; }
    public function getName() { return $this->name; }
    public function getBrand() { return $this->brand; }
    public function getColor() { return $this->color; }
    public function getPrice() { return $this->price; }
    public function getWarranty() { return $this->warranty; }
    public function getImage() { return $this->image; }

    // --- Setter (opsional untuk edit) ---
    public function setName($name) { $this->name = $name; }
    public function setBrand($brand) { $this->brand = $brand; }
    public function setColor($color) { $this->color = $color; }
    public function setPrice($price) { if ($price >= 0) $this->price = $price; }
    public function setWarranty($warranty) { if ($warranty >= 0) $this->warranty = $warranty; }
    public function setImage($image) { $this->image = $image; }

    // --- Display laptop card ---
    public function displayCard($index) {
        echo "
        <div class='card'>
            <img src='uploads/{$this->image}' alt='{$this->name}' />
            <h3>{$this->name}</h3>
            <p><b>Brand:</b> {$this->brand}</p>
            <p><b>Color:</b> {$this->color}</p>
            <p><b>Price:</b> Rp {$this->price}</p>
            <p><b>Warranty:</b> {$this->warranty} year(s)</p>
            <form method='post' style='display:inline-block;'>
                <input type='hidden' name='edit_index' value='{$index}'>
                <button type='submit' class='btn'>Edit</button>
            </form>
            <form method='post' style='display:inline-block;'>
                <input type='hidden' name='delete_index' value='{$index}'>
                <button type='submit' class='btn red'>Delete</button>
            </form>
        </div>
        ";
    }
}
?>
