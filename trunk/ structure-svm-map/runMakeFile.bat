@echo off
rm svm_map_learn 
rm svm_map_classify
mingw32-make
rm foo.model 
svm_map_learn.exe -c 0.1 data_index_file foo.model
rm output.txt
svm_map_classify.exe data_index_file foo.model output.txt
rm foo2.model 
svm_map_learn.exe -c 0.1 fulldata.data foo.model
rm output2.txt
svm_map_classify.exe fulldata.data foo.model output2.txt