/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_basic.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:59:42 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:59:42 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_BASIC_H
# define WOLF3D_BASIC_H

# include "wolf3d_basic_list.h"

char		*ft_strnew(int size);
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *src1, char *src2);
void		ft_stradd(char **src1, char *src2);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
char		*ft_strcut(char **src, char delim);
int			ft_strchr(char *src, char d);
char		**ft_strsplit(char const *s, char c);
int			ft_tablen(char **tab);
void		ft_freetab(char ***tab);
void		error_exit(int error, char *message);
void		ft_bzero(void *src, size_t nb_bytes);
void		endl();
float		ft_atof(char *s);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
int			ft_floor(float source);
float		ft_abs_float(float src);
char		*ft_ftoa(float num);
int			min(int a, int b);
int			max(int a, int b);
float		float_min(float a, float b);
float		float_max(float a, float b);
int			get_next_line(const int fd, char **line);
char		*ft_strcpy(char *dest, const char *str);
char		*ft_strcat(char *dest, const char *src);
int			ft_get_end_line(char *str);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoinf(char *s1, char *s2, int c);
void		ft_lstadd(t_list_fd **alst, t_list_fd *new);
void		ft_lstdel(t_list_fd **alst, void (*del)(void *, size_t));
void		ft_del_cont(void *content, size_t size);
void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_lstdelone(t_list_fd **alst, void (*del)(void*, size_t));
float		round_float(float x, unsigned int round);
t_vec4		round_t_vec4(t_vec4 a, unsigned int round);
void		ft_strdel(char **as);
float		generate_float(float rmin, float rmax);
int			is_number(char *s);
void		check_map(char *path);

#endif
