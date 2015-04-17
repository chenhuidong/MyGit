#! /bin/bash

v_users=`last | awk '{print $1 $3}' | grep -v root | grep -v wtmp | grep -v reboot | grep -v chdyczx`

if [ ! -n "$v_users" ];
then
    echo `date +%Y%m%d`" is null"
    exit 0
fi

for v_user in $v_users
do
    echo $v_user
done


