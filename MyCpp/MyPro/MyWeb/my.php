<?php
require dirname(__FILE__).'/vendor/autoload.php';
require dirname(__FILE__).'/ProcessMng.php';

function greet($name)
{
    $client = new ProcessMng\ProcessMngClient('localhost:54321', [
        'credentials' => Grpc\ChannelCredentials::createInsecure(),
    ]);
    $request = new ProcessMng\ProcessMngRequest();
    $request->setConditionid($name);
    list($reply, $status) = $client->BeginTask($request)->wait();
    echo $status;
    $message = $reply->getReturncode();

    return $message;
}

//$name = !empty($argv[1]) ? $argv[1] : 'world';
echo greet(15)."\n";
                          