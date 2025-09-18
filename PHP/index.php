<?php
/* 
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/

require_once "Laptop.php"; // Import the Laptop class definition

// Uncomment these two lines if you want to reset/clear the session data
// session_start();
// session_destroy();

session_start(); // Start a new session or resume an existing one

// Initialize session data with some default laptops (only if session is empty)
if (!isset($_SESSION['laptops'])) {
    $_SESSION['laptops'] = [
        new Laptop(1, "XPS 13", "Dell", "Silver", 15000000, 2, "XPS%2013.jpg"),
        new Laptop(2, "MacBook Air", "Apple", "Space Gray", 18000000, 1, "macbook%20air.jpeg"),
        new Laptop(3, "ThinkPad X1", "Lenovo", "Black", 20000000, 3, "thinkpad%20X1.png")
    ];
}

// --- Add new laptop ---
if (isset($_POST['add'])) {
    $id = time(); // Generate unique ID based on current timestamp
    $name = $_POST['name'];
    $brand = $_POST['brand'];
    $color = $_POST['color'];
    $price = $_POST['price'];
    $warranty = $_POST['warranty'];

    $imageName = "";
    // Handle uploaded image if provided
    if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
        if (!is_dir("uploads")) mkdir("uploads"); // Create uploads folder if not exists
        $imageName = uniqid() . "_" . basename($_FILES["image"]["name"]);
        move_uploaded_file($_FILES["image"]["tmp_name"], "uploads/" . $imageName);
    }

    // Add new laptop object into session
    $_SESSION['laptops'][] = new Laptop($id, $name, $brand, $color, $price, $warranty, $imageName);
    header("Location: index.php"); // Redirect to refresh page
    exit;
}

// --- Delete laptop ---
if (isset($_POST['delete_index'])) {
    $index = $_POST['delete_index'];
    if (isset($_SESSION['laptops'][$index])) {
        unset($_SESSION['laptops'][$index]);              // Remove element
        $_SESSION['laptops'] = array_values($_SESSION['laptops']); // Re-index array
    }
    header("Location: index.php");
    exit;
}

// --- Edit laptop ---
$editMode = false; // Flag to check if editing mode is active
$editIndex = -1;   // Store index of laptop being edited

// If edit button is clicked, set edit mode
if (isset($_POST['edit_index'])) {
    $editMode = true;
    $editIndex = $_POST['edit_index'];
}

// Handle update submission
if (isset($_POST['update'])) {
    $index = $_POST['update_index'];
    if (isset($_SESSION['laptops'][$index])) {
        // Update fields with new values via setters
        $_SESSION['laptops'][$index]->setName($_POST['name']);
        $_SESSION['laptops'][$index]->setBrand($_POST['brand']);
        $_SESSION['laptops'][$index]->setColor($_POST['color']);
        $_SESSION['laptops'][$index]->setPrice($_POST['price']);
        $_SESSION['laptops'][$index]->setWarranty($_POST['warranty']);

        // Handle updated image if provided
        if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
            $imageName = uniqid() . "_" . basename($_FILES["image"]["name"]);
            move_uploaded_file($_FILES["image"]["tmp_name"], "uploads/" . $imageName);
            $_SESSION['laptops'][$index]->setImage($imageName);
        }
    }
    header("Location: index.php");
    exit;
}

// Store current session laptops
$laptops = $_SESSION['laptops'];

// --- Search feature ---
$searchQuery = "";
if (isset($_GET['search'])) {
    $searchQuery = strtolower(trim($_GET['search'])); // Normalize search input
    // Filter laptops based on name or brand
    $laptops = array_filter($_SESSION['laptops'], function($laptop) use ($searchQuery) {
        return strpos(strtolower($laptop->getName()), $searchQuery) !== false ||
               strpos(strtolower($laptop->getBrand()), $searchQuery) !== false;
    });
}

?>
<!DOCTYPE html>
<html>
<head>
    <title>Laptop Store</title>
    <style>
        /* Basic styling for layout, cards, forms, and buttons */
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

        /* Search box styling */
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

    <!-- Form for adding/updating laptop -->
    <div class="form-container">
        <h2><?php echo $editMode ? "Edit Laptop" : "Add New Laptop"; ?></h2>
        <form method="post" enctype="multipart/form-data">
            <input type="text" name="name" placeholder="Name" 
                value="<?php echo $editMode ? $laptops[$editIndex]->getName() : ''; ?>" required><br>
            <input type="text" name="brand" placeholder="Brand" 
                value="<?php echo $editMode ? $laptops[$editIndex]->getBrand() : ''; ?>" required><br>
            <input type="text" name="color" placeholder="Color" 
                value="<?php echo $editMode ? $laptops[$editIndex]->getColor() : ''; ?>" required><br>
            <input type="number" name="price" placeholder="Price" 
                value="<?php echo $editMode ? $laptops[$editIndex]->getPrice() : ''; ?>" required><br>
            <input type="number" name="warranty" placeholder="Warranty (years)" 
                value="<?php echo $editMode ? $laptops[$editIndex]->getWarranty() : ''; ?>" required><br>
            <input type="file" name="image" accept="image/*"><br>

            <?php if ($editMode): ?>
                <!-- Update mode -->
                <input type="hidden" name="update_index" value="<?php echo $editIndex; ?>">
                <button type="submit" name="update" class="btn">Update</button>
                <a href="index.php" class="btn red">Cancel</a>
            <?php else: ?>
                <!-- Add mode -->
                <button type="submit" name="add" class="btn">Add</button>
            <?php endif; ?>
        </form>
    </div>

    <!-- Search form -->
    <div class="search-box">
        <form method="get">
            <input type="text" name="search" placeholder="Search by name or brand" value="<?php echo htmlspecialchars($searchQuery); ?>">
            <button type="submit">Search</button>
        </form>
    </div>

    <!-- Display all laptops -->
    <h2>All Laptops</h2>
    <div class="container">
        <?php
        if (empty($laptops)) {
            echo "<p>No laptops available.</p>";
        } else {
            foreach ($laptops as $index => $laptop) {
                // Display each laptop as a card (method from Laptop class)
                $laptop->displayCard($index);
            }
        }
        ?>
    </div>
</body>
</html>
