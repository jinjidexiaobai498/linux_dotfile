#!/bin/bash
#Author:LvXudong
#Time:2023 年 10月 07日 10时20分50秒
#Name:removeDeepin.sh
#Version:V1.0
#Description:This is a production script.

deepinList=`apt list --installed | grep deepin`
IFS=$'\n' 
for i in $deepinList ;
do
	apt remove ${i%%"/"*};
done


