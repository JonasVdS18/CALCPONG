# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= CALCPONG
ICON ?= Ballimg.png
DESCRIPTION ?= "A version of pong for your calculator"
COMPRESSED ?= YES
ARCHIVED ?= NO

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
