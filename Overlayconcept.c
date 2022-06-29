//Step 1 : hello 
#include<stdio.h> 
void main()
{
printf("Hello World\n”);
return;
}
//Step 2 : loop 
#include<stdio.h> 
void main()
{
int value = 1;
while (value <= 10)
{
printf("%d\t", value);
Value++;
}
printf("\n");
Return;
}
//Step 3 : Overlay 1
#include <stdio.h> 
#include<unistd.h>
void main()
{
execl("./hello", "./hello", (char *)0);
printf("This wouldn't print\n");
return;
}
//Step 4 : Overlay 2
#include <stdio.h> 
#include<unistd.h>
void main()
{
int pid;
pid = fork();
/* Child process */ if (pid == 0)
{
printf("Child process: Running Hello World Program\n");
execl("./hello", "./hello", (char *)0);
printf("This wouldn't print\n");
}
else
{ /* Parent process */
sleep(3);
printf("Parent process: Running While loop Program\n");
execl("./loop", "./loop", (char *)0);
printf("Won't reach here\n");
}
return;
}
//Step 5 Overlay 2
#include <stdio.h> 
#include<string.h> 
#include<unistd.h>
void main(int argc, char *argv[0])
{
int pid;
int err;
int num_times;
char num_times_str[5];
/* In no command line arguments are passed, then loop maximum count taken as
10 */ if (argc == 1)
{
printf("Taken loop maximum as 10\n");
num_times = 10;
sprintf(num_times_str, "%d", num_times);
}
else
{
strcpy(num_times_str, argv[1]);
printf("num_times_str is %s\n", num_times_str);
}
pid = fork();
/* Child process */ if (pid == 0)
{
printf("Child process: Running Hello World Program\n");
err = execl("./hello", "./hello", (char *)0);
printf("Error %d\n", err);
perror("Execl error: ");
printf("This wouldn't print\n");
}
else
{ /* Parent process */
sleep(3);
printf("Parent process: Running While loop Program\n");
execl("./loop", "./loop", (char *)num_times_str, (char *)0);
printf("Won't reach here\n");
}
return;
}
