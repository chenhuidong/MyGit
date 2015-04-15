#! /bin/bash
########################################################
# Filename: ./fast_trust.sdl
# Date: 2014-10-14 13:22:00
# Author: chenhuidong
# Email: chdyczx@live.com
# Note: 
########################################################

useage()
{
	echo "useage: fast_trust.sh --help or -h for help"
	echo "	fast_trust.sh -all for add all users trust relationship in usrlist.conf"
	echo "	fast_trust.sh -add for add users in addlist.conf with others in usrlist.conf"
	echo "	fast_trust.sh -pp ip1 user1 passwd1 ip2 user2 passwd2 for add one user with another"
	echo "	fast_trust.sh -rm for remove all users authorized_keys in usrlist.conf"
	echo ""
}

#生成公私钥对
key_gen()
{
expect << EOF
spawn ssh $2@$1 ssh-keygen -t rsa
while 1 {
	expect {
  	"*password:" {
    	send "$3\n"
    }
    "yes/no*" {
      send "yes\n"
    }
    "Enter file in which to save the key*" {
    	send "\n"
    }
    "Enter passphrase*" {
    	send "\n"
    }
    "Enter same passphrase again:" {
      send "\n"
    }

    "Overwrite (y/n)" {
    		send "n\n"
     }
     eof {
        exit
    }
  }
}
EOF
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

construct_trust_rel()
{
	if	(($#!=6)); then
		echo "Please input right params:construct_trust ip1 user1 passwd1 ip2 user2 passwd2"  
		useage
		exit 1
	fi
	
	tmp_path=/home/chdyczx
	remote1_path="/home/$2"
	remote2_path="/home/$5"
	
	#tmp目录新建
	if [ ! -d $tmp_path ]
	then 
		mkdir $tmp_path
	fi

	#生成主机1id_rsa
	key_gen $1 $2 $3
	#生成主机2id_rsas
	key_gen $4 $5 $6
	
	#获取主机1
	trans_file "$2@$1:$remote1_path/.ssh/id_rsa.pub $tmp_path/tmp1" "$3"
	
	#获取主机2
	trans_file "$5@$4:$remote2_path/.ssh/id_rsa.pub $tmp_path/tmp2" "$6"
	
	#放置主机1
	trans_file "$tmp_path/tmp2 $2@$1:$remote1_path/.ssh/authorized_keys_tmp" "$3"
	remote_cmd "$1" "$2" "$3" "cat $remote1_path/.ssh/authorized_keys_tmp >> $remote1_path/.ssh/authorized_keys; rm $remote1_path/.ssh/authorized_keys_tmp;"
	
	#放置主机2
	trans_file "$tmp_path/tmp1 $5@$4:$remote2_path/.ssh/authorized_keys_tmp" "$6"
	remote_cmd "$4" "$5" "$6" "cat $remote2_path/.ssh/authorized_keys_tmp >> $remote2_path/.ssh/authorized_keys; rm $remote2_path/.ssh/authorized_keys_tmp;"
	
	#清除tmp
	rm -rf $tmp_path/tmp1 $tmp_path/tmp2
}


construct_trust_all()
{
	v_count=1
	
	if [ ! -f $1 ]
	then
		echo "File $1 is not exist."
		echo ""
		useage
		exit 1
	fi
	
	sed '$d' $1 | while read line
	do
	 	v_ip1=`echo $line | awk -F " " '{print $1}'`
		v_user1=`echo $line | awk -F " " '{print $2}'`
		v_passwd1=`echo $line | awk -F " " '{print $3}'`
		((v_count++))
		
		sed -n ''$v_count', $ p' $1 | while read line2
		do
			v_ip2=`echo $line2 | awk -F " " '{print $1}'`
			v_user2=`echo $line2 | awk -F " " '{print $2}'`
			v_passwd2=`echo $line2 | awk -F " " '{print $3}'`
			echo $v_ip1,$v_user1,$v_ip2,$v_user2
			construct_trust_rel $v_ip1 $v_user1 $v_passwd1 $v_ip2 $v_user2 $v_passwd2
		done
	done
}

add_users_trust()
{
	filenameres=./usrlist.conf
	filenameadd=./addlist.conf
	
	if [ ! -f $filenameres ] || [ ! -f $filenameadd ]
	then
		echo "File usrlist.conf or addlist.conf is not exist."
		echo ""
		useage
		exit 1
	fi
	
	cat $filenameadd | while read line
	do
	 	v_ip1=`echo $line | awk -F " " '{print $1}'`
		v_user1=`echo $line | awk -F " " '{print $2}'`
		v_passwd1=`echo $line | awk -F " " '{print $3}'`
		
		cat $filenameres | while read line2
		do
			v_ip2=`echo $line2 | awk -F " " '{print $1}'`
			v_user2=`echo $line2 | awk -F " " '{print $2}'`
			v_passwd2=`echo $line2 | awk -F " " '{print $3}'`
			echo $v_ip1,$v_user1,$v_ip2,$v_user2
			construct_trust_rel $v_ip1 $v_user1 $v_passwd1 $v_ip2 $v_user2 $v_passwd2
		done
	done
	cat $filenameadd >> $filenameres 
	echo "" > $filenameadd
}

remove_authorized_keys()
{
	if [ ! -f $1 ]
	then
		echo "File $1 is not exist."
		echo ""
		useage
		exit 1
	fi
	
	cat $1 | while read line
	do
	 	v_ip=`echo $line | awk -F " " '{print $1}'`
		v_user=`echo $line | awk -F " " '{print $2}'`
		v_passwd=`echo $line | awk -F " " '{print $3}'`
		remote_path="/home/$v_user"
		remote_cmd "$v_ip" "$v_user" "$v_passwd" "rm $remote_path/.ssh/authorized_keys;"
	done
}

main()
{
	if [ $# -eq 0 ] || [ $1 == "--help" ] || [ $1 == "-h" ]
	then
		useage
	elif [ $1 == "-all" ]
	then
		filename=./usrlist.conf
		construct_trust_all $filename
	elif [ $1 == "-add" ]
	then
		filename=./addlist.conf
		construct_trust_all $filename
		add_users_trust
	elif [ $1 == "-pp" ]
	then
		construct_trust_rel $2 $3 $4 $5 $6 $7
	elif [ $1 == "-rm" ]
	then
		filename=./usrlist.conf
		remove_authorized_keys $filename 
	else
		useage
	fi
}

main $*

exit 0
