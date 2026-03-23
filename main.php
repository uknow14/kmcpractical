<!-- 14.Write a program in PHP to find E = mgh +
1
2
mv2 using a function (give values directly in a program). -->

<html>
<head>
<title>Energy Calculator</title>
</head>
<body>

<?php
function findEnergy($m, $g, $h, $v) {
    $E = $m * $g * $h + 0.5 * $m * $v * $v;
    return $E;
}

$m = 5;
$g = 10;
$h = 3;
$v = 2;



$E = findEnergy($m, $g, $h, $v);
echo "Total Energy E = " . $E;
?>

</body>
</html>
<!-- ============================================================================= -->

<!-- 15.15. Write a program in PHP to send id, name and mark from a form to a web server and find whether a
student passed or failed. -->



<html>
<head>
<title>Student Result</title>
</head>
<body>

<h2>Student Form</h2>
<form method="post" action="">
    ID:   <input type="text" name="id"><br><br>
    Name: <input type="text" name="name"><br><br>
    Mark: <input type="text" name="mark"><br><br>
    <input type="submit" name="submit" value="Submit">
</form>

<?php
if (isset($_POST['submit'])) {
    $id   = $_POST['id'];
    $name = $_POST['name'];
    $mark = $_POST['mark'];

    echo "<br>ID: " . $id . "<br>";
    echo "Name: " . $name . "<br>";
    echo "Mark: " . $mark . "<br>";

    if ($mark >= 40) {
        echo $name . " has Passed!";
    } else {
        echo $name . " has Failed!";
    }
}
?>

</body>
</html>
<!-- ====================================================================================== -->

<!-- 16.Write a program in PHP to store create a database called KMC, a table named RESULT (having fields
id, name, mark) and store at least 1 record. -->

<html>
<head>
<title>Create Database</title>
</head>
<body>

<?php
$conn = mysqli_connect("localhost", "root", "");

if (!$conn) {
    die("Connection failed!");
}

$sql = "CREATE DATABASE IF NOT EXISTS KMC";

if (mysqli_query($conn, $sql)) {
    echo "Database KMC created successfully!";
} else {
    echo "Error: " . mysqli_error($conn);
}

mysqli_close($conn);
?>

</body>
</html>



<!-- LAST moment ko uestion haru -->

<html>
<body>

<?php
$conn = mysqli_connect("localhost","root","");

// check connection
if(!$conn) {
    die("Connection failed");
}

// create database
mysqli_query($conn,"CREATE DATABASE KMC");

// select database
mysqli_select_db($conn,"KMC");

// create table
mysqli_query($conn,"CREATE TABLE RESULT(
id INT,
name VARCHAR(50),
mark INT
)");

echo "Table created successfully";

?>

</body>
</html>
