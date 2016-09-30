<?php
	$arr = isset($_POST['arr']) ? $_POST['arr'] : '';
	if(empty($arr))
	{
		exit('error: no id');
	}
	else
	{
		$command = './MyFrame ' . escapeshellcmd($arr);
		$return = passthru($command);
		echo $return;
	}
?>