<?php
require dirname(__FILE__).'/vendor/autoload.php';
require dirname(__FILE__).'/ProcessMng.php';

function EndTask($name)
{
	$client = new ProcessMng\ProcessMngClient('localhost:54321', 
		['credentials' => Grpc\ChannelCredentials::createInsecure(),]);
	$request = new ProcessMng\ProcessMngRequest();	
    $request->setConditionid($name);
    list($reply, $status) = $client->EndTask($request)->wait();
    $returncode = $reply->getReturncode();
    return $returncode;
}

//$name = !empty($argv[1]) ? $argv[1] : 'world';
echo EndTask(15)."\n";
//echo EndTask(15)."\n";
                          