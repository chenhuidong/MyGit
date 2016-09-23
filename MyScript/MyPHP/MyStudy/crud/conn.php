<?php
/*
$conn = @mysqli_connect('127.0.0.1','chenhuidong','Chenhd@443420');
if (!$conn) {
	die('Could not connect: ' . mysql_error());
}
mysqli_select_db($conn, 'public');
*/
/*
$dsn = "mysql:host=localhost;dbname=public";
$pdo = new PDO($dsn, 'chenhuidong', 'Chenhd@443420');
$rs = $pdo -> query("select * from users"); 
while($row = $rs -> fetch()){ 
print_r($row); 
} 
*/
$conn=mysqli_connect("localhost","chenhuidong","Chenhd@443420","public");

// Check connection
if (mysqli_connect_errno($con))
{
echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
?>