#! /bin/bash

shopt -s expand_aliases
source $HOME/.bashrc
date

main()
{
	#备份
	mysqldump -h'121.42.27.147' -uroot -p111111 -P54321  --all-databases > $WORKPATH2/bak/all_`date +%Y%m%d`.sql

	#删除30天前文件
	find $WORKPATH2/bak -type f -name "all*.sql" -ctime 30 -exec rm {} \; 
}

main $*

exit 0

