#! /bin/bash
########################################################
# Filename: ./exec_files.sh
# Date: 2014-10-14 13:22:00
# Author: chenhuidong
# Email: chdyczx@live.com
# Note: 
########################################################

usage()
{
	echo "usage:"
	echo "	./exec_files.sh -all"
	echo "	exec files in usrlist.conf s filelist.conf "
	echo ""
}

remote_cmd()
{
	expect << EOF
	spawn ssh $2@$1 "$4"
	expect {
    "*password:" {
        	send "$3\n";exp_continue
        }
    eof {
        	exit
        }
}
EOF
}

exec_file()
{
	filename=./usrlist.conf
	filename2=./filelist.conf
	
	if [ ! -f $filename -o ! -f $filename2 ]
	then
		echo "File $filename or $filename2 is not exist."
		echo ""
		usage
		exit 1
	fi
	
	cat $filename | while read line
	do
		v_ip=`echo $line | awk -F " " '{print $1}'`
		v_user=`echo $line | awk -F " " '{print $2}'`
		v_passwd=`echo $line | awk -F " " '{print $3}'`
		echo $v_ip,$v_user,$v_passwd
		cat $filename2 | while read line2
		do
			v_srcname=`echo $line2`
			remote_cmd $v_ip $v_user $v_passwd "sh $v_srcname"
		done
	done
}

main()
{
if [ $# -eq 0 ] || [ $1 == "--help" ] || [ $1 == "-h" ]
then
	usage
	exit 1
elif [ $1=="-all" ]
then
	exec_file
else
	usage
	exit 1
fi

}

main $*

exit 0
