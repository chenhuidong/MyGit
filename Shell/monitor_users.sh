#! /bin/bash

v_users=`last | awk '{print $1}' | grep -v root | grep -v wtmp | grep -v chdyczx`

for v_user in $v_users
do
    echo $v_user
done


