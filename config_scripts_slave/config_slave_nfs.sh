# Creating a shared directory
if [ ! -d $HOME/shared_dir ]; then
	mkdir $HOME/shared_dir;
fi

# Mount directory
sudo mount -t nfs 192.168.0.100:/home/erick/shared_dir /home/erickof/shared_dir/

# Add directory to fstab
sudo echo "192.168.0.100:/home/erick/shared_dir /home/erickof/shared_dir nfs rw,async,hard,intr 0 0" >> /etc/fstab

# Test
sudo umount /home/erickof/shared_dir/
sudo mount -a
df -h