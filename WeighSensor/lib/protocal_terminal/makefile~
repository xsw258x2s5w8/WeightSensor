OBJS 		= CRC.o Base64.o encrypt.o uart.o packet4uart.o queue.o QT_cmd.o
INCLUDES 	= -I .
CC 			= gcc
CFLAGS 		= -g -Wall -c 
LIBS 		= -L ./lib -L./org.eclipse.mosquitto/lib 
LIB			= libprotocal1.so
SUBDIR 		= .
#arm-linux-gcc test.c -I./org.eclipse.mosquitto/lib/ -L./org.eclipse.mosquitto/lib -lmosquitto -lpthread -lrt


$(LIB):$(OBJS)
	$(CC) -fPIC -shared -o $@ $(OBJS) $(LIBS) -lpthread  -lrt #-lsqlite3
#	$(CC) -o monitor  monitor.c
QT_cmd.o : QT_cmd.c
	$(CC) $(CFLAGS) QT_cmd.c
queue.o : queue.c 
	$(CC) $(CFLAGS) queue.c
CRC.o : CRC.c
	$(CC) $(CFLAGS) CRC.c
Base64.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(SUBDIR) Base64.c
uart.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(SUBDIR) uart.c
encrypt.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(SUBDIR) encrypt.c
packet4uart.o:
	$(CC) $(CFLAGS) $(INCLUDE) $(SUBDIR) packet4uart.c
 
clean :
	rm $(OBJS)  smartlib monitor -rf
update:
	scp ./smartlib root@10.82.80.234:/var/www/smartlibrary-update/
