<?php
/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

/**
 * Laptop class definition
 * This class models a Laptop object with properties and a method
 * to render its information inside a styled HTML card.
 */
class Laptop {
    // --- Attributes ---
    public $id;        // Unique identifier
    public $name;      // Laptop name
    public $brand;     // Laptop brand
    public $color;     // Laptop color
    public $price;     // Laptop price (in Rupiah)
    public $warranty;  // Warranty period (in years)
    public $image;     // Image filename (stored in uploads/)

    /**
     * Constructor
     * Initializes a Laptop object with the given attributes.
     */
    public function __construct($id, $name, $brand, $color, $price, $warranty, $image) {
        $this->id = $id;
        $this->name = $name;
        $this->brand = $brand;
        $this->color = $color;
        $this->price = $price;
        $this->warranty = $warranty;
        $this->image = $image;
    }

    /**
     * Display the laptop as an HTML card.
     * Includes an image, details, and action buttons (Edit/Delete).
     */
    public function displayCard() {
        echo "
        <div class='card'>
            <img src='uploads/{$this->image}' alt='{$this->name}' />
            <h3>{$this->name}</h3>
            <p><b>Brand:</b> {$this->brand}</p>
            <p><b>Color:</b> {$this->color}</p>
            <p><b>Price:</b> Rp {$this->price}</p>
            <p><b>Warranty:</b> {$this->warranty} year(s)</p>
            <a href='edit.php?id={$this->id}' class='btn'>Edit</a>
            <a href='delete.php?id={$this->id}' class='btn red'>Delete</a>
        </div>
        ";
    }
}
?>
