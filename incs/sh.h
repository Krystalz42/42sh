/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:07:41 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/24 15:36:19 by sbelazou         ###   ########.fr       */
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
# include <builtins.h>

/*
** A VIRER
*/

void pjt(t_jobs jobs, int index);
void pj(t_process identify, int index, char *inc);

/*
**				FUNCTION CORES
*/

int							shell(void);
int							cursor_placement(void);
void						insert_one_line(void);
void						exit_(void);

/*
**				FUNCTION READ && PRINT && RETURN A STRUCT
*/

char						*read_stdin(unsigned char flags);
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
char						*finish_read_std(t_read **read_std);
t_cmd						*keep_buffer(t_cmd *cmd, int flags);
t_cmd						*key_del_fct(t_cmd *cmd, unsigned long buff);
int							signal_reception(int brk);

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

int							check_if_builtin(char **command, char **env);
uint8_t						builtin_background(char **command, char **env);
uint8_t						builtin_foreground(char **command, char **env);
uint8_t						hash_reset(void);
uint8_t						hash_print(int fd);
uint8_t						b_write_history(void);
uint8_t						b_clear_history(void);
uint8_t						b_delete_history_offset(int offset);
uint8_t						write_history_in_sh(char *pathname);
uint8_t						builtin_jobs(char **command, char **env);
uint8_t						builtin_hash(char **command, char **env);
uint8_t						builtin_history(char **command, char **env);
uint8_t						builtin_kill(char **command, char **env);
uint8_t						builtin_env(char **command, char **env);
uint8_t						builtin_exit(char **command, char **env);

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
int							print_tab(t_read **read_std);
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

int							key_print_(t_read **read_std, unsigned long *buff);
int							key_tab(t_read **read_std, unsigned long buff);
int							key_enter_(t_read **read_std, unsigned long buff);
int							key_interrupt(t_read **read_std,
											unsigned long buff);
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

/*
**				SEARCH HISTORY FUNCTION
*/

int							init_research(t_read **read_std);
int							print_struct_history(t_read **read_std);
int							reset_cur_hist(t_lfh *hist);
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
size_t						compare_environment(char *s1, char *s2);
void						remove_environment(char *string);
char						**env_table(char **env, int flags);
int							usage_environement(char *string);
int						start_from_null(char **command, char ***env);
int						start_from_full(char **command, char ***env);
int						start_from_less(char **command, char ***env);

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
uint8_t						b_write_history_in_file(char *path);

/*
**				PARSING FUNCTION
*/



void						lexing(t_parsing **new, char *str);
void						last(t_parsing **node);
void						operaters(t_parsing **node);
void						commands(t_parsing **node);
t_parsing					*parsing(char *str);
void						stds(t_parsing *node);
void						redirections(t_parsing **node);

/*
**				BASIC FUNCTION
*/

void						ptrnext(t_parsing **node, size_t stop);
void						lstdel(t_parsing **node);
void						lstnew(t_parsing **node, char *str);
size_t						lstlen(t_parsing *node);
void						arraydel(char ***array);

/*
**				TOOL'S PARSING FUNTION
*/

bool						chk_operaters(char c);
bool						chk_slash(const char *str, size_t index);
void						chk_quotes(char c, char quote, const int *flag,
							int *value);

/*
**				JOB'S CONTROL FUNCTION
*/
int							update_status(t_process *process);
void						update_jobs(t_process *process);
t_jobs						*jobs_table(void);
void						my_execve(char **command, char **env);
void						handler_sigchld(int sig);
int							get_jobs_index(pid_t search);
void						my_wait(int index);
void						reset_process(t_process *to_kill);
int							terminate_process(t_process *process);
void						modify_runing(t_process *process, bool change);
void						modify_foreground(t_process *process, bool change);
void						print_status(t_process *process, int index);
void						wait_process(t_process *process, int index);
void						set_fildes(pid_t pgid);
const char					*status_signal(int signal);
const char					*status_exit(int signal);

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

/*
**			   	ERROR FUNCTION
*/

uint8_t						error_builtin(char *from, char *error, char *args);
void						*error_env(void);
void						puterror(char *err);
int							bip(void);

#endif
