#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    printf("Type 'help' for documentation\n");
    char cwd[1024];
    int history_index = 0;
    int flag = 1;
    char history[100][100];
    
    while (1)
    {
        char input[20][50];
        int index = 0;
        getcwd(cwd, sizeof(cwd));

        char str[100];
        printf("Dolly@SHELL : %s $ ", cwd);
        scanf("%[^\n]%*c", str);
        while (str[index] == ' ')
            index++;

        int j = 0;

        int i = index;
        int ctr = 0;

        while (i <= (strlen(str)))
        {
            if (str[i] != ' ' && str[i] != '\0')
            {
                input[ctr][j] = str[i];
                j++;
            }
            else
            {
                input[ctr][j] = '\0';
                ctr++;
                j = 0;
            }
            i++;
        }

        for (int i = 0; i <= strlen(str); i++)
        {
            history[history_index][i] = str[i];
        }
        char *b = getcwd(cwd, sizeof(cwd));
        history_index++;
        b = getcwd(cwd, sizeof(cwd));

        if (strcmp(input[0], "cd") == 0)
        {
            getcwd(cwd, sizeof(cwd));
            int a = chdir(input[1]);
            if (a < 0)
            {
                printf("No such directory.");
            }
        }
        else if (strcmp(input[0], "history") == 0)
        {
            if (strcmp(input[1], "-c") != 0)
            {
                char *b = getcwd(cwd, sizeof(cwd));
                for (int j = 0; j < history_index - 1; j++)
                {
                    printf("%s\n", history[j]);
                }
                b = getcwd(cwd, sizeof(cwd));
            }
            else
            {
                history_index = 0;
            }
        }
        else if (strcmp(input[0], "exit") == 0)
        {
            printf("Thank you....\n");
            break;
        }
        else if (strcmp(input[0], "help") == 0)
        {
            printf("Internel Commands :\n");
            printf("1. cd = To change the current directory\n");
            printf("2. history = Show command history\n\t-c:Clear history\n");
            printf("3. echo = Print arguments\n\t-n:Do not output the trailing newline\n");
            printf("4. pwd = Print Working Directory\n");
            printf("5. exit = Exit the Shell\n");
            printf("Externel Commands :\n");
            printf("1. ls = list directory contents\n\t-a:Show hidden files\n");
            printf("2. cat = open file\n\t-b:show line number\n");
            printf("3. date = show date\n\t-u:date in UTC\n");
            printf("4. rm = remove file\n\t-v:verbose\n");
            printf("5. mkdir = make directories\n\t-v:verbose\n\t-m:make directory with permission\n");
        }
        else if (strcmp(input[0], "mkdir") == 0)
        {
            pid_t pid = fork();
            if (pid < 0)
            {
                printf("fork() error \n");
            }
            else if (pid != 0)
            {
                wait(0);
            }
            else
            {
                if (strcmp(input[1], "-v") == 0)
                {
                    char *b = getcwd(cwd, sizeof(cwd));
                    char *args[] = {"./mkdir", input[1], input[2]};
                    b = getcwd(cwd, sizeof(cwd));
                    execvp(args[0], args);
                }
                else if (strcmp(input[1], "-m") == 0)
                {
                    char *b = getcwd(cwd, sizeof(cwd));
                    char *args[] = {"./mkdir", input[1], input[2], input[3]};
                    b = getcwd(cwd, sizeof(cwd));
                    execvp(args[0], args);
                }
                else
                {
                    char *args[] = {"./mkdir", input[1]};
                    char *b = getcwd(cwd, sizeof(cwd));
                    execvp(args[0], args);
                }
            }
        }
        else if (strcmp(input[0], "pwd") == 0)
        {
            getcwd(cwd, sizeof(cwd));
            char *b = getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
        }
        else if (strcmp(input[0], "date") == 0)
        {
            if (strcmp(input[1], "-u") == 0)
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./date", input[1], input[1]};
                    execvp(args[0], args);
                }
            }
            else
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./date", input[1]};
                    execvp(args[0], args);
                }
            }
        }
        else if (strcmp(input[0], "ls") == 0)
        {
            pid_t pid = fork();
            if (pid < 0)
            {
                printf("fork() error \n");
            }
            else if (pid != 0)
            {
                wait(0);
            }
            else
            {
                getcwd(cwd, sizeof(cwd));

                if (strcmp(input[1], "-a") != 0)
                {
                    char *args[] = {"./ls", cwd};
                    execvp(args[0], args);
                }
                else
                {
                    char *args[] = {"./ls", cwd, input[1]};
                    execvp(args[0], args);
                }
            }
        }
        else if (strcmp(input[0], "cat") == 0)
        {
            if (strcmp(input[1], "-b") == 0)
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./cat", input[1], input[2]};
                    execvp(args[0], args);
                }
            }
            else
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./cat", input[1]};
                    execvp(args[0], args);
                }
            }
        }
        else if (strcmp(input[0], "echo") == 0)
        {
            if (strcmp(input[1], "-n") != 0)
            {
                for (int i = 1; i < ctr; i++)
                {
                    printf("%s", input[i]);
                    if (i != ctr - 1)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("\n");
                    }
                }
                for (int i = 2; i < ctr; i++)
                {
                    printf("%s", input[i]);
                    if (i != ctr - 1)
                    {
                        printf(" ");
                    }
                }
            }
            else
            {
            }
        }
        else if (strcmp(input[0], "rm") == 0)
        {
            if (strcmp(input[1], "-v") == 0)
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./rm", input[1], input[2]};
                    execvp(args[0], args);
                }
            }
            else
            {
                pid_t pid = fork();
                if (pid < 0)
                {
                    printf("fork() error \n");
                }
                else if (pid != 0)
                {
                    wait(0);
                }
                else
                {
                    char *args[] = {"./rm", input[1]};
                    execvp(args[0], args);
                }
            }
        }
        else
        {
            printf("Command not found. \n");
        }
    }
    return 0;
}