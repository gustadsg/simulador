# Nome do seu programa
PROGNAME = server

# Diretórios de origem e de destino
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Compilador e opções de compilação
CC = gcc
CFLAGS = -Wall -I$(INCDIR)

# Arquivos de origem e de objeto
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Alvo padrão
all: $(BINDIR)/$(PROGNAME)

# Regra de construção do executável
$(BINDIR)/$(PROGNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra de construção de objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpar arquivos temporários
clean:
	rm -f $(OBJS) $(BINDIR)/$(PROGNAME)