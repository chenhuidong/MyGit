#! /bin/bash

usage()
{
    echo "usage:"
    echo "  beign all: init.sh -b"
    echo "  stop_all: init.sh -s"
    exit 0;
}

begin_all()
{
	#start mysql
	nohup mysqld_safe --defaults-file=/mnt/home2/51linux_LxomB0aQ/usr/lib/mysql/mysqlcnf/my-small.cnf --log-bin &

	#start php-cgi
	#php-cgi -b 127.0.0.1:54323 &

	#start nginx
	nginx -p /mnt/home2/51linux_LxomB0aQ/usr/lib/nginx/

	exit 0;
}

stop_all()
{
	#stop mysql
	mysqladmin -h'121.42.27.147' -umysql -P54321 -pChenhd@443420 shutdown

	#stop php-cgi
	#stop nginx
	nginx -s stop -p /mnt/home2/51linux_LxomB0aQ/usr/lib/nginx/
	exit 0;
}
main()
{
    if [ $# -ne 1 ] || [ "$1" == "--help" ] || [ "$1" == "-h" ]
    then
            usage
            exit
    elif [ "$1" == "-b" ]
    then
            begin_all $*
    elif [ "$1" == "-s" ]
    then
            stop_all $*
    else
            usage
            exit
    fi
}

main $*

exit 0