#!/bin/bash

arch=$(uname -a)
cpu=$(lscpu | grep "Socket(s)" | awk '{print $2}')
vcpu=$(lscpu | grep "Processeur(s)" | awk '{print $2}')
total_mem=$(free -m | grep Mem | awk '{print $2}')
used_mem=$(free -m | grep Mem | awk '{print $3}')
mem_perc=$(free -m | grep Mem | awk '{print $3/$2 * 100}')
total_hdd=$(df -h --block-size=G --total | grep total | awk '{print $2}')
used_hdd=$(df -h --block-size=G --total | grep total | awk '{print $3}')
hdd_perc=$(df -h --block-size=G --total | grep total | awk '{print $3/$2 * 100}')
cpu_use=$(vmstat 1 1 | awk '/^ *[0-9]/ {print 100 - $15}')
reboot=$(uptime -s)
if lsblk | grep -q 'lvm'; then
	lvm="yes"
else
	lvm="no"
fi
connections=$(( $(ss -t state established | wc -l) - 1 ))
logged_users=$(who | wc -l)
ip=$(ip addr | grep enp | grep inet | awk '{print $2}' | awk -F'/' '{print $1}')
mac=$(ip addr | grep ether | awk '{print $2}')
sudo_count=$(find /var/log/sudo -type f -name log | wc -l)

message="#Architecture : $arch
#CPU physical : $cpu
#vCPU : $vcpu
#Memory Usage : ${used_mem}M/${total_mem}M ($mem_perc%)
#Disk Usage : $used_hdd/$total_hdd ($hdd_perc%)
#CPU Load : $cpu_use
#Last boot : $reboot
#LVM use : $lvm
#Connections TCP : $connections ESTABLISHED
#User log : $logged_users
#Network : IP $ip ($mac)
#Sudo : $sudo_count cmd"
echo "$message" | wall
