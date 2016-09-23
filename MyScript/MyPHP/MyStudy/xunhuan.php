<?php 
$x=1; 

while($x<=5) {
  echo "这个数字是：$x <br>";
  $x++;
} 
?>

<?php 
$x=1; 

do {
  echo "这个数字是：$x <br>";
  $x++;
} while ($x<=5);
?>

<?php 
for ($x=0; $x<=10; $x++) {
  echo "数字是：$x <br>";
} 
?>

<?php 
$colors = array("red","green","blue","yellow"); 

foreach ($colors as $value) {
  echo "$value <br>";
}
?>