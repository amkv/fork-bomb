/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:37:16 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/17 16:37:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

static void		skip(void) { return; }
static void		terminate(void) { exit(0x0); }

static char		*randstring(void)
{
	static char	charset[] = "bcdfghijplmopqdstuvsxazABCDEFGGIJKLMPRSTUVWXYZ";
	char		*randomString;
	int 		n;
	int 		key;
	int			len;

	randomString = NULL;
	n = 0;
	srand(time(NULL));
	len = 1 + rand() % (19 - 1);
	if (len)
	{
		randomString = (char*)malloc(sizeof(char) * (len +1));
		if (randomString)
		{
			while (n < len)
			{
				key = rand() % (int)(sizeof(charset) - 1);
				randomString[n] = charset[key];
				n++;
			}
			randomString[len] = '\0';
		}
	}
	return (randomString);
}

/* ****************************************************************************

int _podargos(int arg0) {
    var_8 = arg0;
    signal(0x4, _tame_podargos);
    var_C = fork();
    rcx = *var_8;
    __strcpy_chk(*rcx, "podargos", 0xffffffffffffffff, rcx);
    goto loc_100000a5c;

loc_100000a5c:
    if ((var_C == 0x0) || (var_C == 0x1)) {
            fork();
    }
    __strcpy_chk(**var_8, "ruins", 0xffffffffffffffff);
    var_C = var_C + 0x1;
    sleep(0x5);
    goto loc_100000a5c;
}
*/

static void		white_horse(char **name)
{
	int 		f;

	signal(0x4, (void*)&terminate);
	strcpy(*&name[0], randstring());
	f = fork();
	while(1)
	{
		if ((f == 0x0 || f == 0x1))
			fork();
		strcpy(*&name[0], randstring());
		f = f + 1;
		sleep(0x1);
	}
}

/* ****************************************************************************

int _lampon(int arg0) {
    rax = signal(0x5, _tame_lampon);
    rcx = *arg0;
    __strcpy_chk(*rcx, "lampon", 0xffffffffffffffff, rcx);
    goto loc_100000b24;

loc_100000b24:
    sleep(0x3);
    var_18 = malloc(0x150);
    while (0xffffffff < 0x2a) {
            *(var_18 + sign_extend_64(0xffffffff) * 0x8) = malloc(0x280de80);
    }
    var_C = 0xffffffff;
    do {
            rax = var_C + 0x1;
            var_C = rax;
            if (rax >= 0x2a) {
                break;
            }
            printf("%p", *(var_18 + sign_extend_64(var_C) * 0x8));
    } while (true);
    goto loc_100000b24;
}
*/

static void		red_horse(char **name)
{
	char 		*mem;

	signal(0x5, (void*)&terminate);
	strcpy(*&name[0], randstring());
	while(1)
	{
		mem = malloc(0x1000);
		memset(mem, rand(), sizeof(char) * 0x150);
	}
}

/* ****************************************************************************

int _xanthos(int arg0) {
    var_8 = arg0;
    rax = signal(0xa, _tame_xanthos);
    rcx = *var_8;
    var_C = 0x0;
    __strcpy_chk(*rcx, "xanthos", 0xffffffffffffffff, rcx);
    goto loc_100000c1b;

loc_100000c1b:
    sleep(0x3);
    if (var_C == 0x0) {
            var_C = fork();
    }
    __strcpy_chk(**var_8, "-bash", 0xffffffffffffffff);
    system("yes");
    goto loc_100000c1b;
}
*/

static void		black_horse(char **name)
{
	int 		f;

	signal(0xa, (void*)&terminate);
	strcpy(*&name[0], randstring());
	f = 0x0;
	while(1)
	{
		sleep(0x3);
		if (f == 0x0)
			f = fork();
		strcpy(*&name[0], randstring());
		system(randstring());
	}
}

/* ****************************************************************************

int _deinos(int arg0) {
    var_8 = arg0;
    __strcpy_chk(**var_8, "deinos", 0xffffffffffffffff);
    goto loc_100000cc0;

loc_100000cc0:
    fork();
    signal(0xb, _tame_deinos);
    rax = rand();
    temp_3 = rax % 0x1a4;
    rax = __sprintf_chk(var_70, 0x0, 0x64, "crap%d.poo", temp_3, 0x64);
    rcx = *var_8;
    __strcpy_chk(*rcx, var_70, 0xffffffffffffffff, rcx);
    var_C = open(var_70, 0x209);
    write(var_C, "plop", 0x4);
    close(var_C);
    sleep(0x3);
    goto loc_100000cc0;
}
*/

static void		pale_horse(char **name)
{
	char 		str[30];
	int 		fd;

	strcpy(*&name[0], randstring());
	while(1)
	{
		fork();
		signal(0xb, (void*)&terminate);
		sprintf(str, "%s", randstring());
		strcpy(*&name[0], str);
		fd = open(str, O_CREAT | O_RDWR);
		write(fd, randstring(), 0x5);
		close(fd);
		sleep(0x3);
	}
}

/* ************************************************************************* */

int				main(int argc, char **argv)
{
	signal(SIGHUP, (void*) &skip);
	signal(SIGINT, (void*) &skip);
	signal(SIGKILL, (void*) &skip);
	signal(SIGPIPE, (void*) &skip);
	signal(SIGALRM, (void*) &skip);
	signal(SIGTERM, (void*) &skip);
	signal(SIGUSR1, (void*) &skip);
	signal(SIGUSR2, (void*) &skip);
	signal(SIGVTALRM, (void*) &skip);
	signal(SIGPROF, (void*) &skip);
	if (fork() == 0x0)
	{
		if (fork() == 0x0)
			white_horse(argv);
		else
			red_horse(argv);
	}
	else
	{
		if (fork() == 0x0)
			black_horse(argv);
		else
			pale_horse(argv);
	}
	return (0);
}
