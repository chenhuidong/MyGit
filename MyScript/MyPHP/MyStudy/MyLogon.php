<!DOCTYPE HTML> 
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body>

 <?php
// 定义变量并设置为空值
$nameErr = $passwordErr = "";
$name = $password = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
   if (empty($_POST["name"])) {
     $nameErr = "姓名是必填的";
   } else {
     $name = test_input($_POST["name"]);
     // 检查姓名是否包含字母和空白字符
     if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
       $nameErr = "只允许字母和空格"; 
     }
   }
   
   if (empty($_POST["password"])) {
     $passwordErr = "密码是必填的";
   } else {
     $password = test_input($_POST["password"]);
     // 检查姓名是否包含字母和空白字符
     if (!preg_match("/^[1-9]{6}$/",$password)) {
       $passwordErr = "请输入6个数字的密码"; 
     }
   }
   header("Location: http://121.42.27.147:7857/apache2_51linux_LxomB0aQ/Welcome.php");
}

function test_input($data) {
   $data = trim($data);
   $data = stripslashes($data);
   $data = htmlspecialchars($data);
   return $data;
}
?>

<h2>账单页面</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 
   姓名：<input type="text" name="name">
   <span class="error">* <?php echo $nameErr;?></span>
   <br><br>
   密码：<input type="password" name="password">
   <span class="error">* <?php echo $passwordErr;?></span>
   <br><br>
   <input type="submit" name="submit" value="提交"> 
</form>

</body>
</html>