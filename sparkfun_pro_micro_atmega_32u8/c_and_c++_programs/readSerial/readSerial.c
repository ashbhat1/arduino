#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */

/* baudrate settings are defined in <asm/termbits.h>, which is
included by <termios.h> */
#define BAUDRATE B9600            
/* change this definition for the correct port */
#define MODEMDEVICE "/dev/ttyACM0" //location of the device
#define _POSIX_SOURCE 1 /* POSIX compliant source */

#define FALSE 0
#define TRUE 1

int open_port(void)
{
  int fd; /* File descriptor for the port */


  fd = open(MODEMDEVICE, O_RDONLY | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */

    perror("open_port: Unable to open /dev/ttyACM0 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);

  return (fd);
}

void getBaudRate(int fd)
{
  printf("In Baud Rate function!\n");
}

int main()
{
  int fd,retval,res;
  struct termios oldtio,newtio;
  char buf[255];
  fd=open_port();
  if((retval=tcgetattr(fd,&oldtio))<0)
  {
    printf("Error! %d\n",retval);
  }
  tcgetattr(fd,&oldtio); /* save current serial port settings */
  bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */
  /* 
  BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
  CRTSCTS : output hardware flow control (only used if the cable has
            all necessary lines. See sect. 7 of Serial-HOWTO)
  CS8     : 8n1 (8bit,no parity,1 stopbit)
  CLOCAL  : local connection, no modem contol
  CREAD   : enable receiving characters
  */
  newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
           
  /*
  IGNPAR  : ignore bytes with parity errors
  ICRNL   : map CR to NL (otherwise a CR input on the other computer
            will not terminate input)
            otherwise make device raw (no other input processing)
  */
  newtio.c_iflag = IGNPAR | ICRNL;
         
  /*
  Raw output.
  Output nothing so we don't want this flag to return anything
  */
  newtio.c_oflag = 0;
         
  /*
  ICANON  : enable canonical input
            disable all echo functionality, and don't send signals to calling program
  */
  newtio.c_lflag = ICANON;
  
  tcflush(fd,TCIFLUSH); //flush out everything that is in buffer
  tcsetattr(fd,TCSANOW,&newtio); //place the settings of everything defined in newtio into tcs, updates baudrate to 9600

  /*
  terminal settings done, now handle input
  In this example the while loops runs indefinitely until I hit ctrl+C
  */
  while (1) {     /* loop until we have a terminating condition */
  /* read blocks program execution until a line terminating character is 
     input, even if more than 255 chars are input. If the number
     of characters read is smaller than the number of chars available,
     subsequent reads will return the remaining chars. res will be set
     to the actual number of characters actually read */
    res = read(fd,buf,255); 
    buf[res]='\0';             /* set end of string, so we can printf */
    printf(":%s:%d\n", buf, res);
    char key = '\n';
    if(strchr(buf,(int)key)!=NULL){
      printf("Found the character!\n");
    }
    else{
      printf("Couldn't find the character %c\n",key);
    }
  }

  /* restore the old port settings */
  tcsetattr(fd,TCSANOW,&oldtio);
  close(fd);
}
