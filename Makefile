.PONY: setup_slave setup_master

SLAVES_DIR=slaves

setup_master:
	@chmod +x installation_master.sh
	@chmod +x config_master.sh

setup_slave:
	@chmod +x installation_slave.sh
	@chmod +x config_slave.sh
