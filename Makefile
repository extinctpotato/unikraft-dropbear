UK_LIBS ?= $(PWD)/lib
UK_ROOT ?= $(UK_LIBS)/unikraft
UK_BUILD ?= $(PWD)/build
LIBS := $(UK_LIBS)/lib-musl:$(UK_LIBS)/lib-lwip:$(UK_LIBS)/lib-dropbear

all:
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS) O=$(UK_BUILD)

$(MAKECMDGOALS):
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS) O=$(UK_BUILD) $(MAKECMDGOALS)
