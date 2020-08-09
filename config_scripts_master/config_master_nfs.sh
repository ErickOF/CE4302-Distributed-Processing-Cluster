# Creating a shared directory
if [ ! -d $HOME/shared_dir ]; then
	mkdir $HOME/shared_dir;
fi

# Export directory by nfs to be used by slave nodes
sudo echo "/home/erick/shared_dir 192.168.0.0/24(rw,no_subtree_check,async,no_root_squash)" >> /etc/exports
sudo exportfs -a

# Show results
cat /etc/exports

# Restart nfs service
sudo service nfs-kernel-server restart
