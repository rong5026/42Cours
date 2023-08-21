/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:52:36 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/08/21 18:41:01 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void sig_handler(int signal)
{
    printf("signal : %d\n", signal);
    if (signal == SIGINT)
    {
        printf("\nnnoshell$");
    }
    else if (signal == SIGTERM)
    {
        printf(" exit\n");
        exit(-1);    
    }
   
}

void setting_signal()
{
    signal(SIGINT, sig_handler);  // CTRL + C
    signal(SIGTERM, sig_handler); // CTRL + D
    signal(SIGQUIT, sig_handler); // CTRL + /
}

int main(void)
{
    char *str;
    // 환경변수
    setting_signal();
    while (1)
    {
        str = readline("nanoshell$ ");
        add_history(str);
        printf("str : %s\n", str);
        free(str);
    }
    /* 함수종료 */
    return (0);
}