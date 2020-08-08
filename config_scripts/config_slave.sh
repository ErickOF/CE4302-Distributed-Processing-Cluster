# Installing ssh
sudo apt-get install ssh

# Installing Server and Client
sudo apt-get install nfs-common portmap

# Creating directory
if [ ! -d .ssh ]; then
	mkdir ~/.ssh
fi

# Gift permissions
chmod 700 .ssh

# Moving key
mv ~/id_rsa.pub ~/.ssh/authrized_keys
