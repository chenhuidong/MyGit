<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
</head>
<body>

<p id="demo"></p>
<script>
var x = 'It\'s alright';
var y = "He is called \"Johnny\"";
document.getElementById("demo").innerHTML = x + "<br>" + y; 
</script>
<script>
var txt = "Hello World!";
document.write("<p>" + txt.length + "</p>");
var txt="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
document.write("<p>" + txt.length + "</p>");
</script>

<p id="demo1"></p>
<script>
var x = "John";              // x 是字符串
var y = new String("John");  // y 是一个对象
document.getElementById("demo1").innerHTML = x===y;
</script>
<p>=== 为绝对相等，即数据类型与值都必须相等。</p>

</body>
</html>