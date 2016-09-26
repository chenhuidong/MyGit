<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
</head>
<body>

<p>本例调用的函数会执行一个计算，然后返回结果：</p>
<p id="demo"></p>
<script>
function myFunction(a,b){
	return a*b;
}
document.getElementById("demo").innerHTML=myFunction(4,3);
</script>

<p>函数可以存储在变量中:</p>
<p id="demo"></p>
<script>
var x = function (a, b) {return a * b};
document.getElementById("demo").innerHTML = x;
</script>

<p>函数存储在变量后，变量可作为函数使用：</p>
<p id="demo"></p>
<script>
var x = function (a, b) {return a * b};
document.getElementById("demo").innerHTML = x(4, 3);
</script>

<p>JavaScrip 内置构造函数。</p>
<p id="demo"></p>
<script>
var myFunction = new Function("a", "b", "return a * b");
document.getElementById("demo").innerHTML = myFunction(4, 3);
</script>

<p id="demo"></p>
<script>
var myFunction = function (a, b) {return a * b}
document.getElementById("demo").innerHTML = myFunction(4, 3);
</script>

</body>
</html>