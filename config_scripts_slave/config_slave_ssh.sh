# Generate ssh key
ssh-keygen

# Copy key
scp ~/.ssh/id_rsa.pub erick@168.192.0.100:~/.ssh/authorized_keys
