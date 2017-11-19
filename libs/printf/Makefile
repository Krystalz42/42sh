
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/30 22:26:52 by aroulin           #+#    #+#              #
#    Updated: 2017/08/30 22:26:54 by aroulin          ###   ########.fr        #
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
RL			= ranlib

# ---------------------------------------------------------------------------- #
#                                                                              #
# TARGET SETUP                                                                 #
#                                                                              #
# ---------------------------------------------------------------------------- #
# - The 'NAME' variable must contain the expected name of the output target.   #
# - The 'SRCS' variable must contain the list of the source files without the  #
# base prefix of the directory.                                                #
# ---------------------------------------------------------------------------- #

NAME		= libprintf.a

SRCS = \
		ft_printf.c \
		ft_vector.c \
		ft_handle_spec.c \
		ft_fmt_parse.c \
		ft_num_conv.c \
		ft_pfhandle.c \
		ft_chr_conv.c \
		ft_str_conv.c \
		ft_wstr_conv.c \
		ft_xou_conv.c \
		ft_float_conv.c \
		ft_pfbonus.c

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

LDFLAGS		= \

LDLIBS		= \

CPPFLAGS	= \
			  -I$(DIR_INCS)	\
			  -I../libft/$(DIR_INCS)\

CFLAGS		= \
			  -Wall -Werror -Wextra	\

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

all : $(NAME)

$(NAME)		: $(DIR_OBJS) $(DIR_DEPS) $(O_SRCS) $(LIBS)
	@$(AR) $(ARFLAGS) $(NAME) $(O_SRCS)
	@$(RL) $(NAME)
	@printf "$(GRN)[ Created Library ]$(RST) %s\n" $(NAME)


clean		:
	@$(RM) $(DIR_OBJS)
	@$(RM) $(DIR_DEPS)
	@printf "$(RED)[ Deleted directory ] $(RST)%s\n$(RED)[ Deleted directory ] $(RST)%s\n" $(DIR_LIBS)/libft/$(DIR_DEPS) $(DIR_LIBS)/libft/$(DIR_OBJS)

fclean		: clean
	@$(RM)	$(NAME)
	@printf "$(RED)[ Deleted Library ] $(RST) %s\n" $(NAME)

re			: fclean all

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(DIR_DEPS)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(word 2, $^))
	@printf "$(YEL)[ Checked ]$(RST) $(word 2,$^)\n"
	@printf "\033[32m[ Created ]\033[0m $@\n"
	@$(COMPILE.c) $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

$(DIR_DEPS)/%.d	: ;

.PRECIOUS		: $(DIR_DEPS)/%.d


-include $(patsubst %,$(DIR_DEPS)/%.d,$(basename $(C_SRCS)))

.PHONY	:	all clean fclean re $(DIR_OBJS)/%.o $(DIR_DEPS)/%.d





