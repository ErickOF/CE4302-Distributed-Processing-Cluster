.PONY: build_filter run_filter_local

APP=filter
SHARED_DIR=/home/erick/shared_dir
MPI_FILE=/home/erick/.mpi_hostfile

SLAVES_DIR=slaves

build_filter:
	@mpic ${SHARED_DIR}/${APP}.c -o ${SHARED_DIR}/${APP}.out

run_filter_local:
	@chmod +x ${SHARED_DIR}/${APP}.out
	./${SHARED_DIR}/${APP}.out -in ${IMAGE} -c ${CORES}

run_filter_cluster:
	@mpirun -v -np 2 --host master,slave1 ${SHARED_DIR}/${APP}.out -in ${IMAGE} -c ${CORES}
