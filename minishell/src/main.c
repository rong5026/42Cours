/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:52:36 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/05 23:16:25 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

void sig_handler(int signal)
{
    if (signal == SIGINT)
    {
        //printf("\033[K"); 지워버리는 것을 원하지는 않았음.
        printf("nanoshell$ \n");
    }

    if (rl_on_new_line() == -1) // readline으로 설정한 문자열을 한 번 출력한다?
        exit(1);
    rl_replace_line("", 1); // 프롬프트에 이미 친 문자열을 싹 날려준다.
    rl_redisplay();         // 프롬프트 커서가 움직이지 않게 해준다.
}

void setting_signal()
{
    signal(SIGINT, sig_handler); // CTRL + C
    signal(SIGQUIT, SIG_IGN);    // CTRL + /
                                 // signal(SIGTERM, sig_handler);
}

int main(int argc, char **argv, char **envp)
{
    char *str;
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    setting_signal();

    (void)argc;
    (void)argv;
    (void)envp;
    
    while (1)
    {
        str = readline("nanoshell$ ");
        if (!str)
        {
            printf("\033[1A");
            printf("\033[10C");
            printf(" exit\n");
            exit(-1);
        }
        else if (*str == '\0')
        {
            free(str);
        }
        else
        {
            add_history(str);
            printf("%s\n", str);
            free(str);
        }
    }
    /* 함수종료 */
    return (0);
}