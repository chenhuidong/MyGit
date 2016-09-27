<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>菜鸟教程(runoob.com)</title>
</head>
<body>

<p>该实例使用 addEventListener() 方法在按钮中添加点击事件。 </p>
<button id="myBtn">点我</button>
<p id="demo"></p>
<script>
document.getElementById("myBtn").addEventListener("click", displayDate);
function displayDate() {
    document.getElementById("demo").innerHTML = Date();
}
</script>


<p>该实例使用 addEventListener() 方法向同个按钮中添加两个点击事件。</p>
<button id="myBtn">点我</button>
<script>
var x = document.getElementById("myBtn");
x.addEventListener("click", myFunction);
x.addEventListener("click", someOtherFunction);
function myFunction() {
    alert ("Hello World!")
}
function someOtherFunction() {
    alert ("函数已执行!")
}
</script>



<p>实例使用 addEventListener() 方法在同一个按钮中添加多个事件。</p>
<button id="myBtn">点我</button>
<p id="demo"></p>
<script>
var x = document.getElementById("myBtn");
x.addEventListener("mouseover", myFunction);
x.addEventListener("click", mySecondFunction);
x.addEventListener("mouseout", myThirdFunction);
function myFunction() {
    document.getElementById("demo").innerHTML += "Moused over!<br>"
}
function mySecondFunction() {
    document.getElementById("demo").innerHTML += "Clicked!<br>"
}
function myThirdFunction() {
    document.getElementById("demo").innerHTML += "Moused out!<br>"
}
</script>

</body>
</html>