<?php
mysql_connect($db_host, $db_user, $db_password);
mysql_select_db($dn_name);
$result = mysql_query("SELECT `name` FROM `users` WHERE `location` = '$location'");
while ($row = mysql_fetch_array($result, MYSQL_ASSOC))
{
    echo $row['name'];
}
mysql_free_result($result);
?>


<?php
$mysqli = new mysqli($db_host, $db_user, $db_password, $db_name);
$sql = "INSERT INTO `users` (id, name, gender, location) VALUES (?, ?, ?, ?)";
$stmt = $mysqli->prepare($sql);
$stmt->bind_param('dsss', $source_id, $source_name, $source_gender, $source_location);
$stmt->execute();
$stmt->bind_result($id, $name, $gender, $location);
while ($stmt->fetch())
{
    echo $id . $name . $gender . $location;
}
$stmt->close();
$mysqli->close();
?>

<?php
$dsn = "mysql:host=$db_host;dbname=$db_name";
$dbh = new PDO($dsn, $db_user, $db_password);
$sql = "SELECT `name`, `location` FROM `users` WHERE `location` = ? , `name` = ?";
$sth = $dbh->prepare($sql);
$sth->execute(array($location, $name));
$result = $sth->fetch(PDO::FETCH_OBJ);
echo $result->name . $result->location;
$dbh = NULL; //by www.jbxue.com
?>