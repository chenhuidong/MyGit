<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"> 
<HTML> 
<HEAD> 
<TITLE> PEAR::HTML_QuickForm </TITLE> 
<META NAME="Generator" CONTENT="EditPlus"> 
<META NAME="Author" CONTENT="Haohappy"> 
</HEAD> 
<BODY> 
<? 
require_once("HTML/QuickForm.php");
//建立一个表单对象
$form = new HTML_QuickForm('frmTest', 'post');
 
/*利用该对象的addElement方法增加四个表单元素
addElemment()的三个参数分别表示类型、名称、显示的文字。
*/
$form->addElement('header', 'header', '请登录'); 
$form->addElement('text', 'name', '用户名：'); 
$form->addElement('password', 'password', '密码：'); 
$form->addElement('submit', 'submit', '提交'); 

//输出到浏览器
$form->display(); 
?>      
</BODY> 
</HTML>