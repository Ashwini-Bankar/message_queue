#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//structure for message queue
struct mwsg_buffer
{
        long mesg_type;
        char mesg_text[100];
}message;

int main(void)
{
        key_t key;
        int msgid;
        
        //ftok to generate unique key
        key=ftok("progfile",65);
        
        //msgget create a mesg queue and return identifier
        msgid=msgget(key,0666 | IPC_CREAT);
        
        //msgrcv to receive message
        msgrcv(msgid,&message,sizeof(message),1,0);
        
        //display the message
        printf("Data Received is : %s \n",message.mesg_text);
        
        //to destroy the messsage queue
        msgctl(msgid,IPC_RMID, NULL);
        return 0;
}
