#! /bin/bash
########################################################
# Filename: ./dispatch_files.sdl
# Date: 2014-10-14 13:22:00
# Author: chenhuidong
# Email: chdyczx@live.com
# Note: 
########################################################

usage()
{
	echo "usage:"
	echo "	./dispatch_files.sh"
	echo "	dispatch files to users in translist.conf "
	echo "	translist.conf line format is ip user passwd"
	echo "	filelist.conf contains sourcepath and remote destpath"
	echo "	filelist.conf line format is sourcepath destpath"
	echo ""
}

trans_file()
{
expect << EOF
spawn scp $1
expect {
    "*password:" {
        	send "$2\n";exp_continue
        }
    eof {
        	exit
        }
}
EOF
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

dispatch_file()
{
	filename=./translist.conf
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
			v_srcname=`echo $line2 | awk -F " " '{print $1}'`
			v_destname=`echo $line2 | awk -F " " '{print $2}'`	
			
			v_dirname=`dirname $v_destname`
			echo "$v_dirname"
			remote_cmd $v_ip $v_user $v_passwd "mkdir -p $v_dirname"
			trans_file "$v_srcname $v_user@$v_ip:$v_destname" "$v_passwd"
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
	dispatch_file
else
	usage
	exit 1
fi

}

main $*

exit 0
