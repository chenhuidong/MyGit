#! /bin/bash

shopt -s expand_aliases
source /mnt/home2/51linux_LxomB0aQ/.bashrc

usage()
{
    echo "usage:"
    echo "  mymanage.sh -a database user passwd"
    echo "  mymanage.sh -d database user passwd"
    exit 0;
}

#删除数据库用户及实例
deleteuser()
{
#主机uid
hid=`id -u`
#主机用户名
huser=`whoami`

#验证用户名密码是否正确
vuser=`mr << ! | sed '1d'
select user from user where user = '$3' and password = PASSWORD('$4');
!`

#用户密码不匹配
if [ ! $vuser ]
then
    echo
    echo "your password is wrong."
    echo "exit."
    echo
    exit 1;
fi

#验证主机uid user 数据库用户 及数据库实例 
vhid=`mr << ! | sed '1d'
select hid from userdatabaserel where hid = '$hid' and huser = '$huser' and duser = '$3' and dbname = '$2';
!`

#用户名数据库实例等不匹配
if [ ! $vhid ]
then
    echo
    echo "you can not drop this database."
    echo "exit."
    echo
    exit 1;
fi

#删除数据库用户及数据库实例
mr << !
drop user $3;
drop database $2;
delete from userdatabaserel where hid = '$hid' and huser = '$huser' and duser = '$3' and dbname = '$2';
!

echo
echo "droped success."
echo
exit 0;
}

#增加数据库用户及实例
adduser()
{
hid=`id -u`
huser=`whoami`

#验证用户是否已创建过数据库实例
vhid=`mr << ! | sed '1d'
select hid from userdatabaserel where hid = $hid;
!`

#已创建退出
if [ $vhid ]
then
    echo
    echo "forbidden! you have registered before."
    echo "exit."
    echo
    exit 1;
fi

#创建数据库用户及实例并赋权
mr << !
create database $2;
CREATE USER $3@'%' IDENTIFIED BY '$4';
grant all on $2.*  to $3;
insert into userdatabaserel(hid, huser, duser, dbname) values ($hid, '$huser', '$3', '$2');
!

echo
echo "registered success."
echo
exit 0;
}

main()
{
    if [ $# -ne 4 ] || [ "$1" == "--help" ] || [ "$1" == "-h" ]
    then
            usage
            exit
    elif [ "$1" == "-a" ]
    then
            adduser $*
    elif [ "$1" == "-d" ]
    then
            deleteuser $*
    else
            usage
            exit
    fi
}

main $*

exit 0

