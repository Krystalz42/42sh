# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/30 22:26:42 by aroulin           #+#    #+#              #
#    Updated: 2017/11/15 20:24:40 by jle-quel         ###   ########.fr        #
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

NAME		= libft.a

SRCS = \
	   ft_atoi.c				\
	   ft_atoui.c				\
	   ft_firstchar.c			\
	   ft_tablen.c				\
	   ft_isread.c				\
	   ft_atoi_base.c			\
	   ft_bzero.c				\
	   ft_chrchar.c				\
	   ft_convert_base.c		\
	   ft_convert_ubase.c		\
	   ft_countchar.c			\
	   ft_debug.c				\
	   ft_filetostr.c			\
	   ft_ftoa.c				\
	   ft_isalnum.c				\
	   ft_iscrlf.c				\
	   ft_isalpha.c				\
	   ft_isascii.c				\
	   ft_isdigit.c				\
	   ft_islower.c				\
	   ft_isprint.c				\
	   ft_isupper.c				\
	   ft_itoa.c				\
	   ft_itounssigned.c		\
	   ft_lltoa.c				\
	   ft_ltoa.c				\
	   ft_memalloc.c			\
	   ft_memccpy.c				\
	   ft_memchr.c				\
	   ft_memcmp.c				\
	   ft_memcpy.c				\
	   ft_memdel.c				\
	   ft_memdel_tab.c			\
	   ft_memmove.c				\
	   ft_memset.c				\
	   ft_nbrlen.c				\
	   ft_newcat.c				\
	   ft_putchar.c				\
	   ft_putchar_fd.c			\
	   ft_putendl.c				\
	   ft_putendl_fd.c			\
	   ft_putnbr.c				\
	   ft_putnbr_fd.c			\
	   ft_putstr.c				\
	   ft_putstr_fd.c			\
	   ft_putstrtab.c			\
	   ft_putstrtab_fd.c		\
	   ft_realloc.c				\
	   ft_recursive_power.c		\
	   ft_split.c				\
	   ft_stoa.c				\
	   ft_str_charnout.c		\
	   ft_str_charnoutrev.c		\
	   ft_str_charout.c			\
	   ft_str_to_tab.c			\
	   ft_str_tolower.c			\
	   ft_str_toupper.c			\
	   ft_strcat.c				\
	   ft_strchr.c				\
	   ft_strclr.c				\
	   ft_strcmp.c				\
	   ft_strcpy.c				\
	   ft_strdel.c				\
	   ft_strdup.c				\
	   ft_strequ.c				\
	   ft_striter.c				\
	   ft_striteri.c			\
	   ft_strjoin.c				\
	   ft_strlcat.c				\
	   ft_strlen.c				\
	   ft_strmap.c				\
	   ft_strmapi.c				\
	   ft_strncat.c				\
	   ft_strncmp.c				\
	   ft_strncpy.c				\
	   ft_strnequ.c				\
	   ft_strnew.c				\
	   my_gnl.c					\
	   ft_strnstr.c				\
	   ft_strrchr.c				\
	   ft_strrev.c				\
	   ft_strsplit.c			\
	   ft_strstr.c				\
	   ft_strsub.c				\
	   ft_strtrim.c				\
	   ft_tolower.c				\
	   ft_toupper.c				\
	   ft_uitoa.c				\
	   ft_ulltoa.c				\
	   ft_ultoa.c				\
	   ft_ustoa.c				\
	   ft_ustrncmp.c			\
	   ft_double_delete.c		\
	   get_next_line.c			\
	   ft_strisdigit.c			\
	   ft_strisalpha.c			\
	   ft_recalloc.c			\
	   ft_uimaxtoa_base.c		\
	   ft_imaxtoa.c				\
	   ft_insrt_to_str.c		\
	   ft_findchr.c				\
	   ft_strndup.c				\

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
			  -I$(DIR_INCS)				\
			  -I../libft/$(DIR_INCS)	\

CFLAGS		= \
			  -Wall -Werror -Wextra		\

# ---------------------------------------------------------------------------- #
# /!\ SOURCE NORMALIZATION AND COMPILATION RULES /!\                           #
# ---------------------------------------------------------------------------- #

DEPFLAGS	= \
			  -MT $@ -MMD -MP -MF $(DIR_DEPS)/$*.Td			\

COMPILE.c	= $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c	\

POSTCOMPILE	= mv -f $(DIR_DEPS)/$*.Td $(DIR_DEPS)/$*.d		\

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
