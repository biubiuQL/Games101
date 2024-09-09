.PHONY:pre debug objs exe run lib

debug:
	$(info ${src_cpp})

IS_DEBUG:=ture

#入口函数所在脚本名
main_name:=Main.cpp


src_cpp=$(shell dir /b src\*.cpp)

lib_src=$(foreach item,${src_cpp},src/${item})

cpp_pres=$(patsubst src/%.cpp,pre/%.ii,${lib_src})

cpp_objs=$(patsubst src/%.cpp,objs/%.o,${lib_src})

pre/%.ii:src/%.cpp
	@$(shell mkdir -p pre)
	@g++ -E $< -o $@

pre:${cpp_pres}

objs/%.o:src/%.cpp
	@$(shell mkdir -p objs)
	@g++ -c $< -o $@

objs:${cpp_objs}

#编译静态链接库
lib:
	@make objs
	@$(shell mkdir -p $@)
#Archive
#r: 表示将文件插入到库中，如果文件已经存在，则替换库中的文件。
#c: 表示创建一个新的库文件，如果库文件不存在，则创建一个新的库文件。
#s: 表示在库文件中添加索引，这有助于加快库文件的访问速度。
	@ar rcs $@/libMatrix.a ${cpp_objs}

exe_cmd:=@g++ ${main_name} lib/libMatrix.a -o Main.exe
ifeq (${IS_DEBUG},ture) 
exe_cmd+=-g
endif
exe:lib
	${exe_cmd}


run:exe
	@./Main.exe