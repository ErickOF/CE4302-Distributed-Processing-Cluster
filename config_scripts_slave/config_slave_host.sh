# Add nodes
sudo echo "192.182.0.100 master master" >> /etc/hosts
sudo echo "192.182.0.101 slave1 slave1" >> /etc/hosts

# Show result
cat /etc/hosts
