export

CC = gcc
LD = gcc
#CC = attolcc -mempro -perfpro -block -proc -- gcc
#LD = attolcc -mempro -perfpro -block -proc -- gcc
CFLAGS = -O3 -fomit-frame-pointer -ffast-math -Wall 
LDFLAGS = -O3 -lm -Wall
#CFLAGS = -g -Wall
#LDFLAGS = -g -lm
#CFLAGS = -pg -Wall
#LDFLAGS = -pg -lm -Wall 

#EXTRA_DEFINES :=

all: svm_map_learn_hideo svm_map_classify

.PHONY: clean
clean: svm_light_clean svm_struct_clean
	rm -f *.o *.tcov *.d core gmon.out *.stackdump svm_map_* *.pyc
cleanest: clean
	find . -name "*~" -exec rm {} \;
	rm -f model.*

#-----------------------#
#----   SVM-light   ----#
#-----------------------#
svm_light_hideo_noexe: 
	cd svm_light; mingw32-make svm_learn_hideo_noexe

svm_light_loqo_noexe: 
	cd svm_light; mingw32-make svm_learn_loqo_noexe

svm_light_clean: 
	cd svm_light; mingw32-make clean

#----------------------#
#----  STRUCT SVM  ----#
#----------------------#

svm_struct_noexe: 
	cd svm_struct; mingw32-make svm_struct_noexe

svm_struct_clean: 
	cd svm_struct; mingw32-make clean


#--------------------------#
#----  SVM python API  ----#
#--------------------------#
PYTHON_FLAGS = -LC:\Python26\libs -LC:\Python26\libs\mingw -IC:\Python26\include -lpython26

python-link:
	MACOSX_DEPLOYMENT_TARGET=10.3
	export MACOSX_DEPLOYMENT_TARGET
	python link-script.py

svm_map_classify: svm_light_hideo_noexe svm_struct_noexe svm_struct_api.o svm_struct/svm_struct_classify.o svm_struct/svm_struct_common.o svm_struct/svm_struct_main.o 
	$(LD) $(LDFLAGS) svm_struct_api.o svm_struct/svm_struct_classify.o svm_light/svm_common.o svm_struct/svm_struct_common.o -o svm_map_classify $(PYTHON_FLAGS) $(LIBS)

svm_map_learn_loqo: svm_light_loqo_noexe svm_struct_noexe svm_struct_api.o svm_struct/svm_struct_learn.o svm_struct/svm_struct_common.o svm_struct/svm_struct_main.o 
	$(LD) $(LDFLAGS) svm_light/svm_loqo.o svm_light/pr_loqo/pr_loqo.o svm_light/svm_learn.o svm_light/svm_common.o $(filter %.o,$^) -o svm_map_learn $(PYTHON_FLAGS) $(LIBS)

svm_map_learn_hideo: svm_light_hideo_noexe svm_struct_noexe svm_struct_api.o  svm_struct/svm_struct_learn.o svm_struct/svm_struct_common.o svm_struct/svm_struct_main.o
	$(LD) $(LDFLAGS) svm_light/svm_hideo.o svm_light/svm_learn.o svm_light/svm_common.o $(filter %.o,$^) -o svm_map_learn $(PYTHON_FLAGS) $(LIBS)


svm_struct_api.o: svm_struct_api.c svm_struct_api.h svm_struct_api_types.h svm_struct/svm_struct_common.h
	$(CC) -c $(CFLAGS) $(PYTHON_FLAGS) $(EXTRA_DEFINES) $(filter %.c,$^) -o svm_struct_api.o

