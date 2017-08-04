#!/bin/bash

v_username=$1
echo $v_username

#清mysql
#清wizard_user表
#drop database
#drop user
mysql -h'127.0.0.1' -uroot -pChenhd@443420 -Dmysql << !
delete from wizard_users where m_username = '$v_username';
drop database $v_username;
drop user $v_username;
!

#清linux用户
userdel -r -f $v_username;
