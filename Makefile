# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 18:36:59 by aroulin           #+#    #+#              #
#    Updated: 2017/08/30 21:01:12 by aroulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION                                                        #
# ---------------------------------------------------------------------------- # 
# - The 'DIR*' variables describe all directories of the project.              #
# ---------------------------------------------------------------------------- #

DIR_SRCS	= srcs
DIR_INCS	= incs
DIR_LIBS	= libs
DIR_DEPS	= .deps
DIR_OBJS	= .objs

# ---------------------------------------------------------------------------- #
# EXTERNAL TOOLS SETTINGS                                                      #
# ---------------------------------------------------------------------------- #
# - Set the default external programs.                                         #
# ---------------------------------------------------------------------------- #

CC			= clang
AR			= ar
ARFLAGS		= rc
RM			= rm -rf

# ---------------------------------------------------------------------------- #
#                                                                              #
# TARGET SETUP                                                                 #
#                                                                              #
# ---------------------------------------------------------------------------- #
# - The 'NAME' variable must contain the expected name of the output target.   #
# - The 'SRCS' variable must contain the list of the source files without the  #
# base prefix of the directory.                                                #
# ---------------------------------------------------------------------------- #

NAME		= 42sh

SRCS = \
	   main.c												\
	   shell.c												\
	   insertOneLine.c										\
	   read/readStdin.c									\
	   read/keyPrint.c										\
	   read/keyDelete.c									\
	   read/keyShift.c										\
	   read/keyHomeEnd.c									\
	   read/keyEof.c										\
	   read/keyTabulation.c								\
	   read/keyArrow.c										\
	   read/keyDeleteHere.c								\
	   read/keyEnter.c										\
	   read/keyInterrupt.c									\
	   read/printStruct.c									\
	   read/keyClear.c										\
	   read/myPut.c										\
	   read/firstCmd.c										\
	   read/prompt.c										\
	   read/checkCmd.c										\
	   read/gblSaveRead.c									\
	   read/finishReadStd.c								\
	   hash/hashValue.c										\
	   hash/hashBoard.c										\
	   read/completion/colorCompletion.c					\
	   read/completion/updateIndex.c						\
	   read/completion/myToGo.c							\
	   read/completion/initCompletion.c					\
	   read/completion/printTab.c							\
	   read/completion/completePath.c						\
	   read/completion/continueCompletion.c				\
	   read/completion/completeBinary.c					\
	   read/completion/createComp.c						\
	   read/completion/initFiles.c							\
	   read/completion/completion.c							\
	   read/completion/upOrDown.c							\
	   history/initHistory.c								\
	   history/previousHistory.c							\
	   history/nextHistory.c								\
	   history/makeListHist.c								\
	   history/gblSaveHistory.c							\
	   history/copyCmd.c									\
	   signal/ftSignal.c									\
	   env/split.c											\
	   env/initEnv.c										\
	   env/myGetenv.c										\
	   env/addListEnv.c									\
	   env/globalSaveEnv.c								\
	   term/initFd.c										\
	   term/initTerm.c										\
	   term/setTerm.c										\
	   term/keepTermStruct.c								\
	   memdel_struct/memdelCompletion.c					\
	   memdel_struct/memdelRead.c							\
	   error_function/bip.c									\

# ---------------------------------------------------------------------------- #
# /!\ COLOR FOR PRINTF /!\                                                     #
# ---------------------------------------------------------------------------- #

RED   =		\x1B[31m
GRN   =		\x1B[32m
YEL   =		\x1B[33m
BLU   =		\x1B[34m
MAG   =		\x1B[35m
CYN   =		\x1B[36m
WHT   =		\x1B[37m
RST   =		\x1B[0m

# ---------------------------------------------------------------------------- #
# PROJECT COMPILATION                                                          #
# ---------------------------------------------------------------------------- #
# - The 'LIBS' tells the compiler where to find libraries.                     #
# - The 'LDFLAGS' tells the linker where to find external libraries (-L flag). #
# - The 'LDLIBS' tells the linker the prefix of external libraries (-l flag).  #
# - The 'CPPFLAGS' tells the compiler where to find preprocessors (-I flag).   #
# - The 'CFLAGS' configures the compiler options.                              #
# ---------------------------------------------------------------------------- #

LIBS		= \
			  $(DIR_LIBS)/libft/libft.a				\
			  $(DIR_LIBS)/printf/libprintf.a		\

LDFLAGS		= \
			  -L $(DIR_LIBS)/libft					\
			  -L $(DIR_LIBS)/printf					\

LDLIBS		= \
			  -lft									\
			  -lprintf								\
			  -lncurses								\

CPPFLAGS	= \
			  -I$(DIR_INCS)							\
			  -I$(DIR_LIBS)/libft/$(DIR_INCS)		\
			  -I$(DIR_LIBS)/printf/$(DIR_INCS)		\

CFLAGS		= \
			  -g									\
			  -Wall -Werror -Wextra					\

# ---------------------------------------------------------------------------- #
# /!\ SOURCE NORMALIZATION AND COMPILATION RULES /!\                           #
# ---------------------------------------------------------------------------- #

DEPFLAGS	= \
			  -MT $@ -MMD -MP -MF $(DIR_DEPS)/$*.Td	\

COMPILE.c	= $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

POSTCOMPILE	= mv -f $(DIR_DEPS)/$*.Td $(DIR_DEPS)/$*.d

C_SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS))
O_SRCS = $(addprefix $(DIR_OBJS)/,$(SRCS:.c=.o))

$(DIR_OBJS)	:
	@mkdir -p $(DIR_OBJS)
$(DIR_DEPS) :
	@mkdir -p $(DIR_DEPS)

# ---------------------------------------------------------------------------- #
# PUBLIC RULES                                                                 #
# ---------------------------------------------------------------------------- #
# The rules must contain at least :                                            #
# - all        make libs and target                                            #
# - $(NAME)    make binaries and target                                        #
# - libs       build static libraries                                          #
# - clean      remove binaries                                                 #
# - fclean     remove binaries and target                                      #
# - fcleanlibs apply fclean rule on libraries                                  #
# - re         remove binaries, target and libraries and build the target      #
#                                                                              #
# To compile a static library, the $(NAME) rule should be :                    #
#     '$(AR) $(ARFLAGS) $(NAME) $(OBJ)'                                        #
#     'ranlib $(NAME)'                                                         #
#                                                                              #
# To compile a C binary, the $(NAME) rule should be :                          #
#     '$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)'                           #
# ---------------------------------------------------------------------------- #

all : libs $(NAME)

$(NAME)		: $(DIR_OBJS) $(DIR_DEPS) $(O_SRCS) $(LIBS)
	@$(CC) $(O_SRCS) -o  $(NAME) $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)[ Created Executable ]$(RST) %s\n" $(NAME)

libs		:
	@make -C $(DIR_LIBS)/libft
	@make -C $(DIR_LIBS)/printf

fcleanlibs	:
	@make -C $(DIR_LIBS)/libft fclean
	@make -C $(DIR_LIBS)/printf fclean

clean		: 
	@$(RM) $(DIR_OBJS)
	@$(RM) $(DIR_DEPS)
	@printf "$(RED)[ Deleted directory ] $(RST)%s\n$(RED)[ Deleted directory ] $(RST)%s\n" $(DIR_DEPS) $(DIR_OBJS)
	

fclean		: fcleanlibs clean
	@$(RM)	$(NAME)
	@printf "$(RED)[ Deleted executable ] $(RST) %s\n" $(NAME)

re			: fclean all

# ---------------------------------------------------------------------------- #
#						 	/!\ CUSTOM RULES /!\							   #
# ---------------------------------------------------------------------------- #

norme		:
	@/usr/bin/norminette  */**/*.[ch]

git			:
	@git add -A
	@git commit -m "Done"
	@git push origin master

exe			:
	make && ./$(NAME)

leaks		:
	while true ; do leaks $(NAME)| grep 'total\|malloced' ; sleep 3 ; clear ; done

leaks1		:
	while true ; do leaks $(NAME) ; sleep 3 ; clear ; done

log			:
	while true ; do cat logger ; sleep 2 ; clear ; done

# ---------------------------------------------------------------------------- #
#						 	/!\ PRIVATE RULES /!\							   #
# ---------------------------------------------------------------------------- #

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c
$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(DIR_DEPS)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(word 2, $^))
	@printf "$(YEL)[ Checked ]$(RST) $(word 2,$^)\n"
	@printf "$(GRN)[ Created ]$(RST) $@  \n" 
	@$(COMPILE.c) $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

$(DIR_DEPS)/%.d	: ;
.PRECIOUS		: $(DIR_DEPS)/%.d
-include $(patsubst %,$(DIR_DEPS)/%.d,$(basename $(C_SRCS)))

# ---------------------------------------------------------------------------- #

.PHONY	:	all clean fclean re $(DIR_OBJS)/%.o $(DIR_DEPS)/%.d libs

# ---------------------------------------------------------------------------- #
