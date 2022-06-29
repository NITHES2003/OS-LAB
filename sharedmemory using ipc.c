//READING
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;
int main()
{
// ftok to generate unique key
key_t key = ftok("shmfile", 65);
// shmget returns an identifier in shmid
int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
// shmat to attach to shared memory
char *str = (char *)shmat(shmid, (void *)0, 0);
printf("Data read from memory: %s\n", str);
// detach from shared memory
shmdt(str);
// destroy the shared memory
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
//WRITING
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;
int main()
{
key_t my_key = ftok("shmfile", 65); // ftok function is used
to generate unique key
int shmid = shmget(my_key, 1024, 0666 | IPC_CREAT); // shmget returns
an ide in shmid
char *str = (char *)shmat(shmid, (void *)0, 0); // shmat to join to
shared memory
cout << "Write Data : ";
fgets(str, 50, stdin);
printf("Data written in memory: %s\n", str);
// detach from shared memory
shmdt(str);
return 0;
}