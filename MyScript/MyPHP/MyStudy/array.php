//索引数组
<?php
$cars=array("Volvo","BMW","SAAB");
echo "I like " . $cars[0] . ", " . $cars[1] . " and " . $cars[2] . ".";
?>


$cars=array("Volvo","BMW","SAAB");


//返回数组长度
<?php
$cars=array("Volvo","BMW","SAAB");
echo count($cars);
?>


<?php
$cars=array("Volvo","BMW","SAAB");
$arrlength=count($cars);

for($x=0;$x<$arrlength;$x++) {
  echo $cars[$x];
  echo "<br>";
}
?>

//关联数组
$age=array("Peter"=>"35","Ben"=>"37","Joe"=>"43");

<?php
$age=array("Bill"=>"35","Steve"=>"37","Peter"=>"43");
echo "Peter is " . $age['Peter'] . " years old.";
?>

<?php
$age=array("Bill"=>"35","Steve"=>"37","Peter"=>"43");

foreach($age as $x=>$x_value) {
  echo "Key=" . $x . ", Value=" . $x_value;
  echo "<br>";
}
?>



//sort() - 以升序对数组排序
//rsort() - 以降序对数组排序
//asort() - 根据值，以升序对关联数组进行排序
//ksort() - 根据键，以升序对关联数组进行排序
//arsort() - 根据值，以降序对关联数组进行排序
//krsort() - 根据键，以降序对关联数组进行排序
<?php
$numbers=array(3,5,1,22,11);
sort($numbers);
?>
