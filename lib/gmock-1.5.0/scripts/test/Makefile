# A Makefile for fusing Google Mock and building a sample test against it.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make check  - makes everything and runs the built sample test.
#   make clean  - removes all files generated by make.

# Points to the root of fused Google Mock, relative to where this file is.
FUSED_GMOCK_DIR = output

# Paths to the fused gmock files.
FUSED_GTEST_H = $(FUSED_GMOCK_DIR)/gtest/gtest.h
FUSED_GMOCK_H = $(FUSED_GMOCK_DIR)/gmock/gmock.h
FUSED_GMOCK_GTEST_ALL_CC = $(FUSED_GMOCK_DIR)/gmock-gtest-all.cc

# Where to find the gmock_test.cc.
GMOCK_TEST_CC = ../../test/gmock_test.cc

# Where to find gmock_main.cc.
GMOCK_MAIN_CC = ../../src/gmock_main.cc

# Flags passed to the preprocessor.
CPPFLAGS += -I$(FUSED_GMOCK_DIR)

# Flags passed to the C++ compiler.
CXXFLAGS += -g

all : gmock_test

check : all
	./gmock_test

clean :
	rm -rf $(FUSED_GMOCK_DIR) gmock_test *.o

$(FUSED_GTEST_H) :
	../fuse_gmock_files.py $(FUSED_GMOCK_DIR)

$(FUSED_GMOCK_H) :
	../fuse_gmock_files.py $(FUSED_GMOCK_DIR)

$(FUSED_GMOCK_GTEST_ALL_CC) :
	../fuse_gmock_files.py $(FUSED_GMOCK_DIR)

gmock-gtest-all.o : $(FUSED_GTEST_H) $(FUSED_GMOCK_H) $(FUSED_GMOCK_GTEST_ALL_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FUSED_GMOCK_GTEST_ALL_CC)

gmock_main.o : $(FUSED_GTEST_H) $(FUSED_GMOCK_H) $(GMOCK_MAIN_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GMOCK_MAIN_CC)

gmock_test.o : $(FUSED_GTEST_H) $(FUSED_GMOCK_H) $(GMOCK_TEST_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GMOCK_TEST_CC)

gmock_test : gmock_test.o gmock-gtest-all.o gmock_main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
