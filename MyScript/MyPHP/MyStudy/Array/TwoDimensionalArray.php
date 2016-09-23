<!DOCTYPE html>
<html>
<body>

<?php
$cars = array
   (
   array("Volvo",33,20),
   array("BMW",17,15),
   array("Saab",5,2),
   array("Land Rover",15,11)
   );
   
echo $cars[0][0].": 库存：".$cars[0][1].", 已售：".$cars[0][2].".<br>";
echo $cars[1][0].": 库存：".$cars[1][1].", 已售：".$cars[1][2].".<br>";
echo $cars[2][0].": 库存：".$cars[2][1].", 已售：".$cars[2][2].".<br>";
echo $cars[3][0].": 库存：".$cars[3][1].", 已售：".$cars[3][2].".<br>";
?>

</body>
</html>


//for
<!DOCTYPE html>
<html>
<body>

<?php
$cars = array
   (
   array("Volvo",33,20),
   array("BMW",17,15),
   array("Saab",5,2),
   array("Land Rover",15,11)
   );
   
for ($row = 0; $row <  4; $row++) {
   echo "<p><b>行数 $row</b></p>";
   echo "<ul>";
   for ($col = 0; $col <  3; $col++) {
     echo "<li>".$cars[$row][$col]."</li>";
   }
   echo "</ul>";
}
?>

</body>
</html>