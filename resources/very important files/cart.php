<?php
include 'config.php';

$sql = "SELECT product_name, size, quantity, added_at FROM cart_items ORDER BY added_at DESC";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<h2>Coșul tău</h2>";
    echo "<table border='1'><tr><th>Produs</th><th>Mărime</th><th>Cantitate</th><th>Data</th></tr>";
    while ($row = $result->fetch_assoc()) {
        echo "<tr><td>" . $row["product_name"] . "</td><td>" . $row["size"] . "</td><td>" . $row["quantity"] . "</td><td>" . $row["added_at"] . "</td></tr>";
    }
    echo "</table>";
} else {
    echo "Coșul este gol.";
}
$conn->close();
?>