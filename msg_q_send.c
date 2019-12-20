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
        message.mesg_type=1;
        
        printf("Write Date...\n");
        fgets(message.mesg_text,100,stdin);
        
        //msgsend to send message
        msgsnd(msgid,&message,sizeof(message),0);
        
        //display the message
        printf("Data send is %s \n",message.mesg_text);
        return 0;
        
}
