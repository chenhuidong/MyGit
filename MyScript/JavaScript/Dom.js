<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>菜鸟教程(runoob.com)</title>
</head>
<body>

<p id="intro">你好世界!</p>
<p>该实例展示了 <b>getElementById</b> 方法!</p>
<script>
x=document.getElementById("intro");
document.write("<p>文本来自 id 为 intro 段落: " + x.innerHTML + "</p>");
</script>


<p>你好世界!</p>
<div id="main">
<p> DOM 是非常有用的。</p>
<p>该实例展示了  <b>getElementsByTagName</b> 方法</p>
</div>
<script>
var x=document.getElementById("main");
var y=x.getElementsByTagName("p");
document.write('id="main"元素中的第一个段落为：' + y[0].innerHTML);
</script>


<p class="intro">你好世界!</p>
<p>该实例展示了 <b>getElementsByClassName</b> 方法!</p>
<script>
x=document.getElementsByClassName("intro");
document.write("<p>文本来自 class 为 intro 段落: " + x[0].innerHTML + "</p>");
</script>

</body>
</html>