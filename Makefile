# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 18:36:59 by aroulin           #+#    #+#              #
#    Updated: 2017/12/20 16:08:19 by jle-quel         ###   ########.fr        #
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
	   cores/main.c												\
	   cores/shell.c											\
	   cores/insert_one_line.c									\
	   cores/var_return.c										\
	   cores/exit.c												\
	   alias/init_rc.c											\
	   alias/alias.c											\
	   alias/tools.c											\
	   read/other_read/read_stdin.c								\
	   read/other_read/read_input.c								\
	   read/other_read/cursor_column.c							\
	   read/other_read/my_tgetnum.c								\
	   read/other_read/finish_read_std.c						\
	   read/other_read/read_gates.c								\
	   read/other_read/print_struct.c							\
	   read/other_read/my_put.c									\
	   read/other_read/first_cmd.c								\
	   read/other_read/prompt.c									\
	   read/other_read/check_cmd.c								\
	   read/other_read/gbl_save_read.c							\
	   read/other_read/keep_buffer.c							\
	   read/other_read/init_struct_for_read.c					\
	   read/other_read/last_cmd.c								\
	   read/other_read/restore_cursor.c							\
	   read/other_read/init_prompt.c							\
	   read/other_read/my_prompt.c								\
	   read/other_read/get_len_prompt.c							\
	   read/other_read/signal_reception.c						\
	   read/key_/key_yank.c										\
	   read/key_/key_print.c									\
	   read/key_/key_delete.c									\
	   read/key_/key_shift.c									\
	   read/key_/key_capitalize_word.c							\
	   read/key_/key_home_end.c									\
	   read/key_/key_eof.c										\
	   read/key_/key_tabulation.c								\
	   read/key_/key_arrow.c									\
	   read/key_/key_delete_here.c								\
	   read/key_/key_enter.c									\
	   read/key_/key_interrupt.c								\
	   read/key_/key_clear.c									\
	   read/key_/key_undo.c										\
	   read/key_/key_reprint.c									\
	   read/key_/key_kill_k.c									\
	   read/key_/key_kill_word.c								\
	   read/key_/key_kill_prev_word.c							\
	   read/key_/key_del_buff.c									\
	   read/key_/key_search_history.c							\
	   read/key_/key_upcase_word.c								\
	   read/key_/key_refresh.c									\
	   read/key_/key_downcase_word.c							\
	   hash/hash_value.c										\
	   hash/table_hash.c										\
	   hash/hash_board.c										\
	   hash/built_in_hash.c										\
	   hash/get_str_from_hash.c									\
	   read/outstanding/add_outstanding.c						\
	   read/outstanding/get_os_pointer.c						\
	   read/completion/init_tab.c								\
	   read/completion/check_binary_path.c						\
	   read/completion/color_completion.c						\
	   read/completion/update_index.c							\
	   read/completion/my_togo.c								\
	   read/completion/init_completion.c						\
	   read/completion/move_vertical.c							\
	   read/completion/print_tab.c								\
	   read/completion/complete_path.c							\
	   read/completion/continue_completion.c					\
	   read/completion/move_horizontal.c						\
	   read/completion/complete_binary.c						\
	   read/completion/create_comp.c							\
	   read/completion/init_files.c								\
	   read/completion/completion.c								\
	   read/search_history/compare_history.c					\
	   read/search_history/compare_list.c						\
	   read/search_history/first_history.c						\
	   read/search_history/last_result.c						\
	   read/search_history/init_research.c						\
	   read/search_history/print_struct_history.c				\
	   read/search_history/manage_cursor_prompt.c				\
	   history/built_in_history.c								\
	   history/get_str_from_history.c							\
	   history/write_history.c									\
	   history/reset_history.c									\
	   history/init_history.c									\
	   history/previous_history.c								\
	   history/next_history.c									\
	   history/make_list_hist.c									\
	   history/gbl_save_history.c								\
	   history/copy_cmd.c										\
	   signal/ft_signal.c										\
	   execution/check_if_builtins.c							\
	   execution/executing_node.c								\
	   execution/my_fork.c										\
	   execution/tools/redirection_tools.c						\
	   execution/tools/get_real_env.c							\
	   execution/tools/looking_for_path.c						\
	   execution/tools/manage_pipe.c							\
	   execution/tools/new_jobs.c								\
	   execution/tools/check_tree_path.c						\
	   execution/tools/do_heredoc.c								\
	   execution/tools/do_string.c								\
	   execution/tools/get_process.c							\
	   execution/tools/find_executing_node.c					\
	   execution/tools/check_path.c								\
	   execution/tools/tools_heredoc.c							\
	   execution/tools/potential_option.c						\
	   execution/tools/manage_use.c								\
	   execution/tools/alias_tools.c							\
	   execution/tools/close_fd.c								\
	   execution/executing_function/op_execution.c				\
	   execution/executing_function/op_great_and.c				\
	   execution/executing_function/op_great.c					\
	   execution/executing_function/op_dgreat.c					\
	   execution/executing_function/op_dless.c					\
	   execution/executing_function/op_lessgreat.c				\
	   execution/executing_function/op_or_if.c					\
	   execution/executing_function/op_and_if.c					\
	   execution/executing_function/op_less.c					\
	   execution/executing_function/op_string.c					\
	   execution/executing_function/op_less_and.c				\
	   execution/executing_function/op_pipeline.c				\
	   execution/executing_function/op_separator.c				\
	   execution/executing_function/op_ampersand.c				\
	   execution/builtins_functions/builtin_jobs.c				\
	   execution/builtins_functions/builtin_alias.c				\
	   execution/builtins_functions/builtin_suspend.c			\
	   execution/builtins_functions/builtin_kill.c				\
	   execution/builtins_functions/builtin_switch.c			\
	   execution/builtins_functions/builtin_switch2.c			\
	   execution/builtins_functions/builtin_history.c			\
	   execution/builtins_functions/builtin_hash.c				\
	   execution/builtins_functions/builtin_env.c				\
	   execution/builtins_functions/builtin_exit.c				\
	   execution/builtins_functions/builtin_data.c				\
	   execution/builtins_functions/builtin_help.c				\
	   execution/builtins_functions/basic_help.c				\
	   execution/builtins_functions/builtin_cd.c				\
	   execution/builtins_functions/builtin_echo.c				\
	   execution/builtins_functions/builtin_setenv.c			\
	   execution/builtins_functions/builtin_unsetenv.c			\
	   execution/builtins_functions/builtin_refresh.c			\
	   execution/builtins_functions/builtin_tools.c				\
	   execution/builtins_functions/builtin_kill2.c				\
	   jobs_control/modify_status_jobs.c						\
	   jobs_control/status_signals.c							\
	   jobs_control/jobs_control.c								\
	   jobs_control/set_process.c								\
	   jobs_control/my_wait.c									\
	   jobs_control/print_process.c								\
	   jobs_control/my_execve.c									\
	   jobs_control/get_real_jobs.c								\
	   parsing/parsing.c										\
	   parsing/lexing/special_tokenisation.c					\
	   parsing/lexing/regular_tokenisation.c					\
	   parsing/lexing/lexer.c									\
	   parsing/lexing/recognition.c								\
	   parsing/parsing/parsing.c								\
	   parsing/expanding/argv.c									\
	   parsing/expanding/alias.c								\
	   parsing/expanding/argv_tools.c							\
	   parsing/expanding/special.c								\
	   parsing/expanding/tilde.c								\
	   parsing/expanding/variable.c								\
	   parsing/expanding/escape.c								\
	   parsing/expanding/split.c								\
	   parsing/expanding/split_tools.c							\
	   parsing/expanding/tools.c								\
	   parsing/tools/list.c										\
	   parsing/tools/error.c									\
	   binary_tree/binary_tree.c								\
	   env/add_environment.c									\
	   env/remove_environment.c									\
	   env/init_env.c											\
	   env/my_getenv.c											\
	   env/initialise_environment.c								\
	   term/init_fd.c											\
	   term/init_term.c											\
	   term/set_term.c											\
	   term/keep_term_struct.c									\
	   memdel_struct/memdel_jobs.c      						\
	   memdel_struct/memdel_outstanding.c						\
	   memdel_struct/memdel_completion.c						\
	   memdel_struct/memdel_search_history.c					\
	   memdel_struct/memdel_read.c								\
	   memdel_struct/memdel_parsing.c							\
	   error_function/bip.c										\
	   error_function/usage_builtins.c							\
	   error_function/usage_builtins2.c							\
	   error_function/usage_builtins3.c							\

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
			  -g3									\
			  -fsanitize=address					\

CPPFLAGS	= \
			  -I$(DIR_INCS)							\
			  -I$(DIR_LIBS)/libft/$(DIR_INCS)		\
			  -I$(DIR_LIBS)/printf/$(DIR_INCS)		\

CFLAGS		= \
			  -Wall -Werror -Wextra					\
			  -g3									\
			  -fsanitize=address					\

# ---------------------------------------------------------------------------- #
# /!\ SOURCE NORMALIZATION AND COMPILATION RULES /!\                           #
# ---------------------------------------------------------------------------- #

DEPFLAGS	= \
			  -MT $@ -MMD -MP -MF $(DIR_DEPS)/$*.Td	\

COMPILE.c	= \
			$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c \

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
	while true ; do leaks $(NAME) ; sleep 5 ; clear ; done

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
