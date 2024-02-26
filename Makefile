# +--------------------+
# |                    |
# |   GENERAL CONFIG   |
# |                    |
# +--------------------+
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
PROBLEM_NAME := $(current_dir)
DEBUG := false
LANG := cpp
ifeq ($(LANG),cpp)
# TARGET := $(FOO)
TARGET := $(PROBLEM_NAME)
EXECUTE := ./$(TARGET)
CLEAN_TARGETS := $(TARGET)
else ifeq ($(LANG),python)
TARGET := $(PROBLEM_NAME).py
EXECUTE := python3 ./$(TARGET)
CLEAN_TARGETS :=
else
$(error "Unknown language; please set TARGET, EXECUTE, and CLEAN_TARGETS manually")
endif
TEST_PASSED := true
CXX := g++
CXXFLAGS := -std=c++17 -D local
# PRECOMPILE_HEADERS := bits/stdc++.h
# PRECOMPILE_HEADERS := bits/extc++.h

#export AC=\nPretest Passed

# Check if nocolor flag is set
ifeq ($(findstring nocolor,$(MAKECMDGOALS)),nocolor)
COLOR_OFF := true
endif

ifdef COLOR_OFF
RED :=
GREEN :=
BLUE :=
NC :=
else
RED := \033[31m
GREEN := \033[32m
BLUE := \033[36m
NC := \033[0m
BOLD := \033[1m
endif
# +-------------------+
# |                   |
# |   GENERAL RULES   |
# |                   |
# +-------------------+

all: $(TARGET)
.PHONY: all

clean:

.PHONY: clean
	-rm -rf $(CLEAN_TARGETS) *.res

# veryclean:
#     -rm -rf $(CLEAN_TARGETS) *.res
# .PHONY: veryclean
#
# rebuild: clean all
# .PHONY: rebuild

# +---------------------+
# |                     |
# |   C++ COMPILATION   |
# |                     |
# +---------------------+

# ifeq ($(DEBUG),true)
# CXXFLAGS += $(DEBUG_CXXFLAGS)
# endif
#
# PCH := .precompiled_headers
# CLEAN_TARGETS += $(PCH)
#
# $(PCH)/%.gch:
#     rm -f $@
#     mkdir -p $(dir $@)
#     # $(LINK.cpp) -x c++-header "$$(echo '#include<$*>' | $(LINK.cpp) -H -E -x c++ - 2>&1 >/dev/null | head -1 | cut -d ' ' -f2)" -o $@
# .PRECIOUS: $(PCH)/%.gch
#
# %: %.cpp # Cancel the builtin rule
#
# %: %.cpp $(patsubst %,$(PCH)/%.gch,$(PRECOMPILE_HEADERS))
#     @$(LINK.cpp) -isystem $(PCH) $< $(LOADLIBES) $(LDLIBS) -o $@
# .PRECIOUS: %
#

# +-----------------------+
# |                       |
# |   RUNNING / TESTING   |
# |                       |
# +-----------------------+

export TIME=\n   mem\t%MKB
#export TIME=\n  real\t%.6es\n  user\t%.6Us\n  sys\t%.6Ss\n  mem\t%MKB
#export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB
#export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

#export TIME=\n  real\t%es\n  sys\t%Ss\n  mem\t%MKB

run: $(TARGET)
	\time $(EXECUTE)
# ifeq ($(DEBUG),true)
#     @echo "Built with DEBUG flags enabled, code may be slower than normal"
# endif
.PHONY: run

%.res: $(TARGET) %.in
	@\time $(EXECUTE) < $*.in > $*.res
# ifeq ($(DEBUG),true)
#     @echo "Built with DEBUG flags enabled, code may be slower than normal"
# endif
.PRECIOUS: %.res

%.out: % # Cancel the builtin rule
		# echo "Success on test number $*"; \
		# echo "status\tpassed $*\n"; \


pass_count := 0
__test_%: %.res %.out
	@if diff -q $*.res $*.out >/dev/null; then \
		echo "$*:$(NC)\t$(GREEN)Accepted$(NC)\n"; \
	else \
		echo "$*:$(NC)\t$(RED)Wrong Answer$(NC)"; \
		echo "$(BLUE)Answer$(NC)"; \
		awk '{print "\t" $$0}' $*.out; \
		echo "$(BLUE)Output$(NC)"; \
		awk '{print "\t" $$0}' $*.res; \
        TEST_PASSED=false; \
        exit 1;\
	fi
.PHONY: __test_%

#	@if diff -q $*.res $*.out >/dev/null; then \
#		echo "$(GREEN)$*:\tAccepted$(NC)\n"; \
#	else \
#		echo "$(RED)$*:\tWrong Answer$(NC)\n"; \
#		echo "Answer"; \
#		awk '{print "\t" $$0}' $*.out; \
#		echo "Output"; \
#		awk '{print "\t" $$0}' $*.res; \
#		exit 1; \
#	fi



CASES := $(sort $(basename $(wildcard *.in)))
TESTS := $(sort $(basename $(wildcard *.out)))

runs: $(patsubst %,%.res,$(CASES))
.PHONY: run

solve: runs
.PHONY: solve


test: $(patsubst %,__test_%,$(TESTS))
	@if [ "$(TEST_PASSED)" = "true" ]; then \
        echo "$(GREEN)$(BOLD)Pretests Passed"; \
    else \
        echo "$(RED)$(BOLD)Pretests Failed"; \
    fi

nocolor:
	@:


