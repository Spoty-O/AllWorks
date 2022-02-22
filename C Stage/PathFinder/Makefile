NAME	=	pathfinder

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

INC_FILES = $(wildcard inc/*.h)
OBJ_FILES = $(addprefix obj/, $(notdir $(SRC_FILES:%.c=%.o)))
SRC_FILES = $(wildcard src/*.c)

LMX_A:=	libmx/libmx.a

all: clean install

install: $(LMX_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(CFLG) $(OBJ_FILES) -L libmx -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

obj/%.o: src/%.c $(INC_FILES)
	@clang $(CFLG) -c $< -o $@ -I inc -I libmx/inc

$(OBJ_FILES): | obj

obj:
	@mkdir -p $@

$(LMX_A):
	@make -sC libmx
	
clean:
	@rm -rf obj
	@printf "obj in $(NAME) \033[31;1mdeleted\033[0m\n"

uninstall:
	@make -sC libmx $@
	@rm -rf obj
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

