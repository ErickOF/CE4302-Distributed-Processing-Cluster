.PONY: build_filter run_filter_local

APP=filter
SHARED_DIR=/home/erick/shared_dir
FLAGS=-lm -lpng
SLAVES_DIR=slaves

build_filter_gcc:
	@gcc ${APP}.c -o ${APP}.out ${FLAGS}

build_filter_mpic:
	@mpic ${SHARED_DIR}/${APP}.c -o ${SHARED_DIR}/${APP}.out ${FLAGS}

run_filter_local:
	@chmod +x ${SHARED_DIR}/${APP}.out
	@./${SHARED_DIR}/${APP}.out -in ${IMAGE}
	@xdg-open output.*

run_filter_cluster:
	@mpic ${SHARED_DIR}/${APP}.c -o ${SHARED_DIR}/${APP}.out ${FLAGS}
	@mpirun -v -np 2 -n ${CORES} --host localhost,192.168.0.100 ${SHARED_DIR}/${APP}.out -in ${IMAGE}
	@xdg-open output.*
