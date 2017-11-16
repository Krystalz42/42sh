/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:07:41 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/15 20:44:59 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <errno.h>
# include <libft.h>
# include <ft_printf.h>
# include <unistd.h>
# include <define.h>
# include <struct.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <logger.h>
# include <logger_utils.h>
# include <enum.h>
# include <time.h>

/*
**				FUNCTION CORES
*/

int							shell(void);
void						insert_one_line(void);
void						exit_(void);
uint8_t						var_return(int ret);

/*
**				FUNCTION READ && PRINT && RETURN A STRUCT
*/

t_cmd						*read_stdin(unsigned char flags);
char						*my_prompt(char *prompt);
void						init_prompt(void);
t_cursor					prompt(unsigned char flags);
t_cmd						*create_element(char c);
int							print_struct(t_read *read_std);
int							my_put(int c);
t_read						*init_struct_for_read(void);
t_cmd						*first_cmd(t_cmd *cmd, int history);
t_cmd						*gbl_save_read(t_cmd *read_std);
int							print_list(int to_select, t_cmd *cmd,
										t_cmd *stop, t_cursor *cur);
void						restore_cursor_(t_cursor cur);
int							check_cmd(t_read **read_std);
int							get_len_prompt(int len);
t_cmd						*last_cmd(t_cmd *cmd);
t_cmd						*finish_read_std(t_read **read_std);
t_cmd						*keep_buffer(t_cmd *cmd, int flags);
t_cmd						*key_del_fct(t_cmd *cmd, unsigned long buff);
int							signal_reception(int brk);
void						initialize_fct(t_read **read_std,
										unsigned char flags);
t_cmd						*finitialize_fct(t_read **read_std);
int							tgetli(void);
int							tgetco(void);
int							cursor_column(int new_line);

/*
**				OUTSTANDING FUNCTION
*/

void						add_outstanding(t_cmd *cmd,
										unsigned long move, unsigned long buff);
t_outstanding				*get_os_pointer(t_outstanding *get,
																	int flags);

/*
**				HASH FUNCTION
*/

unsigned int				hash_value(char *str);
void						inventory_hash(unsigned int new_index);
t_hash						**hash_board(void);
unsigned int				*index_of_hash(void);
char						*search_path(char *binary);
void						add_hash(char *bin, char *path,
														size_t index);

/*
**				BUILT IN FUNCTION
*/

int							check_if_builtin(t_node *node, int info);
uint8_t						builtin_background(t_node *node, int info);
uint8_t						builtin_foreground(t_node *node, int info);
uint8_t						builtin_jobs(t_node *node, int info);
uint8_t						builtin_suspend(t_node *node, int info);
uint8_t						builtin_hash(t_node *node, int info);
uint8_t						builtin_history(t_node *node, int info);
uint8_t						builtin_kill(t_node *node, int info);
uint8_t						builtin_env(t_node *node, int info);
uint8_t						builtin_exit(t_node *node, int info);
uint8_t						builtin_help(t_node *node, int info);
uint8_t						builtin_echo(t_node *node, int info);
uint8_t						builtin_cd(t_node *node, int info);
uint8_t						builtin_setenv(t_node *node, int info);

/*
**				BUILT IN OPTION
*/

uint8_t						hash_reset(void);
uint8_t						b_write_history(void);
uint8_t						b_clear_history(void);
uint8_t						hash_print(int fd);
uint8_t						b_delete_history_offset(int offset);
uint8_t						write_history_in_sh(char *pathname);
uint8_t						kill_process(char *string1, char *string2);
uint8_t						signal_from_int(uint8_t signal);
uint8_t						signal_from_str(char *status);
uint8_t						b_write_history_in_file(char *path);
uint8_t						all_signal(void);
int							start_from_null(char **command, char ***env);
int							start_from_full(char **command, char ***env);
int							start_from_less(char **command, char ***env);

/*
**				BUILT IN TOOLS
*/

void						check_path(char *path);
int							check_directory(char *path);
void						collect_path(char **binary);
int							looking_for_path(char **binary);
t_bdata						*b_data(void);
signed int					search_in_tab(char **data, char *var);
char						**refresh_varenv(char **env);
char						*ft_path(char *var, unsigned int begin);
char						*add_envar(char *var, char *value);
char						**init_pwd(char **env);
unsigned int				search_char(char *str, char c);
uint8_t						builtin_unsetenv(t_node *node, int info);
int							potential_option(char *potential, int c);


/*
**				FUNCTION FOR COMPLETION
*/

void						insert_completion(t_read **read_std, t_file *tmp);
void						move_completion_right(t_read **read_std);
void						move_completion_left(t_read **read_std);
void						move_vertical(t_read **read_std, int pos);
int							is_token(char c);
void						complete_binary(t_read **read_std);
char						*list_to_str(t_read **read_std, t_cmd *cmd);
int							place_cursor(t_read **read_std, int t);
void						reset(t_read **read_std, int to);
int							check_word(t_cmd *cmd);
int							len_cmd(t_cmd **cmd);
void						print_tab(t_read **read_std);
int							my_togo(int li, int co);
int							my_tobackto(int li, int co);
void						back_completion(t_read **read_std);
void						add_little_char(unsigned char type);
void						init_completion(t_read **read_std);
void						complete_path(t_read **read_std, t_path f);
void						continue_completion(t_read **read_std);
void						complete_command(t_read **read_std);
int							print_element(t_file *file, int color);
void						create_comp(t_read **read_std, t_path f);
void						color_completion(unsigned char type, int color);
void						init_files(t_file **file, char *name,
									unsigned char type, int index);
void						completion(t_read **read_std);
void						update_index(t_read **read_std, int i);
int							init_tab_(t_tab *tab_, int li);
static inline int			management_wildcard(char *data, char *comp);

/*
**				POINTER ON FUNCTION FOR READ
*/
int							key_capitalize_word(t_read **read_std,
												unsigned long buff);
int							key_print_(t_read **read_std, unsigned long *buff);
int							key_tab(t_read **read_std, unsigned long buff);
int							key_enter_(t_read **read_std, unsigned long buff);
int							key_clear_(t_read **read_std, unsigned long buff);
int							key_eof(t_read **read_std, unsigned long buff);
int							key_upcase_word(t_read **read_std,
										unsigned long buff);
int							key_downcase_word(t_read **read_std,
												unsigned long buff);
int							key_arrow_left(t_read **read_std,
											unsigned long buff);
int							key_arrow_right(t_read **read_std,
											unsigned long buff);
int							key_arrow_up(t_read **read_std, unsigned long buff);
int							key_arrow_down(t_read **read_std,
											unsigned long buff);
int							key_home_(t_read **read_std, unsigned long buff);
int							key_del(t_read **read_std, unsigned long buff);
int							key_shift_up(t_read **read, unsigned long buff);
int							key_shift_down(t_read **read, unsigned long buff);
int							key_shift_left(t_read **read, unsigned long buff);
int							key_shift_right(t_read **read, unsigned long buff);
int							key_end_(t_read **read_std, unsigned long buff);
int							key_delete_here(t_read **read_std,
											unsigned long buff);
int							key_search_history(t_read **read_std,
												unsigned long buff);
int							key_undo_(t_read **read_std, unsigned long buff);
int							key_reprint(t_read **read_std, unsigned long buff);
int							key_reprint_here(t_read **read_std,
												unsigned long buff);
int							key_kill_k(t_read **read_std, unsigned long buff);
int							key_kill_word(t_read **read_std,
											unsigned long buff);
int							key_kill_prev_word(t_read **read_std,
												unsigned long buff);
int							key_del_buff(t_read **read_std, unsigned long buff);
int							key_yank(t_read **read_std, unsigned long buff);
int							key_refresh_(t_read **read_std, unsigned long buff);
int							capitalize_word_undo(t_read **read_std,
													unsigned long buff);

/*
**				SEARCH HISTORY FUNCTION
*/

int							init_research(t_read **read_std);
int							print_struct_history(t_read **read_std);
t_cursor					prompt_history(int p);
int							new_line_after_bloc(t_read **read_std, int to);
int							key_print_fct(t_cmd *cmd, char c);
void						compare_history(t_read **read_std);
int							list_compare(t_cmd *little, t_cmd *big);
t_hist						*first_history(void);
int							last_resultat(int res);
char						*get_str_from_history(void);

/*
**				ENVIRONEMENT FUNCTION
*/

void						add_environment(char *string);
void						init_env(void);
char						*my_getenv(char *name);
size_t						compare_environment(const char *s1, const char *s2);
void						remove_environment(char *string);
char						**env_table(char **env, int flags);
char						**get_real_env(t_node *node);

/*
**				HISTORY FUNCTION
*/

t_hist						*set_history_to_last(void);
void						reset_history(void);
void						copy_cmd(t_read **read_std, t_cmd *cpy);
t_hist						*gbl_save_history(t_hist *hist, int flags);
void						make_list_hist(t_read *read_std);
void						previous_history(t_read **read_std);
void						next_history(t_read **read_std);

/*
**				LEXING FUNCTION
*/

t_parsing					*parsing(t_cmd *cmd);
void						special_tokenisation(t_cmd *cmd);
void						regular_tokenisation(t_cmd *cmd);
void						lexer(t_cmd *cmd, t_parsing **node);
void						recognition(t_parsing *node);

/*
**				PARSING FUNCTION
*/

void						empty(t_parsing **node);
void						syntax(t_parsing **node);
void						order(t_parsing **node);

/*
**				EXPANDING FUNCTION
*/

void						argv(t_parsing *node);
void						escape(t_parsing *node);
void						special(t_parsing *node, char *expand,
									int to_expand);
void						tilde(t_parsing *node);
void						split(t_parsing *node);
void						variable(t_parsing *node);

/*
**				TOOLS'S LEXING PARSING EXPANDING FUNCTION
*/

bool						chk_add_argv(t_parsing *node);
bool						chk_get_argv(t_parsing *node);
uint8_t						chk_slash(char c, uint8_t *status);
uint8_t						chk_quote(char c, uint8_t *status);
char						*do_skip(char *str, char c);
char						**ft_arrayjoin(char **a1, char **a2);
char						**ft_arraysub(char **argv, size_t start,
										size_t length);
int							isquote(char c);
size_t						skip_to_occurence(char *str, char c);
size_t						get_wordlength(char *str);
size_t						ft_arraylen(char **argv);
void						ft_err(char *str, int err);

/*
**				BASIC FUNCTION
*/

void						lstdel(t_parsing **node);
void						lstadd(t_parsing *node, t_parsing *new);
t_parsing					*lstnew(char *input);

/*
**				CREATE BINARY TREE
*/

t_node						*create_binary_tree(t_parsing *list,
												t_parsing *compare,
												int priority);
uint8_t						execute_node(t_node *node, t_jobs *jobs, int info);
void						check_tree_path(t_node *node);
void						do_heredoc(t_node *node);

/*
**				JOB'S CONTROL FUNCTION
*/

t_process					*my_fork(t_jobs *jobs, t_node *node, int info);
t_jobs						*new_jobs(t_jobs *jobs);
t_process					*new_process(t_jobs *jobs);
void						close_fildes(t_process *process);
void						print_info_jobs(t_jobs *jobs);
t_node						*find_executing_node(t_node *node);
void						first_process(t_jobs *jobs);
void						reset_process(t_jobs *jobs);
void						wait_process(t_jobs *jobs);
void						update_jobs(t_process *process);
int							wait_group(t_process *process, int option);
int							finish_process(t_process *process);
t_jobs						*jobs_table(void);
void						my_execve(char **command, char **env);
void						handler_sigchld(int sig);
void						my_wait(t_jobs *jobs);
int							terminate_process(t_process *process);
void						modify_runing(t_process *process, bool change);
void						modify_foreground(t_process *process, bool change);
void						set_fildes(pid_t pgid);
const char					*status_signal(int signal);
const char					*status_exit(int signal);

/*
**				EXECUTION FUNCTION
*/

uint8_t						op_execution(t_node *node, t_jobs *jobs, int info);
uint8_t						op_separator(t_node *node, t_jobs *jobs, int info);
uint8_t						op_pipeline(t_node *node, t_jobs *jobs, int info);
uint8_t						op_dless(t_node *node, t_jobs *jobs, int info);
uint8_t						op_ampersand(t_node *node, t_jobs *jobs, int info);
uint8_t						op_and_if(t_node *node, t_jobs *jobs, int info);
uint8_t						op_or_if(t_node *node, t_jobs *jobs, int info);
uint8_t						op_less(t_node *node, t_jobs *jobs, int info);
uint8_t						op_great(t_node *node, t_jobs *jobs, int info);
uint8_t						op_great_and(t_node *node, t_jobs *jobs, int info);
uint8_t						op_dgreat(t_node *node, t_jobs *jobs, int info);

/*
**				TOOL'S EXECUTION
*/

int							compare_heredoc(t_cmd *cmd, char *string);
char						**build_table(char **heredoc, char *str);
char						*convert_to_str(t_cmd *cmd);
int							read_pipe(int *fildes);
int							close_pipe(int *fildes);
int							write_pipe(int *fildes);
char						*create_trial_path(char *path, char *binary);

/*
**				PRINT PROCESS
*/

void						print_status(t_process *process, int jobs_spec);
int							print_process(t_process *process, int option,
											int index);
uint8_t						print_jobs(t_jobs *jobs, int option);

/*
**				SIGNAL FUNCTION
*/

void						init_signal(void);
void						reset_signal(void);

/*
**				TERMIOS FUNCTION
*/

struct termios				keep_term_struct(unsigned short flags,
											struct termios *term);
void						set_termios(unsigned short flags);
int							init_fd(void);
int							init_term(void);

/*
**				FUNCTION MEMDEL STRUCTUR
*/

int							memdel_completion(t_tab **tab_);
int							memdel_read(t_read **read_std);
int							memdel_lfh(t_lfh **hist_search);
int							memdel_cmd(t_cmd **cmd);
void						memdel_outstanding(void);
void						memdel_node(t_node **node);

/*
**				ERROR FUNCTION
*/

uint8_t						error_msg(char *from, char *error, char *args);
int							bip(void);
uint8_t						usage_kill(void);
uint8_t						usage_jobs(void);
uint8_t						usage_history(void);
uint8_t						usage_env(void);
uint8_t						usage_hash(void);
uint8_t						usage_unsetenv(void);
uint8_t						usage_setenv(void);
int							create_fildes(char *path, int option, int chmod);
uint8_t						usage_background(void);
uint8_t						usage_foreground(void);
uint8_t						usage_cd(void);
int							help_move(void);
int							help_kill_and_yank(void);
int							help_history(void);

#endif
