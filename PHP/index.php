<?php

require_once "Laptop.php"; // import class Laptop

session_start();

session_destroy();
session_start();
if (!isset($_SESSION['laptops'])) {
    $_SESSION['laptops'] = [
        new Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2, "XPS 13.jpg"),
        new Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1, "macbook air.jpeg"),
        new Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3, "thinkpad X1.png")
    ];
}

// Tambah laptop
if (isset($_POST['add'])) {
    $id = time();
    $name = $_POST['name'];
    $brand = $_POST['brand'];
    $color = $_POST['color'];
    $price = $_POST['price'];
    $warranty = $_POST['warranty'];

    $imageName = "";
    if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
        if (!is_dir("uploads")) mkdir("uploads");
        $imageName = uniqid() . "_" . basename($_FILES["image"]["name"]);
        move_uploaded_file($_FILES["image"]["tmp_name"], "uploads/" . $imageName);
    }

    $_SESSION['laptops'][] = new Laptop($id, $name, $brand, $color, $price, $warranty, $imageName);
    header("Location: index.php");
    exit;
}

// Hapus laptop
if (isset($_POST['delete_index'])) {
    $index = $_POST['delete_index'];
    if (isset($_SESSION['laptops'][$index])) {
        unset($_SESSION['laptops'][$index]);
        $_SESSION['laptops'] = array_values($_SESSION['laptops']);
    }
    header("Location: index.php");
    exit;
}

// Edit laptop
$editMode = false;
$editIndex = -1;
if (isset($_POST['edit_index'])) {
    $editMode = true;
    $editIndex = $_POST['edit_index'];
}
if (isset($_POST['update'])) {
    $index = $_POST['update_index'];
    if (isset($_SESSION['laptops'][$index])) {
        $_SESSION['laptops'][$index]->name = $_POST['name'];
        $_SESSION['laptops'][$index]->brand = $_POST['brand'];
        $_SESSION['laptops'][$index]->color = $_POST['color'];
        $_SESSION['laptops'][$index]->price = $_POST['price'];
        $_SESSION['laptops'][$index]->warranty = $_POST['warranty'];

        if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
            $imageName = uniqid() . "_" . basename($_FILES["image"]["name"]);
            move_uploaded_file($_FILES["image"]["tmp_name"], "uploads/" . $imageName);
            $_SESSION['laptops'][$index]->image = $imageName;
        }
    }
    header("Location: index.php");
    exit;
}

// Fitur search
$searchQuery = "";
if (isset($_GET['search'])) {
    $searchQuery = strtolower(trim($_GET['search']));
    $laptops = array_filter($_SESSION['laptops'], function($laptop) use ($searchQuery) {
        return strpos(strtolower($laptop->name), $searchQuery) !== false ||
               strpos(strtolower($laptop->brand), $searchQuery) !== false;
    });
}

$laptops = $_SESSION['laptops'];
?>
<!DOCTYPE html>
<html>
<head>
    <title>Laptop Store</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f4f4f9;
            padding: 20px;
            text-align: center;
        }
        h1 {
            margin-bottom: 20px;
        }
        .container {
            display: flex;
            flex-wrap: wrap;
            gap: 20px;
            justify-content: center;
        }
        .card {
            background: white;
            padding: 15px;
            border-radius: 10px;
            box-shadow: 0 2px 5px rgba(0,0,0,0.2);
            width: 200px;
        }
        .card img {
            max-width: 100%;
            border-radius: 5px;
        }
        .btn {
            display: inline-block;
            margin: 5px;
            padding: 8px 12px;
            text-decoration: none;
            background: #4CAF50;
            color: white;
            border-radius: 5px;
            border: none;
            cursor: pointer;
        }
        .btn.red {
            background: #e74c3c;
        }
        .form-container {
            background: white;
            padding: 20px;
            margin: 20px auto;
            width: 300px;
            border-radius: 10px;
            box-shadow: 0 2px 5px rgba(0,0,0,0.2);
        }
        input {
            width: 90%;
            padding: 8px;
            margin: 8px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
        }

        .search-box {
        margin: 20px 0;
        text-align: center;
    }

        .search-box input[type="text"] {
            padding: 10px 15px;
            width: 250px;
            border: 1px solid #ccc;
            border-radius: 20px;
            outline: none;
            transition: all 0.3s ease;
        }

        .search-box input[type="text"]:focus {
            border-color: #007bff;
            box-shadow: 0 0 5px rgba(0, 123, 255, 0.5);
        }

        .search-box button {
            padding: 10px 20px;
            margin-left: 8px;
            background-color: #007bff;
            border: none;
            color: white;
            border-radius: 20px;
            cursor: pointer;
            font-weight: bold;
            transition: background-color 0.3s ease, transform 0.2s ease;
        }

        .search-box button:hover {
            background-color: #0056b3;
            transform: scale(1.05);
        }
    </style>
</head>
<body>
    <h1>Laptop Store</h1>

    <div class="form-container">
        <h2><?php echo $editMode ? "Edit Laptop" : "Add New Laptop"; ?></h2>
        <form method="post" enctype="multipart/form-data">
            <input type="text" name="name" placeholder="Name" 
                value="<?php echo $editMode ? $laptops[$editIndex]->name : ''; ?>" required><br>
            <input type="text" name="brand" placeholder="Brand" 
                value="<?php echo $editMode ? $laptops[$editIndex]->brand : ''; ?>" required><br>
            <input type="text" name="color" placeholder="Color" 
                value="<?php echo $editMode ? $laptops[$editIndex]->color : ''; ?>" required><br>
            <input type="number" name="price" placeholder="Price" 
                value="<?php echo $editMode ? $laptops[$editIndex]->price : ''; ?>" required><br>
            <input type="number" name="warranty" placeholder="Warranty (years)" 
                value="<?php echo $editMode ? $laptops[$editIndex]->warranty : ''; ?>" required><br>
            <input type="file" name="image" accept="image/*"><br>

            <?php if ($editMode): ?>
                <input type="hidden" name="update_index" value="<?php echo $editIndex; ?>">
                <button type="submit" name="update" class="btn">Update</button>
                <a href="index.php" class="btn red">Cancel</a>
            <?php else: ?>
                <button type="submit" name="add" class="btn">Add</button>
            <?php endif; ?>
        </form>
    </div>

    <!-- Search -->
    <div class="search-box">
        <form method="get">
            <input type="text" name="search" placeholder="Search by name or brand" value="<?php echo htmlspecialchars($searchQuery); ?>">
            <button type="submit">Search</button>
        </form>
    </div>

    <h2>All Laptops</h2>
    <div class="container">
        <?php
        if (empty($laptops)) {
            echo "<p>No laptops available.</p>";
        } else {
            foreach ($laptops as $index => $laptop) {
                $laptop->displayCard($index);
            }
        }
        ?>
    </div>
</body>
</html>
