<?php
class Laptop {
    public $id;
    public $name;
    public $brand;
    public $color;
    public $price;
    public $warranty;
    public $image;

    public function __construct($id, $name, $brand, $color, $price, $warranty, $image) {
        $this->id = $id;
        $this->name = $name;
        $this->brand = $brand;
        $this->color = $color;
        $this->price = $price;
        $this->warranty = $warranty;
        $this->image = $image;
    }

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
