/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:07:41 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:07:00 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include <libft.h>
#include <unistd.h>
#include <struct.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <define.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

//DEBUG
int fdb;

int					shell(void);
void				insertOneLine(void);

/*
**				FUNCTION READ && PRINT AND RETURN A STRUCT
*/

t_read				*readStdin(void);
int 				prompt(unsigned char flags, char *str);
t_cmd				*createElement(char c);
int					printStruct(t_read *readStd);
int					myPut(int c);
t_read				*initStructForRead(void);
void				makeListHist(t_read *readStd);
t_cmd				*firstCmd(t_cmd *cmd, int history);
t_cmd				*gblSaveRead(t_cmd *readStd);
int					printList(int to_select, t_cmd *cmd, t_cmd *stop, t_read *readStd);
void				restoreCursor(t_cursor cur);
int					checkCmd(t_read **readStd);

/*
**				HASH FUNCTION
*/

unsigned int		hashValue(char *str);
t_hash				*hashBoard(void);
char				*searchPath(char *binary);
void				addHash(char *bin, char *path);

/*
**				FUNCTION FOR COMPLETION
*/

int					reprintCmd(t_read **readStd, int t);
int					printTab(t_read **readStd);
int					myToGo(int li, int co);
int					myToBackTo(int li, int co);
void				backCompletion(t_read **readStd);
void				addLittleChar(unsigned char type);
void				toUp(t_read **readStd);
int					toDown(t_read **readStd);
void				initCompletion(t_read **readStd);
void				completePath(t_read **readStd, t_path f);
void				completeBinary(t_read **readStd);
void				continue_completion(t_read **readStd);
void				complete_command(t_read **readStd);
int					printTab(t_read **readStd);
int					printElement(t_file *file, int color);
void				createComp(t_read **readStd, t_path f);
void				colorCompletion(unsigned char type, int color);
void				initFiles(t_file **file, char *name, unsigned char type, int index);
void				completion(t_read **readStd);
void				updateIndex(t_read **readStd, int i);

/*
**				POINTER ON FUNCTION FOR READ
*/

int					keyPrint(t_read **readStd, char c);
int					keyTab(t_read **readStd);
void				finishReadStd(t_read **readStd);
int					keyEnter(t_read **readStd);
int					keyInterrupt(t_read **readStd);
int					keyClear(t_read **readStd);
int					keyEof(t_read **readStd);
int					keyArrowLeft(t_read **readStd);
int					keyArrowRight(t_read **readStd);
int					keyArrowUp(t_read **readStd);
int					keyArrowDown(t_read **readStd);
int					keyHome(t_read **readStd);
int					keyDel(t_read **readStd);
int					keyShiftUp(t_read **read);
int					keyShiftDown(t_read **read);
int					keyShiftLeft(t_read **read);
int					keyShiftRight(t_read **read);
int					keyEnd(t_read **readStd);
int					keyDeleteHere(t_read **readStd);

/*
**				ENVIRONEMENT FUNCTION
*/

t_env				*gblSaveEnv(unsigned short flags, t_env *env);
void				initEnv(void);
void				splitEnv(char *env);
void				addListEnv(char *name, char *value);
char				*myGetenv(char *str);

/*
**				HISTORY FUNCTION
*/

void				initHistory(void);
void				copyCmd(t_read **readStd, t_cmd *cpy);
t_hist				*gblSaveHistory(t_hist *hist);
void				makeListHist(t_read *readStd);
void				previousHistory(t_read **readStd);
void				nextHistory(t_read **readStd);

/*
**				SIGNAL FUNCTION
*/

void				initSignal(void);
void				resetSignal(void);

/*
**				TERMIOS FUNCTION
*/

struct termios		keepTermStruct(unsigned short flags, struct termios *term);
void				setTermios(unsigned short flags);
int					initFd(void);
int					initTerm(void);

/*
**				FUNCTION MEMDEL STRUCTURE
*/

int					memdelCompletion(t_completion **comp);
int					memdelRead(t_read **readStd);
int					memdelCmd(t_cmd **cmd);

/*
**				ERROR FUNCTION
*/

int					bip(void);

#endif
