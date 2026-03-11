*This project has been created as part of the 42 curriculum by **phsottat***

# Description

This project is about creating Debian based server without GUI and with minimal dependency by using Oracle Virtual Box LVM.

## Software Tool comparison

When to use Debian ?
*	Use Debian over Rocky when you are creating early version of server and/or you are beginner, because there are many more beginner friendly tutorial about Debian.

When to use Rocky ?
*	Use Rocky over Debian when you have to use software that can be used in Debian Stable version and/or you want to make a critical enterprise server.

What make Linux distro differ ?
*	support for different hardware devices and systems or software package configurations, and new version release schedule.

Comparing AppArmor and SeLinux
*	Both AppArmor and SeLinux are MAC (Mandatory Access Control)
*	AppArmor are more user friendly than SeLinux.
*	SeLinux are stricter than AppArmor

Comparing UFW and Firewalld
*	Both UFW and Firewalld are interface of iptables and is used for guarding dangerous internet connection.
*	Firewalld is designed to be used with Red Hat distro and/or Docker.
*	UFW is more user friendly than Firewalld.

Pro of Virtual Box
1.	It support Windows, MacOS, Linux, and some other OS.
2.	It has diverse features e.g. Snapshots, Shared Folders, Virtualize graphic etc.

Con of Virtual Box
1.	Use more resource
2.	Sometimes, set up can be more challenging

Pro of UTM
1.	Suitable for MAC OS
2.	Use fewer resource

Con of UTM
1.	Lower performce with graphic and/or GPU
2.	It is less suitable for non-MAC OS host

Resource
1.	Comparison of Linux distributions
*	https://en.wikipedia.org/wiki/Comparison_of_Linux_distributions
2.	Linux Servers: Which Distro should you use?!
*	https://youtu.be/at4HNRLDERs?si=hWOqvD5LxgRL70Zq
3.	AppArmor vs SELinux: Compare the Differences in Linux Security
*	https://tuxcare.com/blog/selinux-vs-apparmor/
4.	Comparing UFW and Firewalld
*	https://www.reddit.com/r/archlinux/comments/1hkc5x7/regarding_the_firewall_should_i_use_ufw_or/
*	https://www.reddit.com/r/archlinux/comments/3aroy1/firewalld_vs_ufw/
5.	Comparing Pro and Con of Virtual Box and UTM
*	https://youtu.be/szHtNnwC9sE?si=75yRJ3_pbBJcZEcw

# Instructions

## Set up LVM

Server is a computer or computer program that manages access to a centralized resource or service in a network.. Common practical applications of server related technology are
1.	testing if software works with in specific environment e.g. testing if software works in client's OS, test cyber security related software etc.
2.	allow some user to access, edit, and execute some part of computer e.g. Google Drive host, Spotify/Netflix/YouTube Streaming, Facebook profile, Google etc.

LVM is used for managing storage. LVM can be used for managing hardware resource of server.

In order to set LVM you have to
Part No.1: Set initial configuration for VirtualBox file
1.	Open VirtualBox
2.	Click `New` button.
3.	Set initial configuration 
	1.	Name: LVM name, I will name this LVM as `fourier42`
	2.	Folder: Path that contains LVM
	3.	ISO Image: Path that contains ISO image (the file that contains the instruction about the Linux Kernal)
	4.	Click Skip Unattended installation as yes, to avoid unattended installation
4.	Click `Hardware` and set Base Memory and CPU Processors as needed.
5.	Click `Hard Dick` and set amount of hard disk as needed.
6.	Click `Finish` and then click new LVM (on the left panel)

Part No.2: Set initial configuration for LVM
1.	Click `View` -> `Virtual Screen 1` -> `Scale to 150% (autoscaled output)`
2.	Choose `installation` option then press `[return]`
3.	Choose `English` option then press `[return]`
4.	Choose location that near your time zone. In my case it is `other` -> `Asia` -> `Thailand`
5.	Choose `United States - en_US.UTF-8`
6.	Choose `American English`
7.	Set hostname as some name, in my case, the host name is `fft42`
8.	Set domain name as empty string
9.	Set root password
10.	Set name and password of user, in this case, the user is `phsottat42`
11.	Choose `Guided - use entire disk and set up encrypted LVM` option and press `[return]` 2 times.
12.	Choose `Separate /var and /srv, swap < 1GB (for servers)` option
13.	Choose `Yes` option
14.	Set encryption passphrase
15.	Press `[tab]` + `[return]`
16.	Choose `Finish partitioning and write changes to disk` option
17.	Choose `Yes` option
18.	Choose `No` option
19.	Choose location that is your country or near your country. In my case it is `Thailand`.
20.	Choose `deb.debian.org` option
21.	Set HTTP proxy information as empty string
22.	Choose `Yes` option if you don't care about your privacy, or else `No` option.
23.	Avoid install every software in this list and press `Continue` option.
24.	Choose `Yes` option
25.	Choose `/dev/sda (ata-VBOX_HARDDISK_VB0ac1d01c-11ee6b2c)`
26.	Choose `Continue` option to boot.

Part 3: Use LVM for the first time
1.	Write your encryption passphrase
2.	Write `root`
3.	Write your root password

Note that
*	When you first click in virtual machine and it promt `You have clicked the mouse inside the Virtual Machine display or pressd the host key combo. This will ...`, you should click `Cancel` option for the sake of your beginner friendly UXUI.

Resource
1.	How to set up a Linux Web Server using Debian (https://youtu.be/nXxgHrVWOEQ?si=l3e5Iu-RGGTEKOJI)
*	The 0:00 to 6:30 part of this video show how to to use VirtualBox to set LVM. Note that even through both me and him didn't install GUI, his configuration is different from my configuration.
2.	How to use Virtual Box (https://youtu.be/nvdnQX9UkMY?si=JZNz_QuLUIGdYT2w)
*	The YouTuber show how to make LVM with Ubuntu and GUI.

## Creating user and user group

Every Linux server have `root` user which control everythings. A Linux server can have one or multiple users, however, not all user can do everythings as `root` user can, for security related reason e.g. avoid someone to betray you by deleting crucial files etc.

Note that there are 2 users, including `root` and `phsottat42` in my LVM.

In order to control how rule on what users can and cannot do, you can use `chmod` and Apparmor command.

Note that
*	chmod is just a simple system utility used to set the access permissions for files
*	MAC define the explicit permission and rule on how users and processes access and use all the resources.

Linux have user group in order to assign roles to multiple users at once. I will create group named as `user42` with `phsottat42` as its member.
1.	Create user group
*	`groupadd user42`
2.	Add `phsottat42`
*	`sudo usermod -aG user42 phsottat42`
3.	Check if `user42` group have `phsotatt42` as its member.
*	`getent group user42`

Resource
1.	Linux command for setting user and user group (a.k.a. group) (https://labex.io/lesson/users-and-groups)
*	This website contains Bash command for managing user and user group, including 
	1.	`useradd` (creating new user)
	2.	`usermod` (for adding user in a particular group, and adding comment and other data about the specific user)
	3.	`userdel` (delete user)
	4.	`groupadd` (creating new user group)
	5.	`groupdel` (delete user group)
2.	How to view list of all user and user group ?
	1.	How to view all user ? (https://unix.stackexchange.com/questions/423850/how-to-list-users-in-linux-local-remote-real-and-all-users)
	2.	How to view all user group ? (https://askubuntu.com/questions/136788/how-do-i-list-the-members-of-a-group)
3.	How to create user group with target users ?
	1.	How to add user in `sudo` group ? (https://askubuntu.com/questions/2214/how-do-i-add-a-user-to-the-sudo-group)
4.	Different between MAC and chmod
*	https://superuser.com/questions/1687880/how-are-apparmor-and-chmod-related-if-at-all

## How to add new user ?

You can add new user by
1.	Install the `adduser` command
*	`$sudo apt-get install adduser`
2.	Add new user. I will name them as `frieren_transform`
*	`adduser frieren_transform`

How to list all user ?
*	`getent passwd | cut -d: -f1`

How to set `frieren_transform` user password ?
*	`sudo passwd frieren_transform`

How to assign `frieren_transform` in a group `user42` ?
*	sudo usermod -a -G `user42` `frieren_transform`

How to list all of the user in a group `user42` ?
*	`getent group | grep user42`

You can delete user `frieren_transform` and their home directory by using this command
1.	Delete `frieren_transform`
*	`sudo userdel frieren_transform`
2.	Delete their home directory.
*	`sudo rm -r /home/frieren_transform`

Note that
*	It is much more recommended to use `adduser` than `useradd`, because `adduser` is a wrapper of `useradd` and `adduser` is easier to use.

Reference
1.	How to use `adduser` command ?
*	https://www.geeksforgeeks.org/linux-unix/adduser-command-in-linux-with-examples/
2.	The different between `adduser` and `useradd`
*	https://askubuntu.com/questions/345974/what-is-the-difference-between-adduser-and-useradd
3.	How to delete a user & its home folder safely?
*	https://askubuntu.com/questions/459365/how-to-delete-a-user-its-home-folder-safely
4.	How to list all users ?
*	https://unix.stackexchange.com/questions/423850/how-to-list-users-in-linux-local-remote-real-and-all-users
5.	How to assign user to a group ?
*	https://askubuntu.com/questions/79565/how-to-add-existing-user-to-an-existing-group
6.	How to list all of the user in a group ?
*	https://serverfault.com/questions/355292/show-all-users-and-their-groups-vice-versa

## How to be any user ?

We can switch user from `root` to `phsottat42` by using `su` command
*	`su phsottat42`

We can be root user by `su root`.

We can be any user by `su <user name>`.

## Change host name

You can view host name by 
*	`sudo hostnamectl`

You can change host name by
*	`sudo hostnamectl set-hostname <new_name>`

How to solve `sudo: unable to resolve host {hostname}: Temporary failure in name resolution` issues ?
*	set `/etc/hostname` and `/etc/hosts` according to new hostname correctly.

Resource
1.	How to view host name ?
*	https://youtu.be/sJ-JfVD-p0M?si=fCZUdATnFAuNSnmk
2.	If you get "sudo: unable to resolve host {hostname}: Temporary failure in name resolution" related error, I recommend you to read this post.
*	https://askubuntu.com/questions/1343609/sudo-unable-to-resolve-host-hostname-temporary-failure-in-name-resolution
3.	How to solve `sudo: unable to resolve host {hostname}: Temporary failure in name resolution` issues ?
*	https://askubuntu.com/questions/1343609/sudo-unable-to-resolve-host-hostname-temporary-failure-in-name-resolution

## Set SSH Connection

SSH is used for varify that you are the right user. SSH have 2 parts, including private key and public key. You should not share your private key to anyone. On the other hand, anyone can see your public key. When you want to login in the server with your SSH, server have string that encrypted using your public key, then your computer will decrypte the string using your private key and sent the decrypted string back to the server to prove that you are the right user. If your decrypted string is not correct, then it means you are not the right user.

You can activate SSH key in your server by
1.	Update your package.
*	`sudo apt update`
2.	Install the OpenSSH server
*	`sudo apt update`
*	`sudo apt install openssh-server`
3.	Click `Machine` -> `Settings`
4.	Click `Expert`
5.	Click `Network`
6.	set Attached to: `NAT`
7.	Click `Port Forwarding`
8.	Click green `+` sign
9.	Name the rule as `ssh`
10.	Set host port and guest port as any number. In my case, I will set it as `5151` and `4242` respectively. If you want to follow 42 Coding school assignment stricly, both host and guest port should be `4242`, and don't forget to edit `ssh_config` and `sshd_config` accordingly.
11.	Click `OK`
12.	Click `OK`
13.	`cd /etc/ssh/`
14.	Edit `ssh_config`
*	`nano ssh_config`
*	`Port 5151`
*	Press `[control]` + `[x]` + `[y]` + `[return]`
15.	Edit `sshd_config`
*	`nano sshd_config`
*	`Port 4242`
*	`PermitRootLogin no`
*	Press `[control]` + `[x]` + `[y]` + `[return]`
16.	Restart SSH service
*	`service ssh restart`
17.	Using your Terminal on Open VSCode to login on your server.
*	`ssh -p 5151 phsottat42@localhost`
18.	You can logout by using `exit` command

Resource
1.	How SSH works ? (https://youtu.be/dPAw4opzN9g?si=zbBTfppLSlBZdDN7)
2.	How to SSH into a VirtualBox machine (NAT/Bridged)
	1.	https://youtu.be/KQbiii-EEQs?si=vv_qdJ95Sl7uuZJ5
	2.	https://youtu.be/rhFLfwZzlGA?si=F0yS2pitDcHLPbPQ
3.	Different between ssh_config and sshd_config (https://www.reddit.com/r/linuxquestions/comments/dwweeq/whats_the_difference_between_etcsshssh_config_and/)
4.	How to Enable and Disable Root Login via SSH on Ubuntu (https://youtu.be/WRdAugZivPQ?si=KWKCyYPIAGWFWmXI)

## What is Path Environment Variable ?

Path variable is used to add full path for user's command, for example in some cases `PATH=/bin:/usr/bin:/usr/sbin`, it means when you run `echo hello`, it will do one of `/bin/echo hello`, `/usr/bin/echo hello`, and `usr/sbin/echo hello`.

Reference
1.	What is the Unix PATH variable and how do I add to it?
*	https://superuser.com/questions/517894/what-is-the-unix-path-variable-and-how-do-i-add-to-it

## Sudo

`sudo` is the Bash command that allow user to use command as same as the `root` user. Sometimes, it is a good idea to let some users use `sudo` command, and sometimes it isn't, for example you might want some employee to reboot your server with `sudo reboot` when there is a crushed, or you want some user to access information about your server with `sudo hostnamectl` but you do not everyone to be able to do this.

I will create user group that contains only users who can use `sudo` command as named as `sudo`, in order to managing this group of user more easier.

We can set user `phsottat42` to be in the `sudo` group by
1.	Install `sudo`
*	`apt-get update`
*	`apt-get install sudo`
2.	Add `phsottat42` user in `sudo` group
*	`sudo usermod -aG sudo phsottat42`
3.	Check if `user42` group have `phsotatt42` as its member.
*	`getent group user42`

Now you can use `sudo` command, here are some examples of `sudo` command
1.	Update `apt`
*	`sudo apt-get update`
2.	See host name
*	`sudo hostnamectl`

According to the subject, we have to set up a strong configuration for our sudo group. The file that control sudo policy is `/etc/sudoers`. However, it is not recommended to edit this file directly (like using `nano /etc/sudoers` command), because you might config it in a wrong way without any warning, which make you unable to login, your other users can hack your system, and/or other issues.

You can edit `/etc/sudoers` by
1.	`sudo visudo`
2.	Add the following configuration

```
# PURPOSE: Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
# https://askubuntu.com/questions/534868/
# how-can-i-change-the-number-of-password-entry-attempts-allowed-by-sudo
Defaults	passwd_tries=3

# PURPOSE: A custom message of your choice has to be displayed if an incorrect password is
entered when using sudo.
# https://stackoverflow.com/questions/41058328/sudo-change-default-error-message
Defaults	badpass_message="Chopin Wrong Note Etude"

# PURPOSE: Each action performed with sudo has to be logged, including both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
# https://unix.stackexchange.com/questions/108577/
# how-to-log-commands-within-a-sudo-su
%sudo		ALL=(ALL:ALL) LOG_INPUT: LOG_OUTPUT: ALL
Defaults	iolog_dir=/var/log/sudo/

# PURPOSE: The TTY mode has to be enabled for security reasons
# https://stackoverflow.com/questions/67985925/
# why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi
# "This restriction (Defaults requiretty) is not particularly hard to circumvent,
# and so generally isn't all that useful compared to the valid use cases it breaks
# . Red Hat used to use it, but removed it a few years ago." So this setting is considered as outdated.
Defaults    requiretty

# PURPOSE: For security reasons, the paths that can be used by sudo must also be restricted.
Defaults	secure_path=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
```

Resource
1.	How to set up a strong configuration for your sudo group ?
*	https://youtu.be/uYLzDCmv-OA?si=6Di1owLNXKaL5OTm

## Set Password Policy

We can see information about `phsottat42` account and password expiration
*	`chage -l phsottat42`

We can set up password policy of `phsottat42` according to 42 Coding school assignment, by
1.	Setting the minimum number of days between password changes must be set to 2.
*	`chage -m 2 phsottat42`
2.	Setting such that the warning message is displayed 7 days before their password expires.
*	`chage -W 7 phsottat42`
3.	Setting such that the password has to expire every 30 days.
*	`chage -M 30 phsottat42`
4.	Install `libpam-pwquality`. Note that the library pam_pwquality.so has in many/most cases superceded the use of pam_cracklib.so. pam_pwquality.so should be backwards compatible with pam_cracklib.
*	`sudo apt update`
*	`sudo apt install libpam-pwquality`
5.	Edit `/etc/security/pwquality.conf` accordingly
*	`nano pwquality.conf`
*	Add the following configuration.

```
difok = 7
minlen = 10
dcredit = -1
ucredit = -1
lcredit = -1
ocredit = 0
minclass = 3
maxrepeat = 3
usercheck = 1
enforce_for_root
```

You can change you password using `passwd` command.

Resource
1.	Linux Crash Course - User Account & Password Expiration
*	https://youtu.be/UYBPpaWUT64?si=nj9t-aVGywbGKdNf
2.	How to enforce a password complexity policy
	1.	https://askubuntu.com/questions/244115/how-do-i-enforce-a-password-complexity-policy
	2.	https://serverfault.com/questions/936760/how-to-set-password-complexity-in-redhat-7-5
	3.	The Best Way to Secure Linux: Mastering PAM on openSUSE Leap: https://youtu.be/6xYaAPxgK7U?si=W0XZ214nbus-Xw1C
	4.	https://manpages.debian.org/testing/libpam-pwquality/pam_pwquality.8.en.html
	5.	https://oneuptime.com/blog/post/2026-01-15-configure-pam-authentication-ubuntu/view#password-policies-with-pam-pwquality

## Set UFW

UFW (a.k.a. Uncomplicated Fire Wall) is used for making sure that only specific type of port can access your server, in order to protect your server from hacker and/or other issues.

According to Born2BeRoot assignment, you have to leave only port 4242 (or in my case, port `4242`) open in your virtual machine, using UFW. You can do this by
1.	Installing UFW
*	`sudo apt update`
*	`sudo apt install ufw`
2.	Check if `IPV6=yes`, if no then you have to update accordingly using `nano`
* `cat /etc/default/ufw|grep IPV6`
3.	Setting Up Default Policies, By default, UFW is set to deny all incoming connections and allow all outgoing connections.
*	`sudo ufw default deny incoming`
*	`sudo ufw default allow outgoing`
4.	Allow only SSH port. In my case the SSH port is 4242
*	`sudo ufw allow 4242`
5.	Enable ufw
*	`sudo ufw enable`

Other common UFW Command
*	`sudo ufw status` or `sudo ufw status numbered` to view current UFW rules and status
*	`sudo ufw delete "port_index_number"` to delete UFW rule based on its index number.
*	`sudo ufw disable` to disable UFW.

Resource
1.	How to use UFW ?
*	https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu

## Set Cronjob to automating monitoring.sh every 10 minutes.

According to Born2BeRoot assignment, you have to show some specific information about hardware usage and your server in every 10 minutes, by implementing `monitoring.sh` and using `wall` command.

Here is my `/home/phsottat42/monitoring.sh` implementation

```
#!/bin/sh

# PURPOSE: The architecture of your operating system and its kernel version.
# Best way to find the OS name and version on a Unix/Linux platform 

# https://stackoverflow.com/questions/26988262/
# uname print information about Kernal.

arch=$(uname -a)

#############################################################################

# https://www.reddit.com/r/explainlikeimfive/comments/pqkfj9/
# eli5_what_is_the_difference_between_core/
# CPU = processor

# logical cores = thread = virtual processors = virtual cores (according to Google's LLM)

# https://unix.stackexchange.com/questions/88283/so-what-are-logical-cpu-cores-as-opposed-to-physical-cpu-cores
# Physical cores = physical cores within the CPU. 
# Logical cores = the abilities of a single core to do 2 or more things simultaneously. 

#############################################################################

# https://www.reddit.com/r/learnprogramming/comments/
# xejbjd/difference_between_cpund_its_core/
# A core is essentially what used to be called a CPU, 
# but as the number of transistors that can be fit on one chip has increased, 
# the best use of them has been to put multiple whole CPUs on the same chip.
# whole single-chip package is now called the CPU, and consists of multiple cores

# https://youtu.be/E2r04dKacE4?si=PJLkKMI-qSZh9T0o
# Thread only helps CPU do multi tasking.

# https://unix.stackexchange.com/questions/218074/
# how-to-know-number-of-cores-of-a-system-in-linux
# “CPU(s): 56” = the number of logical cores, which equals “Thread(s) per core” × “Core(s) per socket” × “Socket(s)”. 
# Socket = physical CPU package

# PURPOSE: The number of physical processors.

# https://unix.stackexchange.com/questions/468766/understanding-output-of-lscpu
phy=$(lscpu | grep -i -e "^socket" | awk -F " " '{print $2}')

# PURPOSE: The number of virtual processor.
# https://kinsoft.id/blog/general-1/post/how-to-display-the-number-of-processors-vcpu-on-linux-vps-13
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)

#############################################################################

# PURPOSE: The currently available RAM on your server and its utilization rate as a percentage.

# The currently available RAM on your server and its utilization rate as a percentage.
# https://stackoverflow.com/questions/10585978/how-to-get-the-percentage-of-memory-free-with-a-linux-command
# https://www.geeksforgeeks.org/linux-unix/free-command-linux-examples/
sub_ram1=$(free -h | grep Mem | awk '{print $3"/"$7}')
sub_ram2=$(free | grep Mem | awk '{print 100*$3/$7}')
ram=$(echo "$sub_ram1 ($sub_ram2%)")

#############################################################################

# PURPOSE: The currently available storage on your server and its utilization rate as a percentage.
# https://youtu.be/SRtMO-R7dJw?si=g4FHSLAR7R3eVRLw
# https://stackoverflow.com/questions/1507948/search-with-grep-for-words-beginning-and-ending-with

disk1=$(df -h | grep " /$" | awk '{print $3"/"$2}')
disk2=$(df -h | grep " /$" | awk '{print $5}')
disk=$(echo "$disk1 ($disk2)")

#############################################################################

# PURPOSE: The current CPU utilization rate as a percentage.

# https://youtu.be/3r_PBLaZoFQ?si=EZnMiKQOYnBWaZg9
# top command is used for inspecting CPU usage.
# The execution of a program is suspended and instructions belonging to it are not fetched from memory or executed. 
# Those states are the idle states of the processor.
# Since part of the processor hardware is not used in idle states, 
# entering them generally allows power drawn by the processor to be reduced and, 
# in consequence, it is an opportunity to save energy.

# https://linux.die.net/man/1/top
# https://stackoverflow.com/questions/27658675/
# how-to-remove-last-n-characters-from-a-string-in-bash
cpu=$(top -b -n1 | awk -F "," '/^%Cpu/ {print $4}' | cut -c -3 | awk '{print 100 - $1"%"}')

#############################################################################

# PURPOSE: The date and time of the last reboot.
# https://www.cyberciti.biz/tips/linux-last-reboot-time-and-date-find-out.html
boot=$(who -b | awk -F " " '{print $3" "$4}')

#############################################################################

# PURPOSE: Whether LVM is active or not.
# https://labex.io/tutorials/linux-how-to-check-if-an-lvm-volume-is-active-in-linux-558783#verify-volume-mappings-in-%2Fdev%2Fmapper

# https://serverfault.com/questions/606383/logical-volume-attributes
# o = open

# https://stackoverflow.com/questions/5615717/
# how-can-i-store-a-command-in-a-variable-in-a-shell-script
# My friend recommend me to use this approach
lvm=$(lsblk -f | grep -q -i "lvm" && echo yes || echo no)

#############################################################################

# https://unix.stackexchange.com/questions/16311/what-is-a-socket
# A socket is a pseudo-file that represents a network connection.

# https://superuser.com/questions/529830/get-a-list-of-open-ports-in-linux
# Since net-tools is deprecated, you can use the ss command instead.

# https://youtu.be/phY8Q7Woxsw?si=8ysXi8bG-MijD3qh
# How to Use the ss Command (Linux Crash Course Series)

# Active Connection = Open Network Connection (according to Google's LLM)

# https://linux-audit.com/networking/faq/how-to-see-number-of-open-connections/
# How to see the number of open connections on Linux.

# What is TCP ?
# TCP (Transmission Control Protocol) is a protocol that allows devices to communicate reliably over a network.

# PURPOSE: The number of active connections.

tcp=$(ss -s | grep "TCP" | awk -F ' ' '{print $2" ESTABLISHED"}' | head -n 1)

#############################################################################

# https://superuser.com/questions/13043/
# how-can-i-find-the-number-of-users-online-in-linux

# PURPOSE: The number of users using the server.

log=$(users | wc -w)

#############################################################################

# PURPOSE: The IPv4 address of your server and its MAC (Media Access Control) address.

# https://www.geeksforgeeks.org/computer-networks/what-is-ipv4/
# IP = Internet Protocol which is used for identifying device on Network
# IPv4 = Internet Protocol Version 4 = the most widely used IP

# https://www.geeksforgeeks.org/computer-networks/mac-address-in-computer-network/
# MAC Address = Media Access Control Address

# https://askubuntu.com/questions/1113600/why-is-ip-different-from-inet
# inet = Internet Networking = IP your machine

# https://www.reddit.com/r/linux4noobs/comments/juay13/where_can_i_find_my_macddress/
# inet = IPv4 address
# inet6 = IPv6 adress
# ether = MAC Adress
# netmask = netmask

# https://serverfault.com/questions/15887/how-to-list-all-the-ip-addresses-of-a-server
# How to show IP ?

# https://youtu.be/wHfIFZlDxtU?si=l6YEx2qYXKwoQp9p
# How to Use the ip Command in Linux: A Beginner’s Guide

# https://stackoverflow.com/questions/15135430/display-only-the-nth-match-of-grep
# https://askubuntu.com/questions/786883/how-do-i-retrieve-only-the-needed-line-from-terminal-output

ipp=$(ip a | grep "inet " | sed -n 2p | awk -F " " '{print $2}')
mac=$(ip a | grep "ether" | awk -F " " '{print $2}')
ip=$(echo "$ipp ($mac)")

#############################################################################

# https://www.geeksforgeeks.org/linux-unix/history-command-in-linux-with-examples/
# https://labex.io/lesson/regular-expressions-regex
# https://www.geeksforgeeks.org/linux-unix/wc-command-linux-examples/
# https://www.geeksforgeeks.org/linux-unix/history-command-in-linux-with-examples/
# https://unix.stackexchange.com/questions/127551/why-does-the-history-command-do-nothing-in-a-script-file
# https://unix.stackexchange.com/questions/5684/history-command-inside-bash-script
# PURPOSE: The number of commands executed with the sudo program.
HISTFILE=~/.bash_history
set -o history
# cmd=$(history | wc -l)
cmd=$(history | grep -e "^[0-9 ]*sudo" | wc -l)
sudo=$(echo "$cmd cmd")

#############################################################################

# https://www.geeksforgeeks.org/linux-unix/history-command-in-linux-with-examples/
# https://labex.io/lesson/regular-expressions-regex
# https://www.geeksforgeeks.org/linux-unix/wc-command-linux-examples/
# https://www.geeksforgeeks.org/linux-unix/history-command-in-linux-with-examples/
# https://unix.stackexchange.com/questions/127551/why-does-the-history-command-do-nothing-in-a-s>
# https://unix.stackexchange.com/questions/5684/history-command-inside-bash-script

# https://man7.org/linux/man-pages/man1/journalctl.1.html
# PURPOSE: The number of commands executed with the sudo program.

###This line is wrong because you cannot use set -o history in cronjob and history won't working>
###HISTFILE=~/.bash_history
###set -o history
###cmd=$(history | grep -e "^[0-9 ]*sudo" | wc -l)
###sudo=$(echo "$cmd cmd")

# My friend, 42 Born2BeRoot and ChatGPT recommend me to use journalctl.
# journalctl is used to print the log entries stored in the journal
# The frag of this command is used for filtering the printed content.
# If there are multiple frag, journalctl filter data according to both (&)
# Finally, the character "+" may appear as a
    separate word between other terms on the command line. This causes
    all matches before and after to be combined in a disjunction (i.e.
    logical OR).
# a "_COMM=" match for the script name is added to the query
# --since= showing entries on or newer than the specified date
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l )

#############################################################################

wall "
#Architecture: $arch
#Physical CPU: $phy
#vCPU: $vcpu
#Memory Usage: $ram
#Disk Usage: $disk
#CPU load: $cpu
#Last boot: $boot
#LVM use: $lvm
#TCP Connection: $tcp
#User log: $log
#Network: IP $ip
#Sudo: $sudo
"
```

Here is the output

```
phsottat42@tuki42:~$ bash monitoring.sh 
#Architecture: Linux tuki42 6.12.73+deb13-amd64 #1 SMP PREEMPT_DYNAMIC Debian 6.12.73-1 (2026-02-17) x86_64 GNU/Linux
#Physical CPU: 1
#vCPU: 5
#Memory Usage: 297Mi/1.6Gi (17.7314%)
#Disk Usage: 673M/4.6G (16%)
#CPU load: 2%
#Last boot: 2026-02-27 16:54
#LVM use: yes
#TCP Connection: 3 ESTABLISHED
#User log: 3
#Network: IP 10.0.2.15/24 (08:00:27:7d:2c:5b)
#Sudo: 0 cmd
```

Cron Job is used for making Bash script activate to a particular user according to customized schedule. You can edit Cron Job of `phsottat42`, to activate `monitoring.sh` every 10 minutes, by
1.	Editing the Cron Job of `root`
*	`sudo crontab -u root -e`
2.	Set to activate `monitoring.sh` every 10 minutes
*	`*/10 * * * * /bin/sh /home/phsottat42/monitoring.sh`

Resource
1.	How to use Cron Job ?
*	https://youtu.be/v952m13p-b4?si=nxkPeAf-r6Q_YxvT
2.	How to set up a Cron Job to run every 10 minutes ?
*	https://askubuntu.com/questions/799023/how-to-set-up-a-cron-job-to-run-every-10-minutes
3.	How to use `wall` command ?
*	https://linuxize.com/post/wall-command-in-linux/
4.	Read this if your Cron Job is not working.
*	https://askubuntu.com/questions/23009/why-crontab-scripts-are-not-working
5.	Path of Cron Job
*	https://askubuntu.com/questions/71799/what-is-my-crontab-e-local-file-path-i-want-to-set-it-via-bash-script
6.	How to change path variable of Cronjob ?
*	https://stackoverflow.com/questions/53426594/can-i-change-default-path-variable-of-cronjob

## How to submit `signature.txt` file ?

My friend said that you can submit Born2BeRoot by
1.	Close your LVM
2.	go to `~/sgoinfre/virtualbox/fourier42`
3.	`sha1sum fourier42.vdi`
4.	Copy paste random output string inside `signature.txt`
5.	Git init, including `signature.txt` in Git repo, Git add, Git commit, and Git push, as usual

# Resource

## Software Tool comparison
1.	Comparison of Linux distributions
*	https://en.wikipedia.org/wiki/Comparison_of_Linux_distributions
2.	Linux Servers: Which Distro should you use?!
*	https://youtu.be/at4HNRLDERs?si=hWOqvD5LxgRL70Zq
3.	AppArmor vs SELinux: Compare the Differences in Linux Security
*	https://tuxcare.com/blog/selinux-vs-apparmor/
4.	Comparing UFW and Firewalld
*	https://www.reddit.com/r/archlinux/comments/1hkc5x7/regarding_the_firewall_should_i_use_ufw_or/
*	https://www.reddit.com/r/archlinux/comments/3aroy1/firewalld_vs_ufw/
5.	Comparing Pro and Con of Virtual Box and UTM
*	https://youtu.be/szHtNnwC9sE?si=75yRJ3_pbBJcZEcw

## Set up LVM
1.	How to set up a Linux Web Server using Debian (https://youtu.be/nXxgHrVWOEQ?si=l3e5Iu-RGGTEKOJI)
*	The 0:00 to 6:30 part of this video show how to to use VirtualBox to set LVM. Note that even through both me and him didn't install GUI, his configuration is different from my configuration.
2.	How to use Virtual Box (https://youtu.be/nvdnQX9UkMY?si=JZNz_QuLUIGdYT2w)
*	The YouTuber show how to make LVM with Ubuntu and GUI.

## Creating user and user group
1.	Linux command for setting user and user group (a.k.a. group) (https://labex.io/lesson/users-and-groups)
*	This website contains Bash command for managing user and user group, including 
	1.	`useradd` (creating new user)
	2.	`usermod` (for adding user in a particular group, and adding comment and other data about the specific user)
	3.	`userdel` (delete user)
	4.	`groupadd` (creating new user group)
	5.	`groupdel` (delete user group)
2.	How to view list of all user and user group ?
	1.	How to view all user ? (https://unix.stackexchange.com/questions/423850/how-to-list-users-in-linux-local-remote-real-and-all-users)
	2.	How to view all user group ? (https://askubuntu.com/questions/136788/how-do-i-list-the-members-of-a-group)
3.	How to create user group with target users ?
	1.	How to add user in `sudo` group ? (https://askubuntu.com/questions/2214/how-do-i-add-a-user-to-the-sudo-group)
4.	Different between MAC and chmod
*	https://superuser.com/questions/1687880/how-are-apparmor-and-chmod-related-if-at-all

## How to add new user ?
1.	How to use `adduser` command ?
*	https://www.geeksforgeeks.org/linux-unix/adduser-command-in-linux-with-examples/
2.	The different between `adduser` and `useradd`
*	https://askubuntu.com/questions/345974/what-is-the-difference-between-adduser-and-useradd
3.	How to delete a user & its home folder safely?
*	https://askubuntu.com/questions/459365/how-to-delete-a-user-its-home-folder-safely
4.	How to list all users ?
*	https://unix.stackexchange.com/questions/423850/how-to-list-users-in-linux-local-remote-real-and-all-users
5.	How to assign user to a group ?
*	https://askubuntu.com/questions/79565/how-to-add-existing-user-to-an-existing-group
6.	How to list all of the user in a group ?
*	https://serverfault.com/questions/355292/show-all-users-and-their-groups-vice-versa

## Change host name
1.	How to view host name ?
*	https://youtu.be/sJ-JfVD-p0M?si=fCZUdATnFAuNSnmk
2.	If you get "sudo: unable to resolve host {hostname}: Temporary failure in name resolution" related error, I recommend you to read this post.
*	https://askubuntu.com/questions/1343609/sudo-unable-to-resolve-host-hostname-temporary-failure-in-name-resolution
3.	How to solve `sudo: unable to resolve host {hostname}: Temporary failure in name resolution` issues ?
*	https://askubuntu.com/questions/1343609/sudo-unable-to-resolve-host-hostname-temporary-failure-in-name-resolution

## Set SSH Connection
1.	How SSH works ? (https://youtu.be/dPAw4opzN9g?si=zbBTfppLSlBZdDN7)
2.	How to SSH into a VirtualBox machine (NAT/Bridged)
	1.	https://youtu.be/KQbiii-EEQs?si=vv_qdJ95Sl7uuZJ5
	2.	https://youtu.be/rhFLfwZzlGA?si=F0yS2pitDcHLPbPQ
3.	Different between ssh_config and sshd_config (https://www.reddit.com/r/linuxquestions/comments/dwweeq/whats_the_difference_between_etcsshssh_config_and/)
4.	How to Enable and Disable Root Login via SSH on Ubuntu (https://youtu.be/WRdAugZivPQ?si=KWKCyYPIAGWFWmXI)

## What is Path Environment Variable ?
1.	What is the Unix PATH variable and how do I add to it?
*	https://superuser.com/questions/517894/what-is-the-unix-path-variable-and-how-do-i-add-to-it

## Sudo
1.	PURPOSE: Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
*	https://askubuntu.com/questions/534868/how-can-i-change-the-number-of-password-entry-attempts-allowed-by-sudo
2.	PURPOSE: A custom message of your choice has to be displayed if an incorrect password is
*	https://stackoverflow.com/questions/41058328/sudo-change-default-error-message
3.	PURPOSE: Each action performed with sudo has to be logged, including both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
*	https://unix.stackexchange.com/questions/108577/how-to-log-commands-within-a-sudo-su
4.	PURPOSE: The TTY mode has to be enabled for security reasons
*	https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi
5.	How to set up a strong configuration for your sudo group ?
*	https://youtu.be/uYLzDCmv-OA?si=6Di1owLNXKaL5OTm

## Set Password Policy
1.	Linux Crash Course - User Account & Password Expiration
*	https://youtu.be/UYBPpaWUT64?si=nj9t-aVGywbGKdNf
2.	How to enforce a password complexity policy
	1.	https://askubuntu.com/questions/244115/how-do-i-enforce-a-password-complexity-policy
	2.	https://serverfault.com/questions/936760/how-to-set-password-complexity-in-redhat-7-5
	3.	The Best Way to Secure Linux: Mastering PAM on openSUSE Leap: https://youtu.be/6xYaAPxgK7U?si=W0XZ214nbus-Xw1C
	4.	https://manpages.debian.org/testing/libpam-pwquality/pam_pwquality.8.en.html
	5.	https://oneuptime.com/blog/post/2026-01-15-configure-pam-authentication-ubuntu/view#password-policies-with-pam-pwquality

## Set UFW
1.	How to use UFW ?
*	https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu

## Set Cronjob to automating monitoring.sh every 10 minutes.
1.	How to use Cron Job ?
*	https://youtu.be/v952m13p-b4?si=nxkPeAf-r6Q_YxvT
2.	How to set up a Cron Job to run every 10 minutes ?
*	https://askubuntu.com/questions/799023/how-to-set-up-a-cron-job-to-run-every-10-minutes
3.	How to use `wall` command ?
*	https://linuxize.com/post/wall-command-in-linux/
4.	Read this if your Cron Job is not working.
*	https://askubuntu.com/questions/23009/why-crontab-scripts-are-not-working
5.	Path of Cron Job
*	https://askubuntu.com/questions/71799/what-is-my-crontab-e-local-file-path-i-want-to-set-it-via-bash-script
6.	How to change path variable of Cronjob ?
*	https://stackoverflow.com/questions/53426594/can-i-change-default-path-variable-of-cronjob

