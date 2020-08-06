# Creating build directory
if [ ! -d $HOME/openmpi ]; then
	mkdir $HOME/openmpi;
fi

# Download OpenMPI
curl https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.4.tar.gz --output openmpi-4.0.4.tar.gz
mv ./openmpi-4.0.4.tar.gz $HOME/openmpi/openmpi-4.0.4.tar.gz
cd $HOME/openmpi/
tar -xzvf openmpi-4.0.4.tar.gz
cd openmpi-4.0.4

# Installing tool
sudo apt-get install build-essential

# Configure OpenMPI installation
./configure --prefix=$HOME/openmpi

# Compile OpenMPI
make all

# Install OpenMPI
make install

# Complementaries packages for OpenMPI
sudo apt-get install openmpi-bin
sudo apt-get install libopenmpi-dev

# Add OpenMPI to PATH and LD_LIBRARY PATH system vars
export PATH=$PATH:$HOME/openmpi/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/openmpi/lib

# Test
mpicc -v
