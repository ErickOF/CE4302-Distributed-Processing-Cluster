# Creating a shared directory
mkdir ~/shared_dir

# Export directory by nfs to be used by slave nodes
sudo echo "/home/erickof/shared_dir 192.168.0.0/24(rw,no_subtree_check,async,no_root_squash)" >> /etc/exports

# Show results
cat /etc/exports

# Restart nfs service
sudo /etc/init.d/nfs-kernel-server restart
