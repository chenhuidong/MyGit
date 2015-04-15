#! /bin/bash

#¼ìÍÂt½Ó&ftpÉ´«Ê¾Ý 
function networkAndFtp()   
{  
    #³¬ʱʱ¼ä
    timeout=5  
       
    #Ŀ±êվ  
    target=www.baidu.com  
   
    #»ñì״̬Â  
    ret_code=`curl -I -s --connect-timeout $timeout $target -w %{http_code} | tail -n1`  
   
    if [ "x$ret_code" = "x200" ]; 
    then  
        #ÍÂ³©ͨ
	echo "OK"		
    else  
        #ÍÂ²»³©ͨ 		
	#sudo /etc/init.d/networking restart
	echo "NO"		
    fi  
}

main()
{
    networkAndFtp
}

main
