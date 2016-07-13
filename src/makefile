# --------------------------------------------------------------------
# Š¿’¼‘‹ 1.27   Makefile for Borland C++ Compiler 5.5.1
# --------------------------------------------------------------------

# --------------------------------------------------------------------

TARGET	= kanchoku.exe

# --------------------------------------------------------------------

CC	= bcc32
###RC	= brc32 -i"c:\Borland\Bcc55\include"
RC	= brc32 -i"d:\usr\Bcc55\include"
LINKER	= ilink32 -v- -x -Gn -c -Tpe
DLLLINKER	= ilink32 -v- -x -Gn -c -Tpd
GUIFLAGS= -aa
RCFLAGS	= -r -dWIN32
LIBS	= import32.lib cw32.lib
CFLAGS	= -c -DSTRICT -O2 -P

# --------------------------------------------------------------------

# Š¿’¼‘‹
##<v127a - gg>
##SRCS	= main.c table_window.c block.c parser.c mg_table.c control_window.c \
##	  tcode.c st_table.c moji.c bushu_dic.c debug.c
SRCS	= main.c table_window.c block.c parser.c mg_table.c control_window.c \
	  tcode.c st_table.c moji.c bushu_dic.c debug.c gg_dic.c
##</v127a - gg>
RES	= kanchoku.ico kanmini0.ico kanmini1.ico
OBJS	= $(SRCS:.c=.obj)

# --------------------------------------------------------------------

all: $(TARGET)

# --------------------------------------------------------------------

# Š¿’¼‘‹
$(TARGET): $(OBJS) kanchoku.res
	$(LINKER) $(GUIFLAGS) @&&!
c0w32.obj $(OBJS)
$(TARGET)
kanchoku.map
$(LIBS)
	# default .def file
kanchoku.res
!

# --------------------------------------------------------------------

# Š¿’¼‘‹
kanchoku.res: kanchoku.rc $(RES)
	$(RC) $(RCFLAGS) kanchoku.rc

# --------------------------------------------------------------------

%.obj: %.c
	$(CC) $(CFLAGS) $*.c

##<v127a - gg>
gg_dic.obj: gg_dic.c gg_dic.h moji.h debug.h
##</v127a - gg>
block.obj: block.c block.h tc.h debug.h
bushu_dic.obj: bushu_dic.c bushu_dic.h moji.h debug.h
control_window.obj: control_window.c control_window.h table_window.h
main.obj: main.c control_window.h table_window.h
mg_table.obj: mg_table.c mg_table.h debug.h
moji.obj: moji.c moji.h debug.h
parser.obj: parser.c parser.h block.h moji.h tc.h debug.h
st_table.obj: st_table.c st_table.h block.h moji.h tc.h debug.h
##<v127a - gg>
##table_window.obj: table_window.c table_window.h block.h bushu_dic.h mg_table.h moji.h parser.h tcode.h version.h debug.h
##tcode.obj: tcode.c tcode.h tc.h block.h bushu_dic.h mg_table.h moji.h st_table.h table_window.h debug.h
table_window.obj: table_window.c table_window.h block.h bushu_dic.h mg_table.h moji.h parser.h tcode.h version.h debug.h gg_dic.h st_table.h
tcode.obj: tcode.c tcode.h tc.h block.h bushu_dic.h mg_table.h moji.h st_table.h table_window.h debug.h gg_dic.h
##</v127a - gg>
debug.obj: debug.c debug.h

# --------------------------------------------------------------------

install: all
	- del ..\kbdviewer.exe
	copy $(TARGET) ..\kbdviewer.exe

clean:
	- del *.obj
	- del *.exe
	- del *.dll
	- del *.res
	- del *.tds

# --------------------------------------------------------------------
