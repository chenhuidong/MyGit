<!DOCTYPE html>
<html>
<body>

<?php
echo "今天是 " . date("Y/m/d") . "<br>";
echo "今天是 " . date("Y.m.d") . "<br>";
echo "今天是 " . date("Y-m-d") . "<br>";
echo "今天是 " . date("l");
?>

</body>
</html>

//版权年份
<!DOCTYPE html>
<html>
<body>

版权所有 2008-<?php echo date("Y")?>

</body>
</html>

<!DOCTYPE html>
<html>
<body>

<?php
echo "当前时间是 " . date("h:i:sa");
?>

</body>
</html>

//时区
<!DOCTYPE html>
<html>
<body>

<?php
date_default_timezone_set("Asia/Shanghai");
echo "当前时间是 " . date("h:i:sa");
?>

</body>
</html>

//创建时间
<!DOCTYPE html>
<html>
<body>

<?php
$d=mktime(9, 12, 31, 6, 10, 2015);
echo "创建日期是 " . date("Y-m-d h:i:sa", $d);
?>

</body>
</html>

//strtotime创建时间
<!DOCTYPE html>
<html>
<body>

<?php
$d=strtotime("10:38pm April 15 2015");
echo "创建日期 " . date("Y-m-d h:i:sa", $d);
?>

</body>
</html>


<!DOCTYPE html>
<html>
<body>

<?php
$d=strtotime("tomorrow");
echo date("Y-m-d h:i:sa", $d) . "<br>";

$d=strtotime("next Saturday");
echo date("Y-m-d h:i:sa", $d) . "<br>";

$d=strtotime("+3 Months");
echo date("Y-m-d h:i:sa", $d) . "<br>";
?>

</body>
</html>

//下周六日期
<!DOCTYPE html>
<html>
<body>

<?php
$startdate=strtotime("Saturday");
$enddate=strtotime("+6 weeks",$startdate);

while ($startdate <  $enddate) {
   echo date("M d", $startdate),"<br>";
   $startdate = strtotime("+1 week", $startdate);
}
?>

</body>
</html>


//日期之前的天数
<!DOCTYPE html>
<html>
<body>

<?php
$d1=strtotime("December 31");
$d2=ceil(($d1-time())/60/60/24);
echo "距离十二月三十一日还有：" . $d2 ." 天。";
?>

</body>
</html>