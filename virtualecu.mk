################################################################################
# Virtual ECU
################################################################################

VIRTUALECU_VERSION = v0.1
VIRTUALECU_SITE = https://github.com/Waelhechmi/VirtualECU-Simulation-d-un-ECU-moteur-sous-Linux.git
VIRTUALECU_SITE_METHOD = git
VIRTUALECU_SUBDIR = ECU_Sim
VIRTUALECU_LICENSE = MIT

define VIRTUALECU_BUILD_CMDS
	$(MAKE) -C $(@D)/$(VIRTUALECU_SUBDIR)
endef

define VIRTUALECU_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/$(VIRTUALECU_SUBDIR)/ecusim $(TARGET_DIR)/usr/bin/ecusim
endef

$(eval $(generic-package))
